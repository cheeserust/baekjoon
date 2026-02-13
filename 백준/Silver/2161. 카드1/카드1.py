class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.cnt = 0
        
    def empty(self): 
        if self.head == None:
            return 1
        else:
            return 0
            
    def push(self, data):
            new_node = Node(data)
            if self.empty():
                self.head = self.tail = new_node
            else:
                current = new_node
                self.tail.next = current 
                self.tail = current
            self.cnt += 1
    
    def pop(self):
            if self.empty() == 1:
                self.tail = None
                self.cnt = 0
                return -1
            current = self.head
            self.head = current.next
            self.cnt -= 1
            return current.data
    def size(self):
            return self.cnt
    
    def front(self):
         return -1 if self.empty == 1 else self.head.data
        

n = int(input())
q = Queue()
for i in range(1,n+1):
    q.push(i)

while q.size() > 1:
    a = q.pop()
    print(a)
    top = q.pop()
    q.push(top)

print(q.front())