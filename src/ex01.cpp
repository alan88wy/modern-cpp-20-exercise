#include <iostream>

int main() {

    double width, height, length;

    std::cout << "Welcome to box calculator. Please enter width, length and height : " << std::endl;

    std::cout << "Enter width : ";

    std::cin >> width;

    std::cout << "Enter Length : ";

    std::cin >> length;

    std::cout << "Enter height: ";

    std::cin >> height;

    double base_area {width * length};

    double volume {base_area * height};

    std::cout << "The base area is " << base_area << std::endl;

    std::cout << "The volume is " << volume << std::endl;

    return 0;

}