#include <iostream>
using namespace std;

int main()
{
	/*int x, *y;
	x= 5;
 y = &x;

	cout<<"x is"<<x <<"\n";;
	cout<<"*y is "<< *y;
	system("Pause");
	return 0;*/


  unsigned int x = 6;
  unsigned int &z = x;
  unsigned int *y = &x;

  cout << "\nValue in z = " <<z << "\n";

  cout << "\nValue in x = " << x << "\n";
  cout << "Address of x = " << &x << "\n";

  cout << "\nAddress in y = " << y << "\n";
  cout << "Value of *y = " << *y << "\n";

  cout<<"vaule of &*y = "<<  &*y << "\n";

  cout << "\nNow make *y = 8\n";
  *y = 8;
  cout << "Value of x = " << x << "\n";
  return 0;
}

// void foo(int*);

//int main()
//{
//int x = 3;
//foo(&x);
//cout << "x in main = " << x << "\n";
//return 0;
//}
//
//void foo(int *y)
//{
//*y = 5;
//cout << "y in foo = " << *y << "\n";
//}

// void foo(int &y)
// {
// y = 5;
// cout << "y in foo = " << y << "\n";
// }
// int main()
// {
// int x = 3;
// foo(x);
// cout << "x in main = " << x << "\n";
// return 0;
// }