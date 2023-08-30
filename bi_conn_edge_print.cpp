#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
vector<int> adj[N];
map<pair<int,int> ,int> mp;
int dfn[N], low[N], parent[N], timeStamp;
stack<pair<int,int>> S;
set<set<pair<int,int>>> components;
vector<pair<int,int>> edges;

void dfs(int u) {
  dfn[u] = low[u] = ++timeStamp;
  

  for (int v : adj[u]) {
   
    if (dfn[v] == 0) {
     
      
      S.push({u,v});
      parent[v] = u;
      dfs(v);
      low[u] = min(low[u], low[v]);
      if (low[v] >= dfn[u]) {
        set<pair<int,int>> component;
        pair<int,int> w = {-1,-1}; 
     
        while (w.first != u||w.second!=v) {
            
          w = S.top();
          S.pop();
       
          if(!mp[{min(w.first,w.second),max(w.first,w.second)}])
           component.insert({min(w.first,w.second),max(w.first,w.second)}) ,mp[{min(w.first,w.second),max(w.first,w.second)}]++ ;
        }
         if(!mp[{min(w.first,w.second),max(w.first,w.second)}])
         component.insert({w.first,w.second}),
         mp[{min(w.first,w.second),max(w.first,w.second)}]++;
    //  component.push_back({S.top().first,S.top().second});
        //    component.push_back({u,v});
    //    S.pop();
        components.insert(component);
      }
    } else if (v != parent[u] && dfn[v] < dfn[u]) {
         S.push({v,u});
      low[u] = min(low[u], dfn[v]);
    }
   
  }
}

int main() {
  edges.clear();
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (dfn[i] == 0) {
      dfs(i);
    }
  }

int siz=components.size();
int cn=0;
  for(auto pr:components){
    cn++;
    for(auto p:pr){
        set<pair<int,int>> st;
        cout<<p.first<<" "<<p.second<<endl;
    }
    if(cn<siz)
    cout<<'-'<<endl;
  }

  return 0;
}