#include <iostream>
#include "compiler.h"

int main()
{
    Miilang::Lexer l("testing kyword \n identif morethan100bytes 12450 3.14 \"stringTes\\nting\"");
    std::list<Miilang::Lexer::Token>tokens = l.lexAll();
    for(const auto &t : tokens)
    {
        std::cout << static_cast<int>(t.type) << " " << t.value << std::endl;
    }
    
    return 0;
}
