#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
   adj[u].push_back(v);
   adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V) {
   for(int i=0; i<V; i++){
      cout << i << "->";
      for(auto u: adj[i]){
         cout << u << " ";
      }
      cout << endl;
   }
}

vector<int> shortestPath(vector<int> adj[], int V, int s){
   vector<int> dist(V+1, INFINITY);
   vector<bool> vis(V+1);
   queue<int> q;
   q.push(s);
   dist[s] = 0;
   vis[s] = 1;
   while(!q.empty()){
      int p = q.front();
      q.pop();
      for(auto u: adj[p]){
         if(!vis[u]){
            vis[u] = 1;
            dist[u] = dist[p] + 1;
            q.push(u);
         }
      }
   }
   return dist;
}

int main() {
   int V = 6;
   vector<int> adj[V+1];
   addEdge(adj, 0, 1);
   addEdge(adj, 1, 2);
   addEdge(adj, 1, 3);
   addEdge(adj, 2, 5);
   addEdge(adj, 3, 4);
   addEdge(adj, 3, 5);
   addEdge(adj, 3, 6);

   // printGraph(adj, V);
   // dfs(adj, V);
   int source = 5;
   vector<int> dist = shortestPath(adj, V, source);
   cout << "Shortest distance from vertex " << source << " to other vertex are->";
   for(auto u: dist){
      cout << u << " ";
   }cout << endl;
   return 0;
}