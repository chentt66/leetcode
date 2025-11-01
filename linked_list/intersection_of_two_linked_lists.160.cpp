/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Two pointers
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA; // make a copy
        ListNode* pB = headB;
        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }
        return pA;
    }
};

// Set?
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::set<ListNode*> nodesA;
        while (headA != nullptr) {
            nodesA.insert(headA);
            headA = headA->next;
        }
        while (headB != nullptr) {
            if (nodesA.find(headB) != nodesA.end()) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};