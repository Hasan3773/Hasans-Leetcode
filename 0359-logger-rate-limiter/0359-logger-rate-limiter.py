class Logger(object):

    def __init__(self):
        self.messageMap = {}

    def shouldPrintMessage(self, timestamp, message):
        """
        :type timestamp: int
        :type message: str
        :rtype: bool
        """
        if message in self.messageMap:
            if timestamp - self.messageMap[message] >= 10:
                print(self.messageMap, timestamp - self.messageMap[message])
                self.messageMap[message] = timestamp
                return True
            else:
                print(self.messageMap)
                return False
        else:
            self.messageMap[message] = timestamp
            print(self.messageMap)
            return True
            # 10 at 5 and now its 16
            # 16- 5 > 10

    
# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)