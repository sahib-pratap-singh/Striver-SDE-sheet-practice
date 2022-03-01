//Simple math to add two numbers
//Time complexity: O(max(l1,l2));
//Space complexity: O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummy=new ListNode(0);
        ListNode* newnode=dummy;
        while(l1!=NULL || l2!=NULL){
            int a=l1==NULL?0:l1->val;
            int b=l2==NULL?0:l2->val;
            int sum=a+b+carry;
            carry= (sum)/10;
            ListNode* nextnode=new ListNode((sum)%10);
            newnode->next=nextnode;
            newnode=newnode->next;
            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2=l2->next;
            }
        }
        if(carry>0){
            newnode->next=new ListNode(carry);
        }
        return dummy->next;
    }
};