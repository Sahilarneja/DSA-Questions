// https://leetcode.com/problems/coin-change/submissions/1226706703/
class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        // Base case: if amount becomes 0, we don't need any more coins.
        if (amount == 0) {
            return 0;
        }

        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int coin = coins[i];
            // Check if the current coin can be used.
            if (coin <= amount) {
                // Recursively find the minimum number of coins needed for the remaining amount.
                int recAns = solve(coins, amount - coin);
                // If recAns is not INT_MAX, update ans.
                if (recAns != INT_MAX) {
                    mini = min(mini, 1 + recAns);
                }
            }
        }
        return mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        // Get the minimum number of coins needed.
        int ans = solve(coins, amount);
        // If ans is still INT_MAX, it means it's not possible to make the amount with given coins.
        if (ans == INT_MAX) {
            return -1;
        } else {
            return ans;
        }
    }
};