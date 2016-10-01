#ifndef MIILANG_COMPILER_H_
#define MIILANG_COMPILER_H_

#include <string>
#include "lexer.h"

namespace Miilang
{
    using Bytecode = std::string;
    // A simple way to compile some code.
    class Compiler
    {
    public:
        Bytecode compile(const std::string &code);
    private:
        Lexer mLexer;
    };
}

#endif
