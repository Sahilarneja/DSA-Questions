#include <iostream>
#include <numeric> // for accumulate
using namespace std;

// Function to check if it's possible to allot books such that each student gets at most 'sol' pages
bool isPossibleSolution(int A[], int N, int M, int sol){
    int pageSum=0;
    int c=1;
    for(int i=0;i<N;i++){
        if(A[i]>sol){
            return false;
        }
        if(pageSum +A[i]>sol){
            c++;
            pageSum=A[i];
            if(c>M){
                return false;
            }
        }
        else{
            pageSum +=A[i];
        }
    }
    return true; // Return true when the condition is satisfied
}

// Function to find the minimum number of pages that can be allotted to students
int findPages(int A[], int N, int M){
    if(M>N) return -1;

    int start=0;
    int end=accumulate(A, A+N, 0);
    int ans=-1;

    while(start<=end){
        int mid=(start+end)>>1;
        if(isPossibleSolution(A,N,M,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}

// Book Allotment Question:
// Given an array A[] representing the number of pages of N books and M students, 
// the task is to find the minimum number of pages such that each student gets at most one contiguous set of pages.
// Example: A[] = {12, 34, 67, 90}, M = 2
// Output: 113 (Student 1 gets pages {12, 34, 67}, Student 2 gets pages {90})

int main() {
    int A[] = {12, 34, 67, 90};
    int N = sizeof(A) / sizeof(A[0]);
    int M = 2;

    int minPages = findPages(A, N, M);
    cout << "Minimum number of pages to allot: " << minPages << endl;

    return 0;
}
