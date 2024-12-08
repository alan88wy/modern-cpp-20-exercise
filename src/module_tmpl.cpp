module;

#include <iostream>

export module my_module;

namespace my_namespace {

    // export a template class
    export template <typename T>
    struct PublicTemplateClass {
        void print(T param) {
            std::cout << "PublicTemplate::print(" << param << ")" << std::endl;
        }
    };

    // export a template function
    export template <typename T>
    void PublicTemplateFunction(T param) {
        std::cout << "PublicTemplateFunction(" << param << ")" << std::endl;
    }

} // namespace my_namespace