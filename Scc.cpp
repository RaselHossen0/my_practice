#include <bits/stdc++.h>
using namespace std;

 vector<vector<int>> graph(500);
vector<int> tin(100);
vector<int> low(100);
stack <int> ftim;
 bool visited[100];

 int d=0;
 int f=0;
 void add_edge(int p,int v){
    graph[p].push_back(v);
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
void dfs(int v){
    d++;
    visited[v]=true;
    // cout<<v<<endl;
    for(int u:graph[v])
        if(!visited[u]){
        dfs(u);
    }
    ftim.push(v);
}
void dfs2(int v){
    visited[v]=true;
    // cout<<v<<endl;
    for(int u:graph[v]){
        if(!visited[u]){
        dfs2(u);   
    }
    }
   
}
void reversGraph(){
    vector<vector<int>> temp=graph;
    graph.clear();
    graph.resize(temp.size()); 
    for(int p=0;p<temp.size();p++){
        for(int v=0;v<temp[p].size();v++){
            graph[v].push_back(p);
        }
    }
}
void scc(int n){
     for(int i=1;i<=n;i++){
        if(!visited[i])
        dfs(i);
    }
    reversGraph();
    for(int i=1;i<=n;i++){
        visited[i]=false;
    }
    
    while(!ftim.empty()){
        int node=ftim.top();
        ftim.pop();
         cout<<node<<" ";
        if(!visited[node]){
            dfs2(node);
        }
        
        else{
            cout<<endl;
        }

    }

}

 int main(){
    int n;
    cin >> n;
    int edge;
    cin >> edge;
    for(int i=0;i<edge;i++){
        int u,v;
        cin >> u >> v;
        add_edge(u,v);
    }
    scc(n);
   
   //  print_graph();

   


 }