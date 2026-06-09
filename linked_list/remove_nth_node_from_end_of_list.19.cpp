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

 // To remove a node, we need access to the node BEFORE it.
// if n = length, we need to delete the head node, and there is no node before it in the linked list.
// so we need to create a dummy node before the head to handle this case.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // traverse and get the length
        ListNode* current = head;
        int length = 0;
        while (current != nullptr) {
            ++length;
            current = current->next;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        current = dummy;
        for (int i = 0; i < length - n; ++i) {
            current = current->next;
        } // reach the node before the node to be deleted
        ListNode* node_to_delete = current->next; // prevent memory leak?
        current->next = current->next->next;
        delete node_to_delete;

        ListNode* new_list = dummy->next;
        delete dummy;
        return new_list;
    }
};

// e.g. length = 5, n = 2
// --> delete the 4th node, whose index is length - n = 3.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Traverse and get the length
        ListNode* current = head;
        int length = 0;
        while (current != nullptr) {
            ++length;
            current = current->next;
        }
        
        // edge case: remove the head
        if (length == n) {
            ListNode* new_head = head->next;
            delete head;
            return new_head;
        }
        // general case:
        current = head;
        for (int i = 0; i < length - n - 1; i++) {
            current = current->next;
        }
        current->next = current->next->next;
        return head;
    }
};
