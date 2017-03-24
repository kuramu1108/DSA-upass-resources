#include <string>

using std::string;

/*
 * Take an integer n and return n+1.
 */
int addOne(int n){

  return n+1;
}

/*
 * Take a char as a parameter, and return the integer equivalent
 * in terms of a simple cast.
 */
int charToInt(char c){

  return (int) c;
}

/*
 * Take two ints, return their sum.
 */
int add(int a, int b){

  return a+b;
}

/*
 * Same as before, but the inputs are little different.
 */
int ptrAdd(int * a, int * b){

  return *a + *b;
}

/*
 * Return a divided by b, using integer division.
 */
int integerDiv(int a, int b){

  return a/b;
}

/*
 * Take two ints, return a/b as a double.
 */
double doubleDiv(int a, int b){

  return (double)a/(double)b;
}

/*
 * Return whether the passed in int is even.
 */
bool even(int a){

  return a % 2 == 0 ? true: false ;
}

/*
 * Use the function even(int) to implement a function to test whether
 * and int is odd.
 */
bool odd(int a){

  return even(a)? false: true ;
}

/*
 * Take two strings, return their concatentation s + t.
 */
string concatenate(string s, string t){

  return s+t;
}

/*
 * Take in an array of n ints, return an array with one added to each int.
 * This one might be a bit trickier. Can you get it compile without warnings?
 * Can you get it to compile without warnings and also not be a terrible piece of code?
 * (Why is it terrible?)
 */
int* twiddle(int a[], int n){
  int* temp = new int;
  for (int i = 0; i< n; i++) {
    *temp = a[i] + 1;
    temp++;
  }
  temp-=n;
  return temp;
}
