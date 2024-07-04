
"""Stack using linked list"""

class Node:
    def __init__(self,data):
        self.data = data
        self.next = None
        
class StackLinked:
    def __init__(self) -> None:
        self.head = None
    
    def push(self, data):
        new_node = Node(data)
        
        """Verificar se a pulha é vazia, caso seja adiciona no head da stack"""
        if not self.head:
            self.head = new_node
            print('Add in start')
            return
            
        new_node.next = self.head
        self.head = new_node
        return 

    def pop(self):
        if not self.head:
            print('Stack empty')
            return
        
        head = self.head.next
        self.head = head
        
        return 
    
    def peek(self):
        """Return the rop element"""
        if not self.head:
            print('Stack empty')
            return
        
        print(self.head.data)
        
    def show(self):
        if not self.head:
            print('Stack Empty')
            return 
        current_node = self.head
        
        while current_node:
            print(current_node.data, end=' -> ')
            current_node = current_node.next
        print('End')
        
    def length(self):
        if not self.head:
            print('Stack Empty')
            return
        current_node = self.head
        contador = 0
        while current_node:
            contador += 1
            current_node = current_node.next
        
        print(contador)

        
s1 = StackLinked()
s2 = StackLinked()

# s1
s1.push(2)
s1.push(4)
s1.push(6)
s1.push(8)
s1.push(10)
# s2
s2.push(1)
s2.push(3)
s2.push(5)
s2.push(7)
s2.push(9)

# tamanho 
print('tamanho')
s1.length()
s2.length()

s1.show()
s2.show()
# peek topo
print('head of stacks')
s1.peek()
s2.peek()

s1.pop()
s2.pop()

s1.show()
s2.show()

print('head of stacks')
s1.peek()
s2.peek()
# tamanho 
print('tamanho')
s1.length()
s2.length()

s1.pop()
s1.pop()
s1.pop()
s2.pop()
s2.pop()
s2.pop()


s1.show()
s2.show()
s1.pop()
s2.pop()
s1.show()
s2.show()
# tamanho 
s1.length()
s2.length()