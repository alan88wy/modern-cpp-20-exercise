#include <iostream>
#include <list>
#include <algorithm>

void print_list(std::list<int> l, std::string message)
{
    std::cout << message << " : ";

    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";
}
// predicate function
bool is_even(const int& x) { return (x % 2) == 0; }

// predicate class
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

struct is_three {
  bool operator() (const int& value) { return value == 3; }
};

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

    for (int it: l)
    {
        std::cout << it << " ";
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

    print_list(l, "List after inserting 99 at begin + 4 and at the end with 30");

    l.push_front(33);

    print_list(l, "Push 33 to the front");

    // Removing element
    l.pop_front();

    print_list(l, "pop_front (removing first item)");

    l.pop_back();

    print_list(l, "pop_back (removing last item)");

    std::list<int>::iterator itd = l.begin();

    std::advance(itd, 3);

    l.erase(itd);

    print_list(l, "Remove item at begin +3 using l.erase(itd)");

    l.remove(3);

    print_list(l, "Remove all the no 3 from the list l.remove(3)");

    l.clear();

    print_list(l, "l.clear()");

    // Merging list
    std::list<int> l1 {1,3,5};
    std::list<int> l2 {2,4,6};

    l1.merge(l2);

    print_list(l1, "Merging two lists {1,3,5} {2,4,6}");

    /* Spliting list
     *
     * Using slice - moving a slice of list into another list
     * 
     * l1.slice(l2, l1) - move everything from l1 to l2. l1 will be empty
     * 
    */ 

    std::cout << "Moving a slice from l1 into l3\n"; 
    print_list(l1, "l1 before move");

    std::list<int> l3;
    auto pos = l1.begin();
    std::advance(pos, 3);
    l3.splice(l3.begin(), l1, pos, l1.end());

    print_list(l1, "l1 After move");
    print_list(l3, "l3");

    // Reverse l1
    l1.reverse();

    print_list(l1, "Reversing l1"); 

    // sorting
    std::list<int> l4 {1, 3, 3,5,9,2,3,10,4,6,1,9,7,5,8,9,11};
    l4.sort();

    print_list(l4, "Sorting {1,3,3,5,9,2,3,10,4,6,1,9,7,5,8,9,11}"); 

    l4.unique();

    print_list(l4, "Getting unique no {1,3,3,5,9,2,3,10,4,6,1,9,7,5,8,9,11}");
    // resize list
    std::list<int> l5 {1, 3, 3};
    l5.resize(6, 9);

    print_list(l5, "Resize {1,2,3} to 6 elements and fill with 9"); 

    // Swapping list
    std::list<int> l6 {1, 3, 3};
    std::list<int> l7 {4,2,6};
    
    l6.swap(l7);

    std::cout << "Swapping elements of l6 {1, 3, 3} with l7 {4,2,6} : \n"; 
    print_list(l6, "l6");
    print_list(l7, "l7");

    /*
     * listname.remove_if(predicate)
     *
     * Parameters :
     * The predicate in the form of aa function pointer or function object is passed as the parameter.
     * 
     * Result :
     * Removes all the elements of the container which return true for the predicate.
    */

    std::list<int> l8 {1,3,3,5,9,2,3,4,6};

    l8.remove_if(is_even);  // Using predicate function

    print_list(l8, "Remove even number from {1,3,3,5,9,2,3,4,6}");

    std::list<int> l9 {1,3,3,5,9,2,3,4,6};

    l9.remove_if(is_odd());  // Using predicate class

    print_list(l9, "Remove odd number from {1,3,3,5,9,2,3,4,6}");

    std::list<int> l10 {1,3,3,5,9,2,3,4,6};

    l10.remove_if(is_three());  // Using predicate class

    print_list(l10, "Remove number 3 from {1,3,3,5,9,2,3,4,6}");

    // find and remove first item found
    std::list<int> l11 {1,3,3,5,9,2,3,4,6};

    auto it {std::find(l11.begin(), l11.end(), 3) };

    l11.erase(it);

    print_list(l11, "Remove first number 3 at found location from list");

    return 0;
}