#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;


void primMST(vector<vector<pair<int, int>>>& graph, int startVertex) {
    int numVertices = graph.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> inMST(numVertices, false);

    int MSTWeight = 0;
    inMST[startVertex] = true;

    for (auto edge : graph[startVertex]) {
        pq.push({edge.second, edge.first});
    }

    // Repeat until the MST contains all vertices
    while (!pq.empty()) {
        pair<int, int> currentEdge = pq.top();
        pq.pop();

        int toVertex = currentEdge.second;
        int weight = currentEdge.first;

        // If the 'toVertex' is already in MST, skip this edge
        if (inMST[toVertex]) {
            continue;
        }

        // Include the 'toVertex' in MST
        inMST[toVertex] = true;
        MSTWeight += weight;

        // Add all adjacent edges of 'toVertex' to the priority queue
        for (pair<int, int> edge : graph[toVertex]) {
            if (!inMST[edge.first]) {
                pq.push(make_pair(edge.second, edge.first));
            }
        }
    }

    // Print the MST weight
    cout << "Minimum Spanning Tree Weight: " << MSTWeight << endl;
}

int main() {
    int numVertices, numEdges;
   
    cin >> numVertices >> numEdges;

    // Create a graph as an adjacency list of pairs (toVertex, weight)
    vector<vector<pair<int, int>>> graph(numVertices);

  
    for (int i = 0; i < numEdges; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back(make_pair(to, weight));
        graph[to].push_back(make_pair(from, weight));
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    // Find and print the MST using Prim's algorithm
    primMST(graph, startVertex);

    return 0;
}
