//Using hashing
//Time complexity: O(n)
//Space complexity: O(n)

//Floyd’s Cycle-Finding Algorithm 
//Time complexity: O(n)
//Space complexity: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};

//One easy methos is to modify the values of the linked list to tha value which is not in the range.
//When you encounter this value again then there is loop
//Time complexity: O(n)
//Space complexity: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        while(head){
            if(head->val==1000000){
                return true;
            }
            head->val=1000000;
            head=head->next;
        }
        return false;
    }
};