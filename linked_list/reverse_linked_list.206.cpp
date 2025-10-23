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

// Iteratively: O(n) time, O(1) space
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // !
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};

// Recursively: O(n) time, O(n) space
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         // base case: empty linked list or single node
//         if (head == nullptr || head->next == nullptr) return head;
//         // recursive case:
//         ListNode* newHead = reverseList(head->next);
//         head->next->next = head; // make the next node point back to the current node
//         head->next = nullptr; // set current node's next to nullptr to avoid cycles
//         return newHead;
//         }
// };

/*
Example visualization:
Original: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Step-by-step execution:
1. At node 4 (after recursing to base case at 5):
    BEFORE executing any code: 4 -> 5 -> NULL  (4->next points to node 5)
    
    ListNode* newHead = reverseList(head->next);
  - This recursively processes node 5 and returns 5 as newHead
  - After this returns, 4->next STILL points to 5 (unchanged)
  
    Line: head->next->next = head;
    - head is node 4
    - head->next is node 5 (because 4->next still points to 5)
    - head->next->next is 5->next (currently NULL)

    AFTER this line:
    4 -> 5 -> 4  (creates a cycle temporarily!)
        ^____|
    
    Line: head->next = nullptr;
    - We set 4->next = NULL (breaking the cycle)
    
    AFTER this line:
    5 -> 4 -> NULL
    (node 4 is now disconnected from node 5 going forward)
Key insight: We USE the old forward link (4->next = 5) to access node 5 
and reverse its pointer, THEN we break the old forward link.

2. At node 3 (returning from recursion):
   - 3->next = 4 (still pointing forward)
   - We execute: 3->next->next = 3  (which is 4->next = 3)
   - Now: 4 -> 3 (reversed!)
   - Then we set: 3->next = NULL
   - Result so far: 5 -> 4 -> 3 -> NULL
3. continues for all nodes...
Final Result: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
The trick: head->next->next = head happens BEFORE head->next = nullptr
*/