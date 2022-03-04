class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head->next==NULL){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* cur=dummy;
        ListNode* nxt;
        ListNode* pre=dummy;
        ListNode* tmp;
        int n=0;
        while(cur!=NULL){
            n++;
            cur=cur->next;
        }
        while(n>k){
            cur=pre->next;
            nxt=cur->next;
            for(int i=1;i<k;i++){
                tmp=nxt->next;
                nxt->next=pre->next;
                pre->next=nxt;
                cur->next=tmp;
                nxt=cur->next;
            }
            pre=cur;
            n-=k;
        }
        return dummy->next;
    }
};