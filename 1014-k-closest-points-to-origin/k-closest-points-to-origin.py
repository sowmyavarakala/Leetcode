class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []

        for point in points:
            dist = -(point[0] * point[0] + point[1] * point[1])
            if len(heap) == k:
                heapq.heappushpop(heap, (dist, point[0], point[1]))
            else:
                heapq.heappush(heap,(dist, point[0], point[1]))
        
        return [(x,y) for (dist, x, y) in heap]

        