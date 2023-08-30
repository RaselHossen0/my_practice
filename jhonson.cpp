#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

const int MAX_INT = numeric_limits<int>::max();

// Function to find the vertex with the minimum distance
int minDistance(const vector<int> &dist, const vector<bool> &visited) {
    int minimum = MAX_INT;
    int minVertex = 0;

    for (int vertex = 0; vertex < dist.size(); ++vertex) {
        if (!visited[vertex] && dist[vertex] < minimum) {
            minimum = dist[vertex];
            minVertex = vertex;
        }
    }

    return minVertex;
}

// Dijkstra Algorithm for Modified Graph (removing negative weights)
void Dijkstra(const vector<vector<int>> &graph, const vector<vector<int>> &modifiedGraph, int src, vector<vector<int>> &result) {
    int numVertices = graph.size();
    vector<bool> sptSet(numVertices, false);
    vector<int> dist(numVertices, MAX_INT);

    dist[src] = 0;

    for (int count = 0; count < numVertices; ++count) {
        int curVertex = minDistance(dist, sptSet);
        sptSet[curVertex] = true;

        for (int vertex = 0; vertex < numVertices; ++vertex) {
            if (!sptSet[vertex] && dist[vertex] > (dist[curVertex] + modifiedGraph[curVertex][vertex]) && graph[curVertex][vertex] != 0) {
                dist[vertex] = dist[curVertex] + modifiedGraph[curVertex][vertex];
            }
        }
    }

    // Store the shortest distances in the result matrix
    for (int vertex = 0; vertex < numVertices; ++vertex) {
        result[src][vertex] = dist[vertex];
    }
}

vector<int> BellmanFord(vector<vector<int>> &edges, const vector<vector<int>> &graph, int numVertices) {
    int source = numVertices;
    vector<int> dist(numVertices + 1, MAX_INT);
    dist[source] = 0;

    for (int i = 0; i < numVertices; ++i) {
        edges.push_back({source, i, 0});
    }

    for (int i = 0; i < numVertices; ++i) {
        for (const auto &edge : edges) {
            int src = edge[0];
            int des = edge[1];
            int weight = edge[2];

            if (dist[src] != MAX_INT && dist[src] + weight < dist[des]) {
                dist[des] = dist[src] + weight;
            }
        }
    }

    return vector<int>(dist.begin(), dist.begin() + numVertices);
}

void JohnsonAlgorithm(vector<vector<int>> &graph, vector<vector<int>> &result) {
    vector<vector<int>> edges;

    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    vector<int> modifyWeights = BellmanFord(edges, graph, graph.size());

    vector<vector<int>> modifiedGraph(graph.size(), vector<int>(graph[0].size(), 0));

    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            if (graph[i][j] != 0) {
                modifiedGraph[i][j] = graph[i][j] + modifyWeights[i] - modifyWeights[j];
            }
        }
    }

    cout << "Modified Graph: " << endl;
    for (const auto &row : modifiedGraph) {
        for (int weight : row) {
            cout << weight << " ";
        }
        cout << endl;
    }

    // Run Dijkstra for every vertex as source one by one
    for (int src = 0; src < graph.size(); ++src) {
      //  cout << "\nShortest Distance with vertex " << src << " as the source:" << endl;
        Dijkstra(graph, modifiedGraph, src, result);
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    } // 0   1  2  3

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>> result(n, vector<int>(n, MAX_INT));
    
    JohnsonAlgorithm(graph, result);

    // Output the result matrix
    cout << "\nResult Matrix:" << endl;
    for (const auto &row : result) {
        for (int distance : row) {
            if(distance==MAX_INT)
            cout<<"@"<<" ";
            else
            cout << distance << " ";
        }
        cout << endl;
    }

    return 0;
}
