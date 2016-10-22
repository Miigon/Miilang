#include <iostream>
#include <fstream>
#include <sstream>
#include "compiler.h"

int main()
{
    std::ifstream file("sample.ml");
    std::string code((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());
    Miilang::Lexer l(std::move(std::string(code)));
    std::list<Miilang::Lexer::Token> tokens = l.lexAll();
    for(const auto &t : tokens)
    {
        std::cout << static_cast<int>(t.type) << " " << t.value << std::endl;
    }
    
    return 0;
}
