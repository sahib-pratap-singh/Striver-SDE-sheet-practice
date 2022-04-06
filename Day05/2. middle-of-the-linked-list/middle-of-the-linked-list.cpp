//We can use array to find middle of the linked list.
//Time complexity: O(N)
//Space complexity: O(N)


//Find the size of linked list and iterate till mid and return
//Time complexity: O(N)
//Space complexity: O(1)


//Using Fast and Slow Pointer
//Time complexity: O(N)
//Space complexity: O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

//Initialize mid element as head and initialize a counter as 0. 
//Traverse the list from head, while traversing increment the counter and change mid to mid->next whenever the counter is odd. 
//So the mid will move only half of the total length of the list. 
//Time complexity: O(N)
//Space complexity: O(1)

ListNode* middleNode(ListNode* head)
{
    int count = 0;
    ListNode* mid = head;
    while (head != NULL)
    {
        // Update mid, when 'count'
        // is odd number
        if (count & 1)
            mid = mid->next;
 
        ++count;
        head = head->next;
    }
    return mid;
}