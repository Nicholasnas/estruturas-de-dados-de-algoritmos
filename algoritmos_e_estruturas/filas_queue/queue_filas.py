
class Queue:
    def __init__(self) -> None:
        self.items = []
        
    def enqueue(self, item):
        self.items.append(item)
    
    def dequeue(self):
        self.items.pop(0)
    
    
        