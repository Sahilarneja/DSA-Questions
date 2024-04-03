#include <iostream>
using namespace std;

int fib(int n) {
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Recursive call 
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int result = fib(7); 

    cout << "Fibonacci value is: " << result << endl;
    return 0;
}
