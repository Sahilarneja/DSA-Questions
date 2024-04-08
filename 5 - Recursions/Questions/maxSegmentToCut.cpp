//GFG- MAXIMUM THE CUT SEGMENT
#include <iostream>
#include <climits>
using namespace std;

int findMaxSegment(int n, int x, int y, int z){
    //base cases
    if(n == 0){
        return 0;
    }
    if(n < 0){
        return INT_MIN;
    }

    //option1 -- x segment cut krdiya baaki recursion dekhega
    int option1 = 1 + findMaxSegment(n-x, x, y, z);

    //option2 -- y segment
    int option2 = 1 + findMaxSegment(n-y, x, y, z);

    //option3 -- z segment
    int option3 = 1 + findMaxSegment(n-z, x, y,z);

    int result = max(option1, max(option2, option3));
    return result;
}

