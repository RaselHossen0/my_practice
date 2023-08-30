class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        
        if root_x == root_y:
            return
        
        if self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        else:
            self.parent[root_x] = root_y
            if self.rank[root_x] == self.rank[root_y]:
                self.rank[root_y] += 1

def kruskal_max_spanning_tree(n, edges):
    edges.sort(key=lambda edge: -edge[2])  # Sort edges in descending order of weight
    
    dsu = DisjointSet(n)
    max_spanning_tree_weight = 0
    
    for u, v, w in edges:
        if dsu.find(u) != dsu.find(v):
            dsu.union(u, v)
            max_spanning_tree_weight += w
    
    return max_spanning_tree_weight

# Input reading
n = int(input())
m = int(input())
edges = []
for _ in range(m):
    u, v, w = map(int, input().split())
    edges.append((u, v, w))

# Find and print the weight of the maximum spanning tree
max_spanning_tree_weight = kruskal_max_spanning_tree(n, edges)
print(max_spanning_tree_weight)
