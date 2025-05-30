# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteNodes(self, head, m, n):
        """
        :type head: Optional[ListNode]
        :type m: int
        :type n: int
        :rtype: Optional[ListNode]
        """

        current = head
        while current:
            for i in range(1,m):
                if current is None:
                    return head
                current = current.next

            if current is None:
                break

            temp = current.next
            for i in range(n):
                if temp is None:
                    break
                temp = temp.next

            current.next = temp
            current = temp
        return head