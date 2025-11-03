/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Floyd's Cycle Detection Algorithm
// O(n) time, O(1) space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* fast = head->next; // must be head->next!
        // e.g. single node [1]. slow is pointed to head, fast is nullptr, no cycle
        ListNode* slow = head;
        while (fast != slow) {
        if (fast == nullptr || fast->next == nullptr) return false;
        // e.g. ... → 1 → 2 → 3 → null.  no cycle
        // check conditions:
        // !fast: suppose fast pointer at 2. fast->next->next is null.
        // !fast->next: suppose fast pointer at 3. fast->next is null. fast->next->next will crash.
        fast = fast->next->next;
        slow = slow->next;
        }
        return true;
    }
};

// Track occurences
// O(n) time, O(n) space
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> seenNodes;
        ListNode* currentNode = head;
        while (currentNode != nullptr) {
            if (seenNodes.find(currentNode) != seenNodes.end()) {
                return true;
            }
            seenNodes.insert(currentNode);
            currentNode = currentNode->next;
        }
        return false;
    }
};