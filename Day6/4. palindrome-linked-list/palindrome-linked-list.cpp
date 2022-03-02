//We can use array to check palindrme of linked list.
//Time complexity: O(N)
//Space complexity: O(N)

//We can use stack to check palindrme of linked list.
//Time complexity: O(N)
//Space complexity: O(N)

//Findind mid and reverse the next half to compare first half and second half of linked list
//Find mid
//Reverse second half
//compare
//Time complexity: O(n)
//Space complexity: O(1)
class Solution {
public:
    //Middle node
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    //Reverse a linked list
    ListNode* reverseList(ListNode* root) {
        ListNode* prev = NULL;
        ListNode* curr = root;
        while (curr != NULL) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* firsthalfend=middleNode(head);
        ListNode* secondhalf=reverseList(firsthalfend->next);
        // Check whether or not there is a palindrome.
        //cout<<secondhalf->val;
        ListNode* p1 = head;
        ListNode* p2 = secondhalf;
        bool result = true;
        while (result && p2 != NULL) {
            if (p1->val != p2->val) result = false;
            p1 = p1->next;
            p2 = p2->next;
        }        

        // Restore the list and return the result.
        firsthalfend->next = reverseList(secondhalf);
        return result;
    }
};