/*
 * fib.cpp
 *
 *  Created on: 5Apr.,2017
 *      Author: 133145
 */

#include <iostream>
#include <vector>
#include <cmath>

/*
 * Recursive implementation of fibonacci number computation.
 * O(2^{n}) in time and space (each call frame is small, but there's lots of them).
 */
long long fib1(long long n){
	if (n == 1 || n == 0) return 1;

	return fib1(n-1) + fib1(n-2);
}

/*
 * Iterative dynamic programming implementation with an array.
 * O(n) time complexity, O(n) space complexity.
 */
long long fib2(long long n){
	if (n == 0 || n == 1) return 1;

	long long a[n+1];
	a[0] = 1;
	a[1] = 1;
	for (long long i = 2; i <= n; i++){
		a[i] = a[i-1] + a[i-2];
	}

	return a[n];
}

/*
 * Iterative implementation that just juggles variables.
 * O(n) time complexity, but O(1) space complexity.
 */
long long fib3(long long n){
	if (n == 0 || n == 1) return 1;

	long long a = 1;
	long long b = 1;
	for (long long i = 2; i <= n; i++){
		long long c = a + b;
		a = b;
		b = c;
	}

	return b;

}

/*
 * Recursive version with memoization.
 * O(n) time, O(n) space.
 */
long long fib4(long long n, long long * f){

	if (f[n] == 0){
		f[n] = fib4(n-1, f) + fib4(n-2, f);
	}

	return f[n];

}

long long fib4(long long n){
	if (n == 0 || n == 1) return 1;

	long long * f = new long long[n+1]();
	f[0] = 1;
	f[1] = 1;
	long long ret = fib4(n, f);
	delete f;
	return ret;

}


/*
 * A matrix based implementation.
 * O(n) time, O(1) space.
 */
std::vector<std::vector<long long> > matrixMult(const std::vector<std::vector<long long> > & M1, const std::vector<std::vector<long long> > & M2){

	std::vector<std::vector<long long> > M3(2);

	M3[0].resize(2);
	M3[1].resize(2);

	M3[0][0] = M1[0][0]*M2[0][0] + M1[0][1]*M2[0][1];
	M3[0][1] = M1[0][1]*M2[0][0] + M1[1][1]*M2[0][1];
	M3[1][0] = M2[0][1];
	M3[1][1] = M1[0][1]*M2[0][1] + M1[1][1]*M2[1][1];

	return M3;

}

long long fib5(long long n){

	std::vector<std::vector<long long> > M(2);
	std::vector<std::vector<long long> > F(2);

	M[0].resize(2);
	M[1].resize(2);
	F[0].resize(2);
	F[1].resize(2);

	M[0][0] = 1;
	M[0][1] = 0;
	M[1][0] = 0;
	M[1][1] = 1;

	F[0][0] = 1;
	F[0][1] = 1;
	F[1][0] = 1;
	F[1][1] = 0;

	for (long long i = 1; i <= n; i++){
		M = matrixMult(M,F);
	}

	return M[0][0];
}

/*
 * Matrix exponentiation based implementation. Uses recursion - so recursion isn't always slow!
 * O(log n) time!!! O(1) space (if done carefully, this one isn't).
 */
std::vector<std::vector<long long> > matrixPow(std::vector<std::vector<long long> > B, std::vector<std::vector<long long> > M, long long pow){



	if (pow == 0){

		std::vector<std::vector<long long> > I(2);
		I[0].resize(2);
		I[1].resize(2);

		I[0][0] = 1;
		I[0][1] = 0;
		I[1][0] = 0;
		I[1][1] = 1;

		return I;
	}

	if (pow == 1){
		return M;
	}

	if (pow%2 == 0){
		std::vector<std::vector<long long> > T = matrixPow(B, M, pow/2);
		return matrixMult(T,T);
	}
	else{

		return matrixMult(matrixPow(B, M, pow-1), B);
	}

}

long long fib6(long long n){

	std::vector<std::vector<long long> > M(2);
	M[0].resize(2);
	M[1].resize(2);

	M[0][0] = 1;
	M[0][1] = 1;
	M[1][0] = 1;
	M[1][1] = 0;

	std::vector<std::vector<long long> > B(2);
	B[0].resize(2);
	B[1].resize(2);

	B[0][0] = 1;
	B[0][1] = 1;
	B[1][0] = 1;
	B[1][1] = 0;

	M = matrixPow(B, M, n);

	return M[0][0];

}

/*
 * Closed form formula implementation. "Simple", but needs floating point arithmetic, so can run into precision problems very quickly.
 * O(log n) time with the quick exponentiation, O(n) without it. Here calculating the exponent phi^{n} is the "slow" bit. As before
 * this could be O(1) space, but in favour of better programming style, it uses O(log n) space.
 */

long double quickExp(long double base, long double current, int pow){

	if (pow == 0) return 1;
	if (pow == 1) return current;

	if (pow % 2 == 0){
		long double t = quickExp(base, current, pow/2);
		return t * t;
	}
	else{
		return base * quickExp(base, current, pow-1);
	}

}

long long fib7(long long n){

	double phi = (1 + std::sqrt(5))/2;

	long long f_n = std::floor(quickExp(phi, phi, n+1)/std::sqrt(5) + 0.5);

	return  f_n;

}


