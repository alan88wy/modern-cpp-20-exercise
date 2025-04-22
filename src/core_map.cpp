/*
 * std::map will sort the list automatically based on the key.
 * Only store unique keys
 * 
 * List of all Functions of std::map
 * 
 * The following table contains all the functions defined inside std::map class.
 * 
 * Function
 * 
 * map::insert() 	   - Insert elements with a particular key in the map container –> O(log n)
 * map::count()	       - Returns the number of matches to element with key-value ‘g’ in the map. –> O(log n)
 * map::equal_range()  - Returns an iterator of pairs. The pair refers to the bounds of a range that includes 
 *                       all the elements in the container which have a key equivalent to k.
 * map::erase()	       - Used to erase elements from the container –> O(log n)
 * map::rend()	       - Returns a reverse iterator pointing to the theoretical element right before the first 
 *                      key-value pair in the map(which is considered its reverse end).
 * map::rbegin()       - Returns a reverse iterator which points to the last element of the map.
 * map::find()	       - Returns an iterator to the element with key-value ‘g’ in the map if found, else returns the iterator to end.
 * map::crbegin()      - crbegin() returns a constant reverse iterator referring to the last element in the map container. 
 * and map::crend()      crend() returns a constant reverse iterator pointing to the theoretical element before the first 
 *                       element in the map. Use this if you do not allow or are not to modify the record.
 * map::cbegin() 	   - cbegin() returns a constant iterator referring to the first element in the map container. 
 * map::cend()           returns a constant iterator pointing to the theoretical element that follows the last element in the
 *                       multimap. Use this if you do not allow or are not to modify the record.
 * map::emplace()	   - Inserts the key and its element in the map container.
 * map::max_size() 	   - Returns the maximum number of elements a map container can hold –> O(1)
 * map::upper_bound()  - Returns an iterator to the first element that is equivalent to mapped value with key-value ‘g’ or 
 *                       definitely will go after the element with key-value ‘g’ in the map
 * map::operator=	   - Assigns contents of a container to a different container, replacing its current content.
 * map::lower_bound()  - Returns an iterator to the first element that is equivalent to the mapped value with key-value ‘g’ or 
 *                       definitely will not go before the element with key-value ‘g’ in the map –> O(log n)
 * map::emplace_hint() - Inserts the key and its element in the map container with a given hint.
 * map::value_comp()   - Returns the object that determines how the elements in the map are ordered (‘<‘ by default).
 * map::key_comp() 	   - Returns the object that determines how the elements in the map are ordered (‘<‘ by default).
 * map::size()	       - Returns the number of elements in the map.
 * map::empty()	       - Returns whether the map is empty
 * map::begin() and    - begin() returns an iterator to the first element in the map. end() returns an iterator to the 
 * map::end()            theoretical element that follows the last element in the map
 * map::operator[]	   - This operator is used to reference the element present at the position given inside the operator.
 * map::clear() 	   - Removes all the elements from the map.
 * map::at() and       - at() function is used to return the reference to the element associated with the key k. swap() function 
 * map::swap()           is used to exchange the contents of two maps but the maps must be of the same type, although sizes may 
 *                       differ.
*/

#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<int, std::string> m;

    // Different ways of inserting data

    m.insert(std::pair<int, std::string>(1, "one"));
    m.insert(std::pair<int, std::string>(2, "two"));
    m.insert(std::pair<int, std::string>(3, "three"));
    m.insert(std::pair<int, std::string>(3, "theree"));  // Will be ignore since key of 3 exists unless you do m[3] = "theree".
    m.insert({4, "four"});
    m[5] = "five"; // Assignment insert of insert. Will create if not exists
    m[6] = "sis";  // Assignment insert of insert. Will create if not exists
    m[6] = "six";  // Modification since key exists

    for (auto i : m)
    {
        std::cout << i.first << " : " << i.second << "\n";
    }

    std::cout << "Another way to print : \n";

    for (auto i = m.begin(); i != m.end(); ++i)
    {
        std::cout << i->first << " : " << i->second << "\n";
    }

    std::cout << "Another way to print in reverse : \n";

    for (auto i = m.crbegin(); i != m.crend(); ++i)
    {
        std::cout << i->first << " : " << i->second << "\n";
    }

    std::cout << "\n";

    // check if a key exists
    const int key = 9;

    if (m.count(key) > 0)
    {
        std::cout << "Key " << key << " exists\n";
    } else{
        std::cout << "Key " << key << " does not exists\n";
    }

    std::cout << "Another way to find >\n";

    if (m.find(key) != m.end())
    {
        std::cout << "Key " << key << " exists\n";
    } else{
        std::cout << "Key " << key << " does not exists\n";
    }

    std::cout << "record at 2 -> " << m.at(2) << "\n";

    // Swapping value between two maps

    std::map<int, std::string> n {{7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"}, {11, "eleven"}, {12, "twelve"}};

    std::swap(m,n);

    std::cout << "m: \n";

    for (auto i = m.cbegin(); i != m.cend(); ++i)
    {
        std::cout << i->first << " : " << i->second << "\n";
    }

    std::cout << "n: \n";

    for (auto i = n.cbegin(); i != n.cend(); ++i)
    {
        std::cout << i->first << " : " << i->second << "\n";
    }

    return 0;
}