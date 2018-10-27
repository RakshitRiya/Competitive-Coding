#include <iostream>
using namespace std;

size_t get_size_1(int* arr)
{
  return sizeof arr; //return 4=size of pointer
}

size_t get_size_2(int arr[])
{
  return sizeof arr;//return 4=size of pointer
}

size_t get_size_3(int (&arr)[10])
{
  return sizeof arr;//return 40=size of array
}

int main()
{
  int array[10];
  //Assume sizeof(int*) != 10
  cout << (sizeof(array) == get_size_1(array));
  cout << (sizeof(array) == get_size_2(array));
  cout << (sizeof(array) == get_size_3(array));
}


/*
  output : 001
   This question compares three ways for a function to take an array as parameter, 
   while two of them are actually the same.

In main, the array is of array type, therefore the sizeof operator returns 
the size of the array in terms of bytes. (§5.3.3¶2 in the standard: "When applied to
an array, the result [of the sizeof operator] is the total number of bytes in the array. 
This implies that the size of an array of n elements is n times the size of an element.")

In get_size_3, the parameter is a reference to an array of size 10, therefore the sizeof operator 
returns the size of the array in terms of bytes. (§5.3.3¶2 in the standard: When applied to a reference 
or a reference type, the result is the size of the referenced type. )

In get_size_1 and get_size_2, the parameter is a pointer, therefore the sizeof operator returns the size of the pointer. 
Although the parameter of get_size_2 is an array, it is adjusted into a pointer. (§8.3.5¶5 in the standard: 
"any parameter of type “array of T” (...) is adjusted to be “pointer to T”" )

*/
