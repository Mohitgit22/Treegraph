/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode* curr1 = headA, *curr2 = headB;

        while(curr1){
            len1++;
            curr1 = curr1->next;
        }
        while(curr2){
            len2++;
            curr2 = curr2->next;
        }
        
        int diff = abs(len1 - len2);

        ListNode* temp = len1 > len2 ? headA : headB;
        ListNode* smaller = len1 > len2 ? headB : headA;
        while(diff>0){
            temp = temp->next;
            diff--;
        }
      
        while(smaller != temp){
            smaller = smaller->next;
            temp = temp->next;
        }
        return smaller;

    }
};