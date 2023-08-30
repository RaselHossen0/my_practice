#include<bits/stdc++.h>
using namespace std;
#define INF 100000
bool  bellMen(vector<pair<int,pair<int,int>>> &edges,vector<int> & dist, int n){
    dist[0]=0;
    int flag=0;
    for(int i=0;i<n-1;i++){
        int w=edges[i].first;
        int u=edges[i].second.first;
        int v=edges[i].second.second;
       // cout<<u<<" "<<v<<" "<<w<<endl;
        if(dist[u]+w<dist[v]){
            dist[v]=w+dist[u];
            flag=1;
        }
      if(flag==0) return false;

    }
    for(auto i:dist){
        if(i==INF) cout<<"inf"<<endl;
        else
        cout<<i<<" ";
    }
    return false;

}
int main(){
    int n,e;
    cin >> n >> e;
        vector<pair<int,pair<int,int>>> edges;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<e;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        edges.push_back({w,{u,v}});
       //   edges.push_back({w, {v, u}});

    }
    vector<int> dist(n,INF);
    bellMen(edges,dist,n);
    //cout<<edges.size()<<endl;
    
    


}