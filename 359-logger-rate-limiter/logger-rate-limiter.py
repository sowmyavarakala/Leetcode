class Logger:

    def __init__(self):
        self.store = {}
        

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if timestamp < self.store.get(message, 0):
            return False
        self.store[message] = timestamp + 10
        return True
        


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)