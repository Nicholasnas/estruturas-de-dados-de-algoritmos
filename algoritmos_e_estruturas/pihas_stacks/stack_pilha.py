

class Stack:
    def __init__(self) -> None:
        self.items = []
        
    def push(self, item):
        "Adds an item on the top of the stack"
        self.items.append(item)
        
    def pop(self):
        'Remove an item from the top of the stack and return the value of that item'
        if self.size() == 0:
            return None
        else:
            return self.items.pop()
        
    def size(self):
        "return the size of the stuct item"
        return len(self.items)
        
pilha1 = Stack()
pilha1.push(2)
pilha1.push(4)
pilha1.push(6)
print(pilha1.items)
pilha1.pop()
print(pilha1.items)