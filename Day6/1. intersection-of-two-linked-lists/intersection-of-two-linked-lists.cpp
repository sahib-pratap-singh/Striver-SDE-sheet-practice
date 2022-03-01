//We can use hashmap
//Time complexity: O(N)
//Space complexity: O(N)

//Using difference of node counts
//count length of bith list and find diff trvers big list till diff
//after that compare both lists
//Time complexity: O(n+m)
//Space complexity: O(1)

//Two pointer technique
//Time complexity: O(n+m)
//Space complexity: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=b){
            a=a==NULL?headB:a->next;
            b=b==NULL?headA:b->next;
        }
        return a;
    }
};