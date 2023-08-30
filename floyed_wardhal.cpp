#include <bits/stdc++.h>
using namespace std;
#define INF 10000000
int main()
{
    int N, M; 
    cin >> N >> M;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    vector<vector<int>> parent(N, vector<int>(N, -1));


    for (int i = 1; i <= M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
       // dist[v][u]= w;
        parent[u][v]=u;
    }
    int V = N;
for(int i=0;i<V;i++){
    for(int j=0;j<V;j++){
        if(i==j) dist[i][j]=0;
    }
}
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                 if (dist[i][k] < INF && dist[k][j] < INF)
                  dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    //  for (int i = 0; i < V; i++) {
    //     for (int j = i+1; j < V; j++) {   
    //         if (dist[i][j] == INF)
    //             cout << i<<" to "<<j<<": "<<"inf"<<endl;
    //         else
    //            cout << i<<" to "<<j<<": "<<dist[i][j]<<endl;
    //     }
     
    // }
     for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]==INF)
            cout<<"@"<<" ";
            else
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
