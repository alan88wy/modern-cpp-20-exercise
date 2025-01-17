#include <string>
#include <print>

using namespace std;

class Animal
{
public:
    explicit Animal(double weight) : m_weight{weight} {}
    virtual double getWeight() const { return m_weight; }

protected:
    Animal() = default;

private:
    double m_weight{0.0};
};

class Dog : public virtual Animal
{
public:
    explicit Dog(double weight, string name) : Animal{weight}, m_name{std::move(name)} {println("Dog's constructor!");}

protected:
    explicit Dog(string name) : m_name{std::move(name)} {println("Dog's protected constructor!");}

private:
    string m_name;
};

class Bird : public virtual Animal
{
public:
    explicit Bird(double weight, bool canFly) : Animal{weight}, m_canFly{canFly} {println("Bird's constructor!");}

protected:
    explicit Bird(bool canFly) : m_canFly{canFly} {println("Bird's protected constructor!");}

private:
    bool m_canFly{false};
};

class DogBird : public Dog, public Bird
{
public:
    explicit DogBird(double weight, string name, bool canFly) : Animal{weight}, Dog{std::move(name)}, Bird{canFly} {}
};

int main()
{
    // Dog d {"James"};  - Will not work as this constructor is protected and can only be call by derived class like DogBird below;
    //                   - Others can only call the public method.

    DogBird dogBird{22.33, "Bella", true};
    println("Weight: {}", dogBird.getWeight());

    return 0;
}