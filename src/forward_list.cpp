#include <iostream>
#include <forward_list>

void print_list(std::forward_list<int>& l, std::string message)
{
    std::cout << message << " : ";

    for (std::forward_list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n";
};

// predicate function
bool is_odd(const int& x) { return (x % 2) == 1; };

int main()
{
    std::forward_list<int> l1;
    std::forward_list<int> l2;
    std::forward_list<int> l3;

    l1.assign({1,2,3});  // assign {1,2,4}  to l1

    print_list(l1, "Assign {1,2,3} to l1");

    l2.assign(5, 2);  // assing a list 5 no 2

    print_list(l2, "assign 5 no of 2");

    l3.assign(l1.begin(), l1.end()); // Assign values of l1 to l2;
    print_list(l3, "Assign elements of l1 to l3");
    
    /*
     * push_front(): This function is used to insert the element at the first position on forward list. The value from this function is copied to the space before first element in the container. The size of forward list increases by 1.
     * emplace_front(): This function is similar to the previous function but in this no copying operation occurs, the element is created directly at the memory before the first element of the forward list.
     * pop_front(): This function is used to delete the first element of the list.  
    */

    l3.push_front(60);
    l3.emplace_front(90);
    l3.pop_front();

    print_list(l3, "l3 push_front(60), emplace_front(90), pop_front()");

    /*
     * insert_after(): This function gives us a choice to insert elements at any position in forward list. 
     *                 The arguments in this function are copied at the desired position.
     * emplace_after(): This function also does the same operation as the above function but the elements are 
     *                  directly made without any copy operation.
     * erase_after(): This function is used to erase elements from a particular position in the forward list. 
     *                There are two variants of ‘erase after’ function.
    */

    std::forward_list<int>::iterator it3 = l3.begin();

    std::advance(it3, 2);
    l3.insert_after(it3, {4,3,5});
    print_list(l3, "Insert {4,3,5} after begin() + 2");

    it3 = l3.emplace_after(it3, 99);
    print_list(l3, "emplace_after {1,2,1} after begin() + 2");

    std::advance(it3, 1);
    it3 = l3.erase_after(it3, l3.end());
    print_list(l3, "emplace_after {1,2,1} after begin() + 2 + 1");

    /*
     * remove(): This function removes the particular element from the forward list mentioned in its argument.
     * remove_if(): This function removes according to the condition in its argument. 
    */

    l3.remove(99);
    print_list(l3, "Remove 99");

    l3.remove_if(is_odd);
    print_list(l3, "Remove Odd No");

    /*
     * Other Method Definition
     *
     * front()	This function is used to reference the first element of the forward list container.
     * begin()	This function is used to return an iterator pointing to the first element of the forward list container.
     * end()	This function is used to return an iterator pointing to the last element of the list container.
     * cbegin()	Returns a constant iterator pointing to the first element of the forward_list.
     * cend()	Returns a constant iterator pointing to the past-the-last element of the forward_list.
     * before_begin()	Returns an iterator that points to the position before the first element of the forward_list.
     * cbefore_begin()	Returns a constant random access iterator which points to the position before the first element of the forward_list.
     * max_size()	Returns the maximum number of elements that can be held by forward_list.
     * resize()	Changes the size of forward_list.
     * unique()	Removes all consecutive duplicate elements from the forward_list. It uses a binary predicate for comparison.
     * reverse() 	Reverses the order of the elements present in the forward_list.
    */

    return 1;
}