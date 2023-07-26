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

def add_edge(u, v):
    global graph, Graph
    p = create_vertex(u)
    c = create_vertex(v)

    if u not in graph:
        graph[u] = []
    if p not in Graph:
        Graph[p] = []
    Graph[p].append(c)
    graph[u].append(v)

create_graph([1, 2, 3, 4,5,6,7,8])

add_edge(2, 3)
add_edge(1, 2)
add_edge(4, 5)
add_edge(3, 4)
add_edge(3,6)
add_edge(1, 3)
add_edge(7, 8)
# print(vertices)
# print(graph)
# print(Graph)
# print(vertex(7)
# print(Graph[Vertex(2)])
def dfs(Graph):
    for v in Graph:
      #  print(v,end='* \n')
        if v.color == 'white':
            DFS_visit(v)
def DFS_visit(u):
    global time
    time+=1
    u.d=time
    u.color='grey'
    val=u.val
    print(u.val)
    real_vertex=vertices[val]
    # print(Graph[real_vertex])
    for v in Graph[real_vertex]:
      #  print(v,end='% ')
        if v.color=='white':
            # print('@',end=' ')
            DFS_visit(v)
    u.color='black'
    time+=1
    u.f=time
    
    
    

dfs(Graph)

# for v in Graph:
#     vs=Graph[v]
#     for u in vs:
#         print(u.val,end=" Node< ")
#         print(u.f,end=" ")