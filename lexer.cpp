#include "lexer.h"
#include "lexhelper.h"
#include <iostream>
#include <unordered_set>
#include <sstream>

namespace Miilang
{
    /*
    std::vector<Token> Lexer::makeTokenList(const std::string &code)
    {
        //NOT IMPLEMENTED
        return {};
    }
    */
    
    static const std::unordered_set<std::string> Keywords
        {
            "kyword",
            "int",
        };
    
    Lexer::Lexer(std::string code)
        :mCode(std::move(code)),mLength(code.length()),mPos(0)
    {
    }
    
    std::list<Lexer::Token> Lexer::lexAll()
    {
        std::list<Lexer::Token> ret;
        Token t;
        do
        {
            t = next();
            ret.push_back(t);
            
        }while (t.type != Token::Type::Eof);
        return ret;
    }
    
    char Lexer::nextChar(size_t n)
    {
        char ch = nextCharNoMove(0);
        move(n);
        return ch;
    }
    
    void Lexer::move(size_t n)
    {
        mPos += n;
    }
    
    char Lexer::nextCharNoMove(size_t n)
    {
        if(isEOF())
        {
            return 0;
        }
        return mCode[mPos + n];
    }
    
    Lexer::Token Lexer::next()
    {
        do
        {
            char ch = nextChar();
            
            //EOF
            if(ch == 0) return {Token::Type::Eof};
            //skip space charactors
            if(ch == ' '||ch == '\t') continue;
            //newline
            if(ch == '\n') return {Token::Type::Newline};
            //identifier or keyword
            if(LexHelper::isIdentifierFirst(ch))
            {
                size_t posStart = mPos - 1;
                do
                {
                    if(!LexHelper::isIdentifier(ch)) break;
                    ch = nextChar();
                }
                while(true);
                size_t idLen = mPos - posStart - 1;
                std::string id = std::move(mCode.substr(posStart,idLen));
                if(Keywords.find(id) != Keywords.end())
                    return {Token::Type::Keyword,std::move(id)};
                else
                    return {Token::Type::Identifier,std::move(id)};
            }
            //string
            if(ch == '"')
            {
                ch = nextChar(); //skip over '"'
                std::stringstream ss;
                size_t posStart = mPos - 1;
                size_t lastEscape = posStart;
                while(ch != '"')
                {
                    if(ch == '\\') //escape characters
                    {
                        ss << mCode.substr(lastEscape,mPos - lastEscape - 1);
                        auto a = ss.str();
                        ch = nextChar();
                        if(ch == 'a') ss << '\a';
                        else if(ch == 'b') ss << '\b';
                        else if(ch == 'f') ss << '\f';
                        else if(ch == 'n') ss << '\n';
                        else if(ch == 'r') ss << '\r';
                        else if(ch == 't') ss << '\t';
                        else if(ch == 'v') ss << '\v';
                        else if(ch == '\\') ss << '\\';
                        else if(ch == '\'') ss << '\'';
                        else if(ch == '"') ss << "\"";
                        else if(ch == '?') ss << "\?";
                        else if(ch == '\0') ss << '\0';
                        // TODO: HEX and OCT support --Miigon 16.10.1
                        a = ss.str();
                        lastEscape = mPos;
                    }
                    ch = nextChar();
                }
                size_t strLen = mPos - posStart - 1;
                if(lastEscape == posStart) // do not have any escape character
                {
                    return {Token::Type::String,mCode.substr(posStart,strLen)};
                }
                else
                {
                    ss << mCode.substr(lastEscape,strLen - (lastEscape - posStart));
                }
                return {Token::Type::String,ss.str()};
            }
            //number
            if(LexHelper::isNumber(ch))
            {
                size_t posStart = mPos - 1;
                do
                {
                    // TODO: Error when more than 1 points --Miigon 16.10.1
                    if(!(LexHelper::isNumber(ch) || ch == '.')) break;
                    ch = nextChar();
                }
                while(true);
                size_t idLen = mPos - posStart - 1;
                return {Token::Type::Number,mCode.substr(posStart,idLen)};
            }
        }while(true);
    }
}
