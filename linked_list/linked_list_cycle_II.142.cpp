// Floyd's Tortoise and Hare algorithm
// O(n) time, O(1) space



// Hash set
// O(n) time, O(n) space
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        std::unordered_set<ListNode*> nodeSet; //node pointer set
        while (head != nullptr) {
            if (nodeSet.find(head) != nodeSet.end()) {
                return head;
            } else {
                nodeSet.insert(head);
            }
            head = head->next;
        }
        return nullptr;
        
    }
};

