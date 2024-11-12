class MyStack:

    def __init__(self):
        self.store = []

    def push(self, x: int) -> None:
        self.store.append(x)

    def pop(self) -> int:
        x = self.store[-1]
        self.store = self.store[:-1]
        return x

    def top(self) -> int:
        return self.store[-1]

    def empty(self) -> bool:
        return True if len(self.store) == 0 else False


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()