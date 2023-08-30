#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_NODES = 100000;

vector<int> graph[MAX_NODES];
bool visited[MAX_NODES];
int parent[MAX_NODES];
int disc[MAX_NODES];
int low[MAX_NODES];
int timeValue = 0;
vector<pair<int, int>> bridges;

void dfs(int node) {
    visited[node] = true;
    disc[node] = low[node] = ++timeValue;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            parent[neighbor] = node;
            dfs(neighbor);
            low[node] = min(low[node], low[neighbor]);
            if (low[neighbor] > disc[node]) {
                int smaller = min(node, neighbor);
                int larger = max(node, neighbor);
                bridges.emplace_back(smaller, larger);
            }
        } else if (neighbor != parent[node]) {
            low[node] = min(low[node], disc[neighbor]);
        }
    }
}

void findBridges(int n) {
    timeValue = 0;
    bridges.clear();
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
        parent[i] = -1;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    sort(bridges.begin(), bridges.end());
    for (const auto& bridge : bridges) {
        cout << bridge.first << bridge.second << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    findBridges(n);

    return 0;
}
