#include <bits/stdc++.h>
using namespace std;

int V = 500;

vector<vector<pair<int, int>>> graph(V); 
bool mstSet[500];
int parent[500];
int key[500];
void add_edge(int u, int v, int weight) {
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight});
}
//sudhu min key ta return kore
int minKey(int key[]) {
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST( int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++){
        int r=graph[i][parent[i]].second;
        cout << parent[i] << " - " <<i <<" ";
        cout<< r  << " \n";
       
        }
}

void primMST(int V) {

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;
//toot
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key);
        mstSet[u] = true;

        for (auto &neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!mstSet[v] && weight < key[v]) {//u jar sathe connected ->v se agei mst te ase kina and tar weight soto kina 
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    printMST( V);
}

int main() {
    
int n;
cin >> n;
int ed;
cin >> ed;

for(int i=0;i<ed;i++){
    int u,v,w;
    cin >> u >>v >> w;
    add_edge(u,v,w);
}
    // Convert the graph to adjacency list
    
    // Print the solution
    primMST(n);
    return 0;
}
