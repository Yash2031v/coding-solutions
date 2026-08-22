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
    bool isPalindrome(ListNode* head) {
        vector<int>n;
        ListNode* temp = head;
        while(temp!=NULL){
            n.push_back(temp->val);
            temp=temp->next;
        }
        
        int r = n.size()-1;
        int f = 0;
        while(r>=f){
            if(n[r]!=n[f]){
                return false;
            }
            r--;
            f++;
        }
        return true;
    }
};