class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = defaultdict(int)
        for num in nums:
            count[num] += 1
        
        min_heap = []
        for num, freq in count.items():
            heappush(min_heap, (freq, num))
            if len(min_heap)>k:
                heappop(min_heap)
        
        return [ heappop(min_heap)[1] for _ in range(len(min_heap)) ]
        