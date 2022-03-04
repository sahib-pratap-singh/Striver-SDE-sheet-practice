//We can use array to rotate the linked list.
//Time complexity: O(N)
//Space complexity: O(N)

//Another approach is to 
//1. Reverse the full list
//2. reverse first k size list
//3. reverse remaning list i:e (n-k)
//You will get the result
//Time complexity: O(N)
//Space complexity: O(1)

//Another approach is to make list cyclic
//Time complexity: O(N)
//Space complexity: O(1)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        int length = 0;
        ListNode* newhead = head;
        while(newhead!=NULL){
            length++;
            if(newhead->next==NULL){
                newhead->next=head;
                break;
            }
            newhead=newhead->next;
        }
        k = length - k%length;
        for(int i=0;i<k;i++){
            newhead=newhead->next;
        }
        head=newhead->next;
        newhead->next=NULL;
        return head;
    }
};