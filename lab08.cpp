#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned n);
unsigned factTail(unsigned n, unsigned acc);

unsigned fib(unsigned n);
unsigned fibTail(unsigned n, unsigned a, unsigned b);

unsigned mult(unsigned x, unsigned y);
unsigned multTail(unsigned x, unsigned y, unsigned acc);

unsigned power(unsigned x, unsigned y);
unsigned powerTail(unsigned x, unsigned y, unsigned acc);

unsigned product(unsigned x, unsigned y);
unsigned productTail(unsigned x, unsigned y, unsigned acc);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

// Factorial: n! = n*(n-1)!
unsigned fact(unsigned n) {
    return factTail(n, 1);
}

unsigned factTail(unsigned n, unsigned acc) {
    if (n <= 1) return acc;
    return factTail(n - 1, acc * n);
}

// Fibonacci: fib(n) = fib(n-1) + fib(n-2)
unsigned fib(unsigned n) {
    return fibTail(n, 0, 1);
}

// a = fib(n-2), b = fib(n-1)
unsigned fibTail(unsigned n, unsigned a, unsigned b) {
    if (n == 0) return a;
    if (n == 1) return b;
    return fibTail(n - 1, b, a + b);
}

// Multiplication using repeated addition
unsigned mult(unsigned x, unsigned y) {
    return multTail(x, y, 0);
}

unsigned multTail(unsigned x, unsigned y, unsigned acc) {
    if (y == 0) return acc;
    return multTail(x, y - 1, acc + x);
}

// Power: x^y
unsigned power(unsigned x, unsigned y) {
    return powerTail(x, y, 1);
}

unsigned powerTail(unsigned x, unsigned y, unsigned acc) {
    if (y == 0) return acc;
    return powerTail(x, y - 1, acc * x);
}

// Product of consecutive numbers from x to y
unsigned product(unsigned x, unsigned y) {
    return productTail(x, y, 1);
}

unsigned productTail(unsigned x, unsigned y, unsigned acc) {
    if (x > y) return acc;  // base case
    return productTail(x + 1, y, acc * x);
}
