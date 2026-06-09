# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# Dummy node 解决的不是"链表"问题，而是"前驱节点不存在"的问题。
# O(l) time
# O(1) space
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # length
        l = 0
        curr = head
        while curr:
            l += 1
            curr = curr.next
        dummy = ListNode(-1)
        dummy.next = head
        curr = dummy
        i = 0
        while i < l-n:
            curr = curr.next
            i += 1
        # IMPORTANT: need to stop at the node before the node to be deleted
        curr.next = curr.next.next
        return dummy.next

# Two pointers
def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
    dummy = ListNode(-1)
    dummy.next = head
    fast = slow = dummy

    # fast 先走 n+1 步
    for _ in range(n + 1):
        fast = fast.next

    # 同步前进直到 fast 到尾
    while fast:
        fast = fast.next
        slow = slow.next

    # slow 此时在待删节点的前驱
    slow.next = slow.next.next
    return dummy.next