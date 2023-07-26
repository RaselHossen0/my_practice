class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None

    def append(self, data):
        new_node = Node(data)
        if self.is_empty():
            self.head = new_node
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = new_node

    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def delete(self, data):
        if self.is_empty():
            return

        if self.head.data == data:
            self.head = self.head.next
            return

        current = self.head
        while current.next is not None:
            if current.next.data == data:
                current.next = current.next.next
                return
            current = current.next

    def display(self):
        current = self.head
        while current is not None:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

linked_list = LinkedList()
graph = {}
Graph = {}


vertices = {}
time =0
class Vertex:
    def __init__(self, val):
        self.val = val
        self.color = 'white'
        self.d = 0
        self.f = 0
        self.pa = None

    def __str__(self):
        return str(self.val)

def create_vertex(val):
    if val in vertices:
        return vertices[val]
    else:
        v = Vertex(val)
        vertices[val] = v
        return v

def create_graph(nodes):
    global graph, Graph
    for i in nodes:
        v = create_vertex(i)
        # print(i,end='gr')
        graph[i] = []
        Graph[v] = []
       

def add_edge(u, v,Graph):

    p = create_vertex(u)
    c = create_vertex(v)

    if u not in graph:
        graph[u] = []
    if p not in Graph:
        Graph[p] = []
   
    Graph[p].append(c)
    graph[u].append(v)
    

create_graph([1, 2, 3, 4,5,6,7,8])


add_edge(1, 2, Graph=Graph)
add_edge(2, 3, Graph=Graph)
# add_edge(3, 4, Graph=Graph)
add_edge(4, 3, Graph=Graph)
# add_edge(4, 8, Graph=Graph)
# add_edge(2, 5, Graph=Graph)
add_edge(5, 4, Graph=Graph)
add_edge(5, 6, Graph=Graph)
add_edge(7, 5, Graph=Graph)
add_edge(7, 6, Graph=Graph)
add_edge(8, 6, Graph=Graph)
add_edge(7, 6, Graph=Graph)
# add_edge(7, 8, Graph=Graph)
add_edge(9, 9, Graph=Graph)




def dfs(Graph):
    time=0
    for v in Graph:
        if v.color == 'white':
            DFS_visit(v,time)
def DFS_visit(u,time):
    global linked_list
    time+=1
    u.d=time
    u.color='grey'
    val=u.val
    print(u.val)
    real_vertex=vertices[val]
    for v in Graph[real_vertex]:
        if v.color=='white':
            DFS_visit(v,time)
    u.color='black'
    time+=1
    u.f=time
    linked_list.prepend(u.val)
    
    

dfs(Graph)



linked_list.display()
