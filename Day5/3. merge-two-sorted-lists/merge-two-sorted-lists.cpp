//We can use array to sort the linked list.
//Time complexity: O(Nlog(N))
//Space complexity: O(N)

//We can use another Linked list to store sorted nodes
//Time complexity: O(N)
//Space complexity: O(N)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* target=new ListNode(0);
        ListNode* result=target;
        while(l1 and l2){
            if(l1->val<=l2->val){
                target->next=l1;
                l1=l1->next;
            }
            else{
                target->next=l2;
                l2=l2->next;
            }
            target=target->next;
        }
        target->next=l1?l1:l2;
        return result->next;
    }
};

//We can connect first linked list to second linked list and use insertion sort
//Time complexity: O(N*N)
//Space complexity: O(1)

//We can connect first linked list to second linked list and use merge sort
//Time complexity: O(Nlog(N))
//Space complexity: O(1)


//Recursive method of inplace merging
//Time complexity: O(N)
//Space complexity: O(N)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if (!h1)
        return h2;
        if (!h2)
            return h1;

        // start with the linked list
        // whose head data is the least
        if (h1->val < h2->val) {
            h1->next = mergeTwoLists(h1->next, h2);
            return h1;
        }
        else {
            h2->next = mergeTwoLists(h1, h2->next);
            return h2;
        }
    }
};


//Merging Inplace
//Time complexity: O(N)
//Space complexity: O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        if(l2->val<=l1->val){
            swap(l1,l2);
        }
        ListNode* res = l1;
        while(l1!=NULL and l2!=NULL){
            ListNode* temp = NULL;
            while(l1 and l1->val<=l2->val){
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            swap(l1,l2);
        }
        return res;
    }
};