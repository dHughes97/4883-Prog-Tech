## P2 - Add Two Numbers
### Delton Hughes
### Description:
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



### Input Examples: 
Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2: 
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
- The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
- It is guaranteed that the list represents a number that does not have leading zeros.


Solution: 
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // This function returns a ListNode and takes two linked lists 
    // It returns a pointer to the head of the linked list
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Initializing: 
        ListNode* temp = new ListNode(); // starting point of the result linked list 
        ListNode* current = temp;        // Builds the new linked list
        int carry = 0;                 // Holds the carry
        

        // the loop continues until both lists reach the end and the is no carry left. 
        while(l1 || l2 || carry){

            // if l1 is !NULL (has val) pointer return the val inside l1 node ":" aka else return 0  
            // Same thing for l2 and lastly if there is a carry add it at the end. 
            int sum = (l1 ? l1->val : 0) +  (l2 ? l2->val : 0) + carry; 
            // if the carry is >= 10 then it will be stored in the counter as 1. 
            carry = sum/10;

            int digit = sum % 10; 

            current->next = new ListNode(digit); // Create a new node for the result list 
            current = current-> next; // Move the current pointer forward. 
            // Move to the next nodes if they exist 
            if(l1) l1 = l1-> next; 
            if(l2) l2 = l2-> next; 

        }

        return temp->next; // Return the list starting from the node after L3
    }
};
```
