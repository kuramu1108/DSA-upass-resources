#include <cxxtest/TestSuite.h>
#include <string>

using std::string;

int addOne(int);
int charToInt(char);
int add(int, int);
int ptrAdd(int*, int*);
int integerDiv(int, int);
double doubleDiv(int, int);
bool even(int);
bool odd(int);
string concatenate(string, string);
int* twiddle(int*, int);

class MyTestSuite1 : public CxxTest::TestSuite
{
public:
  
    void testAddOne(void){
      for (int i = 0; i < 100; i++){
	TS_ASSERT_EQUALS(addOne(i), i+1);
      }
    }

    void testCharToInt(void){

      for (char l = 'a'; l <= 'a' + 26; l++){
	TS_ASSERT_EQUALS(charToInt(l), (int)l);
      }
      
    }

    void testAdd(void){

      for (int a = 1; a < 100; a++){
	int b = 0;
	while (b > -30){
	  TS_ASSERT_EQUALS(add(a,b),a+b);
	  b--;
	}
      }
    }

    void testPtrAdd(void){

      for (int a = 1; a < 100; a++){
	int b = 0;
	while (b > -30){
	  TS_ASSERT_EQUALS(ptrAdd(&a,&b),a+b);
	  b--;
	}
      }
    }

    void testIntegerDiv(void){

      int a = 0;
      do{
	int b = 1;
	do{
	  TS_ASSERT_EQUALS(integerDiv(a,b), a/b);
	  b++;
	} while(b < 100);
	a++;
      } while (a < 99);
    }

    void testDoubleDiv(void){
      int a = 0;
      do{
	int b = 1;
	do{
	  double da = a;
	  double db = b;
	  TS_ASSERT_EQUALS(doubleDiv(a,b), da/db);
	  b++;
	} while(b < 100);
	a++;
      } while (a < 99);
    }


    void testEven(void){

      for (int i = 0; i < 1000; i += 2){
	TS_ASSERT_EQUALS(even(i), true);
      }

      for (int i = 1; i < 1000; i += 2){
	TS_ASSERT_EQUALS(even(i), false);
      }
    }

    void testOdd(void){
      for (int i = 0; i < 1000; i += 2){
	TS_ASSERT_EQUALS(odd(i), false);
      }

      for (int i = 1; i < 1000; i += 2){
	TS_ASSERT_EQUALS(odd(i), true);
      }
    }

    void testConcatenate(void){

      string foo = "foo";
      string bar = "bar";

      TS_ASSERT_EQUALS(concatenate(foo, bar), "foobar");
    }

    void testTwiddle(void){

      int a[] = {1,4,2,5,6,7,4,3};

      int * b = twiddle(a, 8);

      for (int i = 0; i < 8; i++){
	TS_ASSERT_EQUALS(a[i] + 1, *(b+i));
      }

    }
};
