#include<bits/stdc++.h>
using namespace std;
#define INF 100000
void dijkastra(vector<vector<pair<int,int>>> &graph,int n,vector<int> &dist,int src,vector<bool> &vis){
    dist[src]=0;
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    pq.push({0,src});
    vis[src]=true;
    while(!pq.empty()){
        int w=pq.top().first;
        int v=pq.top().second;
        pq.pop();
        vis[v]=true;
        for(auto to:graph[v]){
            int u=to.first;
            int weight=to.second;
            if(!vis[u] && dist[v] + weight < dist[u]) {
                dist[u] = dist[v] + weight;
                pq.push({dist[u], u});
            }
        }
    }
   for(auto i : dist) {
        if(i == INF) cout << "inf" << endl;
        else cout << i << " ";
    }
}
int main(){
    int n,e;
    cin>> n>> e;
    vector<vector<pair<int,int>>> gr(n);
    for(int i=0;i<e;i++){
        int u,v,w;
        cin  >> u >> v >> w;
        gr[u].push_back({v,w});
       // gr[v].push_back({u,w});
    }
    vector<int> dist(n,INF);
    vector<bool> vis(n,false);
    dijkastra(gr,n,dist,0,vis);
    

}