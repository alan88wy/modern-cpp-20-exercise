/*
    Pointer to char:
    ****************

    The keyword const refers to its immediate left, or immediate right if there is nothing on the left.

    So

    -> char* is a “(mutable) pointer to a (mutable) character”
    -> const char* and char const * are both “(mutable) pointers to constant character(s)”. 
       (the “constant” thing are the characters, pointers can be “re-pointed” to other characters)
    -> char * const is instead a “constant pointer to a (mutable) character” (the “constant” thing is the pointer: 
       you can change what it points to, but not make it to point somewhere else.
    -> const char * const and char const * const are “constant pointers to constant character(s)”

    -> char* ptr;       // Pointer to char ==> You can modify the pointer(ptr) and the character string it contains (*ptr)
    -> const char* ptr; // Pointer to a char const ==> You can modify the pointer(ptr) but you cannot modify the character 
                           string it contains (*ptr)
    -> char const* ptr; // Pointer to a const char (that means it is the same as 2) ==> You can modify the pointer(ptr) but 
                           you cannot modify the character string it contains (*ptr)
    -> char* const ptr; // Const pointer to a char ==> You cannot modify the pointer(ptr) but you can modify modify the 
                           character string it contains (*ptr)
    -> const char* const ptr; // Const pointer to a char const ==> You cannot modify the pointer(ptr) and 
                                 you cannot modify the character string it contains (*ptr)

   C++ allows the use of pointers that point to pointers, that these, in its turn, point to data (or even to other pointers). 
   The syntax simply requires an asterisk (*) for each level of indirection in the declaration of the pointer:

   

*/

#include <iostream>

using namespace std;

// functions
int addition (int a, int b) { 
   return (a+b); 
   }

int subtraction (int a, int b) { 
   return (a-b); 
   }

int operation (int x, int y, int (*functocall)(int,int)) {
  int g;
  g = (*functocall)(x,y);
  return (g);
}


int main() {

   char a {'C'};
   char *ptr { &a };
   const char* p { &a };   // this will cause compile time warming it it is not initialized during declaration
   const char* const q { p };   // Must point to another pointer during declaration
   char const * r;
   char* const s { ptr };  // can change value of s

   // cout << showbase;
   cout << "&a : " << &a << endl;
   cout << " p : " << p << endl;
   cout << "*p : " << *p << endl;

   // cout << noshowbase;

      p = &a;
      // *p = 'D';  - Cannot modify since we declare as const char*

      // *q = 'a'; - This will not work since we declare as const char const q

      r = &a;
      // *r = 'D'; // This will not work since we declare as const *r

   cout << "a = 'C', *ptr = &a, s = ptr, r = &a" << endl;
   cout << "a : " << a << endl;
   cout << "*r : " <<  *r << endl;

   *s = 'S';

   cout << "*s = 'S' : " << *s << endl;
   cout << "a : " << a << endl;
   cout << endl;

   // Pointer to int

   int firstvalue = 5, secondvalue = 15;
   int * p1, * p2;

   p1 = &firstvalue;  // p1 = address of firstvalue
   p2 = &secondvalue; // p2 = address of secondvalue
   *p1 = 10;          // value pointed to by p1 = 10
   *p2 = *p1;         // value pointed to by p2 = value pointed to by p1
   p1 = p2;           // p1 = p2 (value of pointer is copied)
   *p1 = 20;          // value pointed to by p1 = 20

   cout << "firstvalue is " << firstvalue << '\n';
   cout << "secondvalue is " << secondvalue << '\n';
   cout << "address of firstvalue is " << &firstvalue << '\n';
   cout << "p1 is " << *p1 << '\n';
   cout << "p2 is " << *p2 << '\n';

   // Pointer has similar characteristics as an array ?
   *p1 += 1;
   cout << "p1 is " << *p1 << '\n';
   p1[0] = 10;
   p1[1] = 12;
   cout << "p1 is " << *p1 << '\n';
   cout << "*(p1+1) is " << *(p1+1) << '\n';
   cout << "p1[1] is " << p1[1] << '\n';

   // Pointer to pointer

   // char a1;
   char * b;
   char ** c;
   // a1 = 'z';
   b = &a;
   c = &b;   // c point to pointer b

   cout << "a is " << a << endl;
   cout << "*b (=& a1) is " << *b << endl;
   cout << "**c (= &b) is " << **c << endl;

   // Pointer to function
   int m,n;
   int (*minus)(int,int) = subtraction;  // minus point to function substraction

   m = operation (7, 5, addition);

   cout << "m = operation (7, 5, addition) is " << m << endl;
   n = operation (20, m, minus);
   cout << "n = operation (20, m, minus) is " << n << endl; // sames as calling substraction (20, m);

   return 0;

}