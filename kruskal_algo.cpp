#include <bits/stdc++.h>
using namespace std;
const int N=10000;
int parent[N];
int Rank[N];
void make(int i){
    parent[i]=i;
    Rank[i]++;
}
int find(int u){
    if(parent[u]==u) return u;
    else{
       return parent[u]=find(parent[u]);
    }
}
void Union(int u,int v){
    int a = find(u);
    int  b = find(v);
    if (a != b) {
        if (Rank[a] < Rank[b])
            swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b])
            Rank[a]++;
    }

}


int main(){
    vector<pair<int,pair<int,int>>> edge;
        vector<pair<int,pair<int,int>>> temp;

        // vector<pair<pair<int,int>,pair<bool,int>>> temp;

    int n,e;
    cin >> n >> e;
    vector<pair<int,int>> mst;
    int wcnt[N]={0};
    for(int i=0;i<e;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge.push_back({w,{u,v}});
        temp.push_back({w,{u,v}});
    }
    for(int i=1;i<=n;i++){
        make(i);
    }
    for(int i=0;i<n;i++){
        int w=temp[i].first;
        wcnt[w]++;

    }
    sort(edge.begin(),edge.end());
      for(int i=0;i<e;i++){
        int u,v,w;
        w=edge[i].first;
        u= edge[i].second.first;
        v=edge[i].second.second;
        if(find(u)==find(v)) {
            // if(wcnt[w]>0)
            // cout<<"At least one"<<endl;
            // else
            // cout<<"None"<<endl;

            continue;
            }
        else{
            Union(u,v);
            if(wcnt[w]>1) wcnt[w]+=1000;
            else
            wcnt[w]+=20;

         //   cout<<"Any"<<endl;
            mst.push_back({u,v});
        }
        
        //cout<<u<<" "<<v<<" "<<w<<endl;
    }
    for(int i=0;i<e;i++){
        int w=temp[i].first;
      //  cout<<w<<" ";
     //   cout<<wcnt[w]<<endl;
        if(wcnt[w]>1000) cout<<"at least one"<<endl;
        else if(wcnt[w]>=20&& wcnt[w]<1000) cout <<"any"<<endl;
        else
        cout<<"none"<<endl;
    }
    // for(int i=0;i<mst.size();i++) {
    //     cout<<mst[i].first<<" " << mst[i].second <<endl;
    // }

}