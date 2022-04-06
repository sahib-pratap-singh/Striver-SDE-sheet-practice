//We can use array to reverse the linked list.
//Time complexity: O(N)
//Space complexity: O(N)

//We can use stack to reverse the linked list
//Time complexity: O(N)
//Space complexity: O(N)

//Recursive way to reverse the linked list
//Time complexity: O(N)
//Space complexity: O(1)
//Auxiliary space: O(N)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* cur=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return cur;
    }
};

//Iterative way to reverse the linked list
//Time complexity: O(N)
//Space complexity: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* cur=head;
        ListNode* prev=NULL;
        ListNode* nxt=head->next;
        while(nxt!=NULL){
            cur->next=prev;
            prev=cur;
            cur=nxt;
            nxt=nxt->next;
        }
        cur->next=prev;
        return cur;
    }
};