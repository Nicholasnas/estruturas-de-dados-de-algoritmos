from collections import deque


stack = deque()

stack.append(2)
stack.append(4)
stack.append(6)
stack.append(8)

print(stack)
stack.pop()
print(stack)

