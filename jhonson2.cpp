#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int MAX = 1000;

struct edge {
    int u, v;
    long long w;
    edge() {}
    edge(int u, int v, long long w) : u(u), v(v), w(w) {}

    void print() {
        cout << "edge " << u << " " << v << " " << w << endl;
    }
};

bool bellman_ford(int n, int src, vector<struct edge>& E, vector<vector<long long>>& dis) {
    dis[src][src] = 0;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (auto e : E) {
            if (dis[src][e.u] + e.w < dis[src][e.v]) {
                flag = 1;
                dis[src][e.v] = dis[src][e.u] + e.w;
            }
        }
        if (flag == 0) return true;
    }
    return false;
}

vector<long long> dijkstra(int n, int src, vector<struct edge>& E, vector<vector<long long>>& potential) {
    set<pair<long long, int>> S;
    vector<long long> dis(n, INF);
    vector<long long> temp(n, INF);
    vector<pair<int, long long>> adj[n];

    dis[src] = temp[src] = 0;
    S.insert(make_pair(temp[src], src));
    for (auto e : E) {
        adj[e.u].push_back(make_pair(e.v, e.w));
    }

    while (!S.empty()) {
        pair<long long, int> cur = *(S.begin());
        S.erase(cur);

        int u = cur.second;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            long long w = adj[u][i].second;

            if (temp[u] + w < temp[v]) {
                S.erase(make_pair(temp[v], v));
                temp[v] = temp[u] + w;
                dis[v] = dis[u] + w;
                S.insert(make_pair(temp[v], v));
            }
        }
    }
    return dis;
}

void johnson(int n, vector<vector<long long>>& ar, vector<struct edge> E) {
    vector<vector<long long>> potential(n, vector<long long>(n, INF));
    for (int i = 0; i < n; i++) E.push_back(edge(n, i, 0));

    for (int i = 0; i < n; i++) {
        vector<long long> dis = dijkstra(n, i, E, potential);
        for (int j = 0; j < n; j++) {
            ar[i][j] = dis[j];
        }
    }
}

int main() {
    vector<struct edge> E;
    int N, M;
    cin >> N >> M;

    vector<vector<long long>> ar(N, vector<long long>(N, INF));

    for (int i = 0; i < M; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        E.push_back(edge(u, v, w)); // Subtract 1 from u and v for 0-based indexing
    }

    int n = N;
    for (int i = 0; i < n; i++) {
        if (!bellman_ford(n, i, E, ar)) {
            cout << "Negative cycle detected!" << endl;
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ar[i][j] == INF)
                cout << "@" << " ";
            else
                cout << ar[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
