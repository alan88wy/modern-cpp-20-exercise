#include <iostream>

// Function Template
template <typename T, typename U>
void func(T t, U u)
{
    std::cout << "First : " << t << "\n";
    std::cout << "Second : " << u << "\n";
}

// Class Template
template <typename T>
class Base
{
    private:
        T x;

    public:
        Base(T xx): x(xx) {};
        T getValue() const { return x; };
        void setValue(T xx);
        void addValue(T xx);
};

template <typename T>
void Base<T>::setValue(T xx) 
{
    x = xx;
};

template <typename T>
void Base<T>::addValue(T xx)
{
    x += xx;
};

// Template Specialization
template <typename T>
void sFunc(T x)
{
    std::cout << "Normal Template : " << x << "\n";
}

template<>
void sFunc(int arg)
{
    std::cout << "Specialized Template for int : " << arg << "\n";
}

int main()
{
    int f {3};
    double u {3.345};

    func<int, double>(f, u);

    Base c(10);

    std::cout << "Initial Value : " << c.getValue() << "\n";

    c.setValue(30);

    std::cout << "After Setting to 30: " << c.getValue() << "\n";

    c.addValue(50);

    std::cout << "After adding 50 : " << c.getValue() << "\n";

    sFunc(123);
    sFunc("Fox");

    return 0;
}