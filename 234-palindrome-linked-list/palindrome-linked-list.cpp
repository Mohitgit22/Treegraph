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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr, * front = nullptr, *temp = head;

        while(temp){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;

        while(fast and fast->next){
         slow = slow->next;
         fast = fast->next->next;
        }

        ListNode* curr2 = reverse(slow);
        ListNode* curr1 = head;

        while(curr1 and curr2){
            if(curr1->val != curr2->val)
            return false;

            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return true;
    }
};