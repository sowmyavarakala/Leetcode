class MovingAverage:

    def __init__(self, size: int):
        self.length = 0
        self.max = size
        self.queue = deque()
        self.sum = 0
        

    def next(self, val: int) -> float:
        if self.length < self.max:
            self.length += 1
            self.queue.append(val)
            self.sum += val
        else:
            self.sum -= self.queue.popleft()
            self.queue.append(val)
            self.sum += val
        return self.sum/self.length




# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)