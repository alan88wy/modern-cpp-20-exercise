/*
 * To Compile
 * 
 * g++ -std=c++20 -c module_tmpl.cpp -fmodules-ts -o module_tmpl.o
 * g++ -std=c++20 -c module.cpp -fmodules-ts -o module.o
 * g++ -std=c++20 module.o module_tmpl.o -o program
 * ./program
*/

#include <ostream>

import my_module;

int main() {

    my_namespace::PublicTemplateClass<int> pubtmpl;
    pubtmpl.print(14);

    my_namespace::PublicTemplateFunction(1.2);
    my_namespace::PublicTemplateFunction("a string");

    return 0;
}