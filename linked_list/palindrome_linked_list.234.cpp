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


// Two pointers
// O(n) time, O(1) space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        } // stop in the middle
        ListNode* reversedSecondHalf = reverseLinkedList(slow->next);

        ListNode* firstHalf = head;
        while (reversedSecondHalf != nullptr) {
            if (firstHalf->val != reversedSecondHalf->val) return false;
            firstHalf = firstHalf->next;
            reversedSecondHalf = reversedSecondHalf->next;
        }
        return true;
    }
private:
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

};


// Turn the linked list to an array
// O(n) time, O(n) space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        std::vector<int> v;
        while (curr != nullptr) {
            v.push_back(curr->val);
            curr = curr->next;
        }

        int start = 0;
        int end = v.size() - 1;
        while (start < end) {
            if (v[start] != v[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};