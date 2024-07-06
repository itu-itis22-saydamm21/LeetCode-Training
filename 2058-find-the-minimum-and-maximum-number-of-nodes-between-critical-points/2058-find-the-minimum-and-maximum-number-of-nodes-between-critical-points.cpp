/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first_critic = -1;
        int curr_critic = -1;
        int min_dist = -1, max_dist = -1;
        int prev = head->val;
        int node = 1;
        head = head->next;
        node++;
        while(head->next){
            int curr = head->val;
            int next = head->next->val;
            
            if((curr > prev && curr > next) || (curr < prev && curr < next)){
                if(first_critic == -1) {
                    first_critic = node;
                    curr_critic = node;
                }
                else{
                    if(min_dist == -1)  min_dist = node - curr_critic;
                    else min_dist = min(min_dist, node - curr_critic);
                    curr_critic = node;
                }
            }
            prev = curr;
            head = head->next;
            node++;
        }
        if(min_dist != -1) max_dist = curr_critic - first_critic;
        vector<int> res(2);
        res[0] = min_dist;
        res[1] = max_dist;
        return(res);
    }
};