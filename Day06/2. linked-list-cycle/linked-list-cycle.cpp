//Method 1

//Using hashing
//Here we will chech if the node we have visisted is present or not if we have visited it then it mean there is cycle.

//Time complexity: O(n)
//Space complexity: O(n)

class Solution {
public:
    unordered_map<ListNode*,int> mp;
    bool hasCycle(ListNode *head) {
        while(head!=NULL){
            if(mp.find(head) == mp.end()){
                mp[head]++;
            }
            else{
                return true;
            }
            head=head->next;
        }
        return false;
    }
};

//Method 2

//Floyd’s Cycle-Finding Algorithm 
//Here we will use two pointers slow and fast 
//where slow will travel one step and fast two step
//if they become same at some time there is cycle
//if fast is null then there is no cycle

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

//Method 3

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