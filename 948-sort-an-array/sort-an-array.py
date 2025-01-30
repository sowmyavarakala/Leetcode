from typing import List

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def heapify(n, i):
            largest = i  # Assume the root (nums[i]) is the largest
            left = 2 * i + 1  # Left child
            right = 2 * i + 2  # Right child

            # If left child is greater than root
            if left < n and nums[left] > nums[largest]:
                largest = left

            # If right child is greater than the largest so far
            if right < n and nums[right] > nums[largest]:
                largest = right

            # If the largest is not the root, swap and continue heapifying
            if largest != i:
                nums[i], nums[largest] = nums[largest], nums[i]
                heapify(n, largest)

        n = len(nums)

        # Step 1: Build a Max Heap (Heapify the array)
        for i in range(n // 2 - 1, -1, -1):
            heapify(n, i)

        # Step 2: Extract elements from heap one by one
        for i in range(n - 1, 0, -1):
            nums[i], nums[0] = nums[0], nums[i]  # Swap max to the end
            heapify(i, 0)  # Restore heap property

        return nums

# GPT
