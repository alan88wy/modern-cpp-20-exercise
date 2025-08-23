#include <iostream>
#include <string>
class Base
{
    public:
    
        Base(int i, std::string aa);
        Base(const Base& cp);             // Copy Constructor
        Base& operator=(const Base& cp);  // Assignment Operator
        Base(const Base&& mv);            // Move Constructor
        Base& operator=(const Base&& mv); // Move Assignment
        Base& operator++();               // This is for j++
        Base operator++(int);             // This is for ++j
        Base& operator+=(const Base& pl); // += operator
        void print_str(std::string f);
        void print_idx(std::string f);

    private:
        std::string myStr;
        int idx;
};

void Base::print_str(std::string f)
{
    std::cout << f << " : " << myStr << "\n";
}

void Base::print_idx(std::string f)
{
    std::cout << f << " : " << idx << "\n";
}

Base::Base(int i, std::string aa)
{
    myStr = aa;
    idx = i;
    // std::cout << myStr <<"\n";
}

// Copy Constructor
Base::Base(const Base& cp): myStr {cp.myStr}, idx {cp.idx}
{
    std::cout << "Copy Constructor -> " << myStr <<"\n";
}

// Copy Assignment operator
Base& Base::operator=(const Base& cp)
{
    myStr = cp.myStr;
    idx = cp.idx;
    std::cout << "Assignment Constructor -> " << myStr << "\n";
    return *this;
}

// Move Constructor
Base::Base(const Base&& mv): myStr {std::move(mv.myStr)}, idx {std::move(mv.idx)}
{
    std::cout << "Move Constructor -> " << myStr << "\n";
}

// Move Assignment Operator
Base& Base::operator=(const Base&& mv)
{
    myStr = mv.myStr;
    idx = mv.idx;

    std::cout << "Move Assignment Operator -> " << myStr << "\n";

    return *this;
}

Base& Base::operator++()
{
    ++this->idx;
    std::cout << "Prefix operator ++ invoked - " << idx << '\n';
    return *this;
}

Base Base::operator++(int)
{
    Base tmp(*this);
    operator++();
    std::cout << "Postfix operator ++ invoked - " << tmp.idx << '\n';

    return tmp;  // Return Old Value
}

Base& Base::operator+=(const Base& pl)
{
    this->idx += pl.idx;

    std::cout << "+= Operator -> " << myStr << "\n";

    return *this;
}

int main()
{
    std::cout << "-> Base myOrig {0, \"Original \"};\n";
    Base myOrig {0, "Original "};

    myOrig.print_str("myOrig");

    std::cout << "-> Base myFirstOrig {0, \"First Original \"};\n";

    Base myFirstOrig {0, "First Original "};

    myFirstOrig.print_str("myFirstOrg");

    std::cout << "-> Base mySecOrig {0, \"Second Original \"};\n";

    Base mySecOrig {0, "Second Original "};

    mySecOrig.print_str("mYSecOrig");

    // Copy Constructor will be Called
    std::cout << "-> Base thirdOrig = myOrig;\n";
    Base thirdOrig = myOrig;

    thirdOrig.print_str("thirdOrig");

    // Copy Assignment Operator Called
    std::cout << "-> mySecOrig = myOrig;\n";
    mySecOrig = myOrig;
    mySecOrig.print_str("mySecOrig");

    // Move Constructor will be Called
    std::cout << "-> Base moveOrig = std::move(myOrig);\n";
    Base moveOrig = std::move(myOrig);

    moveOrig.print_str("moveOrig");

    // Must not do this as myOrig is no longer in the right State
    // myOrig.print_str("myOrig");

    // Move Assignment
    std::cout << "-> Base cur {0, \"New Base\"};\n";
    Base cur {0, "New Base"};

    cur.print_str("cur");

    std::cout << "-> Base toMove {0, \"\"};\n";
    Base toMove {0, ""};

    // Move Assignment Operator will be Called
    std::cout << "-> toMove = std::move(cur);\n";
    toMove = std::move(cur);
    toMove.print_str("toMove");
    toMove.print_idx("toMove idx");
    // cur no longer in the right state. DO NOT USE

    // ++x operator will be called
    std::cout << "-> ++toMove;\n";
    ++toMove;
    toMove.print_idx("toMove idx++");

    // x++ operator will be called
    std::cout << "-> toMove.operator++(0);\n";
    toMove.operator++(0);
    toMove.print_idx("toMove ++idx");

    // Prefix ++ operator will be called
    std::cout << "-> ++mySecOrig;\n";
    ++mySecOrig;
    mySecOrig.print_idx("mySecOrig ++idx");

    toMove.print_idx("toMove idx before += mySecOrig");
    // += operator will be called
    std::cout << "-> toMove += mySecOrig;\n";
    toMove += mySecOrig;
    mySecOrig.print_idx(("mySecOrig"));
    toMove.print_idx("toMove += ");

    return 0;
}