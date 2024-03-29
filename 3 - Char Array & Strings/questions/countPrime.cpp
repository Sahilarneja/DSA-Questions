// https://leetcode.com/problems/count-primes/submissions/1217503967/
class Solution {
public:
    
    bool isPrime(int n){
        if(n <= 1){
            return false;
        }
        for(int i=2; i<n; i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    } 

    //Naive approach
    int countPrimes(int n) {
        //Naive approach
    //     int count = 0;
    //     for(int i = 2; i < n; i++){
    //         if(isPrime(i)){
    //             count++;
    //         }
    //     }
    //     return count;
    // }


    // sieve approach

        if(n <= 2) return 0;

        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        int ans = 0;

        for(int i = 2; i * i < n; i++) {
            if(prime[i]) {
                for(int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        for(int i = 2; i < n; i++) {
            if(prime[i]) ans++;
        }

        return ans;
    }
};