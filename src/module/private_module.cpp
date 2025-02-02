export module adder;
// import std;
import <memory>;
import <print>;

export class Adder
{
public:
    Adder();
    virtual
˜Adder();
    int add(int a, int b) const;

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};

module :private;

class Adder::Impl
{
public:
    ˜Impl() { std::println("Destructor of Adder::Impl"); }
    int add(int a, int b) const { return a + b; }
};
Adder::Adder() : m_impl{std::make_unique<Impl>()} {}
Adder::˜Adder() {}
int Adder::add(int a, int b) const { return m_impl -­> add(a, b); }