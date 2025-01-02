
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
    
class Queue:
    def __init__(self) -> None:
        self.head = None
        self.tail = None  # cauda
        self.num_elements = 0
        
    def enqueue(self, data):
        new_node = Node(data)
        if not self.head:  # queue empty
            self.head = new_node
            self.tail = self.head
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.num_elements += 1
    
    def dequeue(self):
        if not self.head:
            print('Queue Empty')
            return
        
        self.head = self.head.next
        self.num_elements -= 1
    
    def show(self):
        if not self.head:
            print('Queue Empty')
            return
        
        current_node = self.head
        
        while current_node:
            print(current_node.data, end=' -> ')
            current_node = current_node.next
        
        print('End!')
    def size(self):
        return self.num_elements
        
        
            

f1 = Queue()
f1.enqueue(2)
f1.enqueue(4)
print('show')
f1.show()
print('Tamanho')
print(f1.size())
f1.enqueue(6)
f1.enqueue(8)
print('show')
f1.show()
print('Tamanho')
print(f1.size())

f1.dequeue()
f1.show()
f1.dequeue()
f1.dequeue()
f1.dequeue()
f1.show()