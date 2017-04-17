#include <iostream>
#include <cmath>
#include <string>
/*
 * Prints a triangle of *s, height rows high.
 */
void stars(int height){

  for (int i = 0; i < height; i++){
    for (int j = 0; j <= i; j++){
      std::cout << "*";
    }
    std::cout << std::endl;
  }
  
}

/*
 * Prints a square of #s of side length height.
 */
void square(int height){

   for (int i = 0; i < height; i++){
    for (int j = 0; j < height; j++){
      std::cout << "#";
    }
    std::cout << std::endl;
  } 

}

/*
 * Draws a line of -s of length "length".
 */
void line(int length){

  for (int i = 0; i < length; i++){
    std::cout << "-";
  }
  std::cout << std::endl;

}

/*
 * Breeds rabbits for gen generations.
 */

void printRabbit(int num){

  std::string line[] = {"(\\_/)", "('.')", "(> <)"};

  for (int l = 0; l < 3; l++){
    for (int i = 0; i < num; i++){
      std::cout << line[l];
    }
    std::cout << std::endl;
  }
}

void bunnies(int gen){

  for (int i = 0; i < gen; i++){
    printRabbit(pow(2,i));
    std::cout << std::endl;
  }
  
}

/*
 * Computes the greatest common divisor of m and n.
 */
int gcd(int n, int m){

  while (n != m){

    if (n > m){
      n = n - m;
    }
    else{
      m = m -n;
    }
  }
  return n;

}  

int main(){

  int n;
  std::cout << "How tall of a triangle do you want?" << std::endl;
  std::cin >> n;
  stars(n);

  std::cout << "\nWhat size square do you want?" << std::endl;
  std::cin >> n;
  square(n);

  std::cout << "\nWhat length line do you want?" << std::endl;
  std::cin >> n;
  line(n);

  std::cout << "\nHow many generations of rabbits do you need?" << std::endl;
  std::cin >> n;
  bunnies(n);

  int a, b;
  std::cout << "Give me a positive integer:" << std::endl;
  std::cin >> a;
  std::cout << "Give me a second one:" << std::endl;
  std::cin >> b;
  std::cout << "\nTheir greatest common divisor is " << gcd(a,b) << "." << std::endl;
}
