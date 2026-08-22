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
        ListNode* dummy = new ListNode(23);
        dummy->next=head;
        ListNode* fp = dummy;
        ListNode* sp = dummy;
        int i=0;
        for(i;i<n;i++){
            sp=sp->next;
        }
        while(sp->next!=NULL ){
            fp=fp->next;
            sp=sp->next;
        }
        fp->next=fp->next->next;
        return dummy->next;

    }
};