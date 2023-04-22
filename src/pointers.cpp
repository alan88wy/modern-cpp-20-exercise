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

   cout << showbase;
   cout << "&a : " << hex << static_cast<void *>(&a) << endl;
   cout << " p : " << hex << static_cast<const void *>(p) << endl;
   cout << "*p : " << *p << endl;

   cout << noshowbase;

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
   cout << "n = operation (20, m, minus) is " << n << endl; // sames as calling substraction(20, m);

   // Array of const pointer to const char

   const char * student[] {
      "James Dean",
      "Thor",
      "Iron Man"
   };

   cout << endl;
   for (auto st : student) {
      cout << st << endl;
   }


   // *student[0] = "Hulk" // will cause error - read-only variable is not assignable

   // However, we can do this
   
   const char * new_student { "Hulk" };
   student[0] = new_student;

   cout << endl;
   cout << "Assign Hulk to student[0] .... " << endl;
   cout << endl;

   for (auto st : student) {
      cout << st << endl;
   }

   int scores[] {1,2,3,4,5,6};

   int *p_score {scores};

   int number { 21};

   // pointer decay
   p_score = &number;

   cout << *p_score << endl;

   // Swapping array
   int arr1[] {1,2,3,4};
   int arr2[] {5,6,7,8};

   int * temp {nullptr};

   int * p_arr1 { arr1 };
   int * p_arr2 { arr2 };
   temp = p_arr1;
   p_arr1 = p_arr2;
   p_arr2 = temp;

   for (size_t i {}; i < size(arr1); i++) {
      cout << p_arr1[i] << " ";
   }

   cout << dec << endl;

   // Pointer arithmathic
   int arr3[] {1,2,3,4,5,6,7,8,9,10};
   int * ptr1 {arr3 + 0};
   int * ptr2 {arr3 + 5};

   cout << "ptr1 : " << ptr1 << endl;
   cout << "ptr2 : " << ptr2 << endl;
   cout << "ptr2 - ptr1 : " << ptr2 - ptr1 << endl;
   cout << "ptr1 - ptr2 : " << ptr1 - ptr2 << endl;

   // C++ also have ptrdiff_t to store the diff
   ptrdiff_t pos_diff = ptr2 - ptr1;
   ptrdiff_t neg_diff = ptr1 - ptr2;

   cout << "pos_diff : " << pos_diff << endl;
   cout << "neg_diff : " << neg_diff << endl;
   
   cout << "Size of ptrdiff_t : " << sizeof(ptrdiff_t) << endl;

   cout << "Comparing pointers " << boolalpha << endl;
   cout << endl;
   cout << "ptr1 > ptr2 : " << (ptr1 > ptr2) << endl;
   cout << "ptr1 < ptr2 : " << (ptr1 < ptr2) << endl;
   cout << "ptr1 >= ptr2 : " << (ptr1 >= ptr2) << endl;
   cout << "ptr1 <= ptr2 : " << (ptr1 <= ptr2) << endl;
   cout << "ptr1 == ptr2 : " << (ptr1 == ptr2) << endl;
   cout << "ptr1 != ptr2 : " << (ptr1 != ptr2) << endl;
   cout << noboolalpha << endl;

   int * ptr4 { nullptr };
   
   ptr4 = new int;

   *ptr4 = 50;

   cout << "ptr4 : " << *ptr4 << endl;

   delete ptr4;
   ptr4 = nullptr; // Always good to reset memory to nullptr. Otherwise, it will contain junk data.

   // Can re-use pointer
   ptr4 = new int {45};
   cout << "ptr4 re-used : " << *ptr4 << endl;

   delete ptr4;
   ptr4 = nullptr; // Always good to reset memory to nullptr


   return 0;

}