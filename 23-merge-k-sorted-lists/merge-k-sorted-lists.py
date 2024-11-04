# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        min_heap = []

    # Push the first node of each list into the heap (if not empty)
        for i, lst in enumerate(lists):
            if lst:
                heapq.heappush(min_heap, (lst.val, i, lst))

        # Dummy node to act as the head of the merged list
        dummy = ListNode(0)
        current = dummy

        # Extract the minimum element from the heap and add to the merged list
        while min_heap:
            val, idx, node = heapq.heappop(min_heap)
            current.next = ListNode(val)
            current = current.next
            # If the list from which this node came has more nodes, add the next node to the heap
            if node.next:
                heapq.heappush(min_heap, (node.next.val, idx, node.next))

        # Return the merged linked list (skipping the dummy head)
        return dummy.next
        