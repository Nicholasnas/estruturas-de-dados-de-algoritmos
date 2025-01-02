

"""Linked list"""
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
    
    
class LinkedList:
    def __init__(self) -> None:
        self.head = None  # lista comeca vazia
    
    def append(self, data):
        new_node = Node(data)
        
        if self.head == None: # lista vazia
            self.head = new_node
            return
        # caso a lista ja tenha mais de um nó
        current_node = self.head
        
        while current_node.next:
            current_node = current_node.next
        
        current_node.next = new_node
        return  
    
    def lenght(self):
        if self.head == None:
            return 0
        
        current_node = self.head
        total = 0   
        while current_node:
            total += 1
            current_node = current_node.next
        return total
    
    def print_list(self):
        if self.head == None:
            return 'List empty'
        
        current_node = self.head
        
        while current_node:
            print(current_node.data, end=' -> ')
            current_node = current_node.next
        print('Fim')
        
    def reverse_linkedlist(self):
        previous_node = None
        current_node = self.head
        
        while current_node != None:
            node_next = current_node.next
            current_node.next = previous_node
            previous_node = current_node
            current_node = node_next
        self.head = previous_node
    
    def get(self, index):
        if index >= self.lenght() or index < 0:
            print('Erro: Index out of range')
            return None
        
        current_index = 0
        current_node = self.head
        
        while current_node:
            if current_index == index:
                return current_node.data
            current_node = current_node.next
            current_index += 1
    
    def search_item(self, data):
        
        if self.head == None:
            print('List is empty.')
            return None
        
        current_node = self.head
        while current_node:
            if current_node.data == data:
                print(f'I Find the target {data}.')
                return data
            current_node = current_node.next
        
        print("Item not found")
        return False
    
    def remove_at_start(self):
        if self.head == None:
            print('List is empty.')
            return None
        
        self.head = self.head.next
    
    def remove_at_end(self):
        if self.head == None:
            print('List is empty.')
            return None

        current_node = self.head
        while current_node:
            current_node = current_node.next
        current_node.next = None 
    
    def insert_at_start(self, value):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node
    
    def insert_at_end(self, value):
        current_node = self.head
        
        while current_node:
            current_node = current_node.next
        
        current_node.next = Node(value)
    
    def remove_element_by_value(self, value):
        if self.head == None:
            print('List is empty.')
            return None
        
        current_node = self.head
        while current_node:
            if current_node.data == value:
                node_next = current_node.next
                
        


l1 = LinkedList()
l1.append(1)
l1.append(2)
l1.append(3)
l1.print_list()
print(l1.lenght())
