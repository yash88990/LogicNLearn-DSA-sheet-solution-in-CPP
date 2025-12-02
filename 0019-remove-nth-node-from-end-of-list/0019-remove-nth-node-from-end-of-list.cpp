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
        if(!head || !head->next)return NULL;
        int cnt = 0;
        ListNode* curr = head;
        while(curr){
            cnt++;
            curr = curr->next;
        }
        int pos = cnt - n;
        if(pos == cnt)return NULL;
        if(pos == 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        cnt = 0;
        curr = head;
        while(cnt < pos -1){
            curr = curr->next;
            cnt++;
        }
        ListNode* temp = curr->next;
        if(temp->next) curr->next = temp->next;
        else curr->next = NULL;
        delete temp;
        return head;
    }
};