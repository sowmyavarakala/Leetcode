class Solution:
    def leastInterval(self,tasks, n):
        # Step 1: Count the frequency of each task
        task_counts = Counter(tasks)
        
        # Step 2: Create a max-heap with negative frequencies
        max_heap = [-count for count in task_counts.values()]
        heapq.heapify(max_heap)
        
        # Step 3: Use a queue to manage cooldowns
        cooling_queue = []
        time = 0
        
        # Step 4: Simulate time intervals
        while max_heap or cooling_queue:
            time += 1
            
            if max_heap:
                # Execute the task with the highest frequency
                freq = heapq.heappop(max_heap) + 1  # Increase because it was negative
                if freq:  # If there are remaining instances of this task
                    cooling_queue.append((freq, time + n))
            
            # Check if any task has completed its cooldown
            if cooling_queue and cooling_queue[0][1] == time:
                heapq.heappush(max_heap, cooling_queue.pop(0)[0])
        
        return time

            
            