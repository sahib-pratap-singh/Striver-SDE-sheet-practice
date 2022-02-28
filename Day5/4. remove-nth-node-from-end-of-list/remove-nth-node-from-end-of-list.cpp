//We can use array to remove nth node from end of the linked list.
//Time complexity: O(N)
//Space complexity: O(N)


//Find the size of linked list and iterate till n-k+1 and return
//Time complexity: O(N)
//Space complexity: O(1)


//Using Fast and Slow Pointer
//Time complexity: O(N)
//Space complexity: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newnode= new ListNode(0);
        newnode->next=head;
        ListNode* slow=newnode;
        ListNode* fast=newnode;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return newnode->next;
    }
};