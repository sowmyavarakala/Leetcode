from collections import deque

class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        circle = deque(range(1, n + 1))
    
        current_position = 0
        
        while len(circle) > 1:
            current_position = (current_position + k - 1) % len(circle)
            circle.remove(circle[current_position])
        
        return circle[0]

        