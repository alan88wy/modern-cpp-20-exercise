#include <iostream>

int main()
{

    auto lambda = []() { std::cout << "Hello Lambda\n";};
    auto lambdax = [](int x) { std::cout << "Hello Lambda: " << x << "\n";};
    auto lambday = [](int& x) { std::cout << "Hello Lambda: ++y -> " << ++x << "\n";};
    auto lambdaxy = [](int& x, int&y) { 
        x += 10;
        y += 5;
        std::cout << "Hello Lambda: x + 10 -> " << x << " y + 5 -> " << y << "\n";
    };

    lambda();
    lambdax(10);

    int y = 10;

    std::cout << "y-> " << y << "\n";

    lambday(y);

    std::cout << "After Lambda y-> " << y << "\n";

    int x = 10;

    std::cout << "x -> " << x << " y-> " << y << "\n";

    lambdaxy(x, y);

    std::cout << "x -> " << x << " y-> " << y << "\n";

    

    

    return 0;
}