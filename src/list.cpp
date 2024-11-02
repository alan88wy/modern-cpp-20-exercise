#include <iostream>
#include <list>

int main()
{
    std::list<int> l {1, 3, 3,5,9,2,3,10,4,6,1,9,7,5,8,9,11};

    std::cout << "Print List using for (int i:l) : ";

    for (int i : l) {
        std:: cout << i << " ";
    }

    std::cout << "\n";

    std::cout << "Front : " << l.front() << "\n";
    std::cout << "Back : " << l.back() << "\n";

    std::list<int>::iterator beginIter = l.begin();
    std::list<int>::iterator endIter = l.end();

    std::cout << "Iterator v1 : ";
    // iterator
    for (std::list<int>::iterator it = beginIter; it != endIter; ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    // or this
    std::cout << "Iterator v2 : ";

    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    // Reverse Iterator
    std::cout << "Reverse Iterator : ";

    for (std::list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    std::list<int>::iterator itb = l.begin();

    std::advance(itb, 4);

    std::cout << "Begin + 4 : " << *itb << "\n";

    l.insert(itb, 99);

    l.push_back(30);

    std::cout << "List after inserting 99 at begin + 4 and at the end with 30 : \n";

    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    // Removing element
    l.pop_front();

    std::cout << "pop_front (removing first item) : ";

    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    l.pop_back();

    std::cout << "pop_back (removing last item) : ";

    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    std::list<int>::iterator itd = l.begin();

    std::advance(itd, 3);

    l.erase(itd);

    std::cout << "Remove item at begin +3 using l.erase(itd) : ";

    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    l.remove(3);

    std::cout << "Remove all the no 3 from the list l.remove(3) : ";

    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";

    l.clear();

    std::cout << "l.clear() : ";

    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";


    return 1;
}