# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy_node = ListNode(0)
        current = dummy_node # python is always referencing
        carry = 0
        while l1 or l2 or carry != 0:
            val1 = 0 if not l1 else l1.val
            val2 = 0 if not l2 else l2.val
            val_sum = val1 + val2 + carry
            # note the quotient and remainder
            digit = val_sum % 10
            carry = val_sum // 10
            current.next = ListNode(val = digit)
            current = current.next
            if l1 is not None:
                l1 = l1.next
            if l2 is not None:
                l2 = l2.next
        return dummy_node.next