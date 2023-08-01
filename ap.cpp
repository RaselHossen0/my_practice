#include <bits/stdc++.h>
using namespace std;

 vector<vector<int>> graph(500);
vector<int> tin(100);
vector<int> low(100);
 bool visited[100];
int cnt=0;
 int d=0;
 void add_edge(int p,int v){
    graph[p].push_back(v);
    graph[v].push_back(p);
 }
void print_graph(){
    for (int p = 1; p <= graph.size(); p++) {
        cout  << p << ": ";
        for (int i = 0; i < graph[p].size(); i++) {
            cout << graph[p][i] << " ";
        }
        cout << endl;
    }
}
void dfs(int v,int p){
    d++;
    tin[v]=low[v]=d;

    visited[v]=true;
    int child=0;
    for(int u:graph[v]){
        child++;
        if(p==u) continue;

        if(!visited[u]){
        dfs(u,v);
        low[v]=min(low[v],low[u]);
        if(low[u]>=tin[v] && p!=-1){
            cnt++;
            cout<<v<<" Articulation point"<<endl;
        }
        }
        else{
            low[v]=min(low[v],tin[u]);
        }
    }
    // if(child>0 && p==-1)
    // cout<<v<<endl;
    //  cout<<v<<"->"<<d<<endl;
}
 int main(){
    while(1){
    int n;
    cin >> n;
    int edge;
    cin >> edge;
    for(int i=0;i<edge;i++){
        int u,v;
        cin >> u >> v;
        add_edge(u,v);
    }
   
   //  print_graph();

    for(int i=1;i<=n;i++){
        if(!visited[i])
        dfs(i,-1);
    }
    for(int i=0;i<100;i++) visited[i]=false;
  
    if(n==0 && edge==0)
    break;
    }
  cout<<cnt<<endl;
    cnt=0;

 }