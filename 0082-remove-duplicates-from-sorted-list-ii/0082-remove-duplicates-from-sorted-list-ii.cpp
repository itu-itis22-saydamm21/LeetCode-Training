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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* traverse = head;
        ListNode* prev = newHead;
        while(traverse){
            if(traverse->next && traverse->val == traverse->next->val){
                while(traverse->next && traverse->val == traverse->next->val)
                    traverse = traverse->next;
                prev->next = traverse->next;
            }
            else{
                prev = prev->next;
            }
            traverse = traverse->next;
        }
        
        return newHead->next;
    }
};