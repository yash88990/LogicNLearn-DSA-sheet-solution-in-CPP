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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* curr = head;
        while(curr){
            curr=curr->next;
            cnt++;
        }
        int ans = cnt - n;
        if(ans == 0){
            ListNode* newhead = head;
            head = head->next;
            delete newhead;
            return head;
        }
        cnt = 0;
        curr = head;
        while(cnt < ans - 1){
            curr = curr->next;
            cnt++;
        }
        ListNode* nextnode = curr->next;
        curr->next = curr->next->next;
        delete nextnode;
        return  head;
    }
};