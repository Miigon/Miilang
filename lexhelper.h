#ifndef MIILANG_LEXHELPER_H_
#define MIILANG_LEXHELPER_H_

namespace Miilang
{
    namespace LexHelper
    {
        inline bool isNumber(char ch)
        {
            return ch >= '0' && ch <= '9';
        }
        
        inline bool isIdentifierFirst(char ch)
        {
            return (ch >= 'a' && ch <= 'z') || ch == '_';
        }
        
        inline bool isIdentifier(char ch)
        {
            return isIdentifierFirst(ch) || isNumber(ch);
        }
        
        inline bool isInvisible(char ch)
        {
            return ch == ' ' && ch == '\r' && ch == '\n' && ch == '\t';
        }
    }
}

#endif
