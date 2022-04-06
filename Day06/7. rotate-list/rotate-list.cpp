//We can use array to rotate the linked list.
//Time complexity: O(N)
//Space complexity: O(N)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return 0;
        }
        vector<int> nums;
        ListNode* node=head;
        while(node){
            nums.push_back(node->val);
            node=node->next;
        }
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        node=head;
        int i=0;
        while(node){
            node->val=nums[i++];
            node=node->next;
        }
        return head;
    }
};

//Another approach is to 
//1. Reverse the full list
//2. reverse first k size list
//3. reverse remaning list i:e (n-k)
//You will get the result
//Time complexity: O(N)
//Space complexity: O(1)

class Solution {
public:
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
    
    ListNode* rotateRight(ListNode* head, int k) {
        //If the node is NULL
        if(head==NULL)
            return 0;
        
        //Calculate the length of linked list
        
        ListNode* newhead = head;
        int length=0;
        while(newhead!=NULL){
            length++;
            newhead=newhead->next;
        }
        
        
        k = k%length;
        if(k==0)
            return head;
        
        //Reverse list
        head=reverseList(head);
        
        //Find the kth node 
        ListNode* kthnode=head;
        while(k>1 && kthnode){
            kthnode=kthnode->next;
            k--;
        }

        if(kthnode==NULL || kthnode->next==NULL)
            return head;
        
        //Reverse second list
        ListNode* secondhalf=reverseList(kthnode->next);
        kthnode->next=NULL;
        
        //Reverse first list
        ListNode* firsthalfend=reverseList(head);
        ListNode* result=firsthalfend;
        
        //Link firlt list to second list
        while(firsthalfend && firsthalfend->next){
            firsthalfend=firsthalfend->next;
        }
        firsthalfend->next=secondhalf;
        
        return result;
    }
};

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