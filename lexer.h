#ifndef MIILANG_LEXER_H_
#define MIILANG_LEXER_H_

#include <string>
#include <vector>
#include <list>

namespace Miilang
{
    class Lexer
    {
    public:
        struct Token
        {
            enum class Type
            {
                Eof,
                Error,
                Identifier,
                Keyword,
                Number,
                Newline,
                String,
            };
            Type type;
            std::string value;
        };
        Lexer(std::string code);
        std::list<Token> lexAll();
        char nextChar(size_t n = 1);
        char nextCharNoMove(size_t n = 1);
        void move(size_t n);
        Token next();
        bool isEOF()
        {
            return mPos >= mLength;
        };
    private:
        size_t mPos;
        size_t mLength;
        std::string mCode;
    };
}

#endif
