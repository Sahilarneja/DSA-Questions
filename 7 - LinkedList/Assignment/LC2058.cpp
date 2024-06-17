// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/submissions/1290759634/ 
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1}; // minDist & maxDist

        if (!head || !head->next || !head->next->next) {
            return ans;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = curr->next;

        int firstCP = -1;
        int lastCP = -1;
        int minDist = INT_MAX;
        int i = 1;

        while (nxt != nullptr) {
            bool isCP = (curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val);

            if (isCP) {
                if (firstCP == -1) {
                    firstCP = i;
                } else {
                    minDist = min(minDist, i - lastCP);
                }
                lastCP = i;
            }

            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            i++;
        }

        if (lastCP == firstCP) {
            return ans; // There exists only one CP
        } else {
            ans[0] = minDist;
            ans[1] = lastCP - firstCP;
        }
        
        return ans;
    }
};
