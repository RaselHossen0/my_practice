#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=5000;
vector<pair<int, int> >  adj_list[N];  

vector<bool> visited(N,false);  
vector<int> mst(N,-1);  
vector<int> value(N, INT_MAX); 
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que; 

void prims() {
    que.push(make_pair(0, 1)); 
    value[1]=0;                
    while (!que.empty()) {      
        int node = que.top().second; 
        visited[node] = true;        
        que.pop();                    
        for (auto neighbor : adj_list[node]) {  
            int weight = neighbor.second;        //get their weight
            int vertex = neighbor.first;         //get their index

            if (!visited[vertex] && value[vertex] > weight) {   //if the node is not visited and if its weight along this edge is less than the 
                value[vertex] = weight;                         //previous edge associated with it, then only we consider it
                mst[vertex] = node;
                que.push(make_pair(value[vertex], vertex));     //we update the values and then push it in the queue to examine its neighbors
            }
        }
    }
}

void print_graph() {
    for (int i = 2; i < N; ++i)
        printf("%d - %d\n", mst[i], i);  //print the connections
}

void makegraph(int m, int n, int wght) {

    /* This function adds the edges and nodes to
      the graph in the form of an adjacency list */
    adj_list[m].push_back(make_pair(n, wght));     //make a pair of the node and its weight
    adj_list[n].push_back(make_pair(m, wght));     //we need to add it both ways i.e if a connects b, then b also connects a
}

int main() {
    makegraph(5, 4, 5);   //insert the node and edge
    makegraph(5, 1, 3);   //insert the node and edge
    makegraph(1, 2, 3);   //insert the node and edge
    makegraph(1, 4, 7);   //insert the node and edge
    makegraph(2, 5, 11);  //insert the node and edge
    makegraph(6, 4, 1);   //insert the node and edge
    makegraph(5, 6, 7);   //insert the node and edge
    makegraph(3, 1, 3);   //insert the node and edge
    makegraph(3, 2, 7);   //insert the node and edge

    prims();              //call the function the perform the minimum spanning tree algorithm
    print_graph();        //print the final minimum spanning tree

    return 0;
}