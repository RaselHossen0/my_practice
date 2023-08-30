#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> gr(10000);
vector<bool> visited(10000);
vector<int> dis(10000);
vector<int> parent(10000);  // Store the parent of each vertex in the shortest path

int minimumDist(int n) {
    int min = INT_MAX, index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dis[i] <= min) {
            min = dis[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int n, e;
    cin >> n >> e;

    gr.resize(n + 1);
    visited.assign(n + 1, false);
    dis.assign(n + 1, INT_MAX);

    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        gr[u].push_back({w, v});
        gr[v].push_back({w, u});
    }

    dis[1] = 0;

    for (int i = 1; i <= n; i++) {
        int mn = minimumDist(n);
        visited[mn] = true;

        for (auto u : gr[mn]) {
            int w = u.first;
            int to = u.second;
            if (!visited[to] && (w + dis[mn]) < dis[to]) {
                dis[to] = w + dis[mn];
                parent[to] = mn; 
            }
        }
    }

    vector<int> path;
    int current = n;
    while (current != 1) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

  
    for (int u : path) {
        cout << u << " ";
    }
    cout << endl;

  

    return 0;
}
