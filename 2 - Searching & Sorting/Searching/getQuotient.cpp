#include <iostream>
using namespace std;

int getQuotient(int divisor, int dividend) {
    int s = 0;
    int e = abs(dividend); // Use absolute value for ease of calculation
    int ans = -1;
    int mid;

    while (s <= e) {
        mid = s + (e - s) / 2;
        if (mid * divisor == dividend) {
            return mid;
        } else if (mid * divisor < dividend) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    int divisor = 7;
    int dividend = -29;

    int ans = getQuotient(divisor, abs(dividend)); 
    cout << "Intermediate ans is: " << ans << endl;

    // Check the signs and adjust the result accordingly
    if ((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0)) {
        ans = -ans;
    }

    cout << "Final ans is: " << ans << endl;
    return 0;
}
