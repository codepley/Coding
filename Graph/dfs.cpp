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

void dfsTraverse(vector<int> adj[], vector<bool>& vis, int s){
   vis[s] = 1;
   cout << s << " ";
   for(auto u: adj[s]){
      if(!vis[u]){
         dfsTraverse(adj, vis, u);
      }
   }
}

void dfs(vector<int> adj[], int V){
   vector<bool> vis(V+1);
   for(int i=0; i<V; i++){
      if(!vis[i]){
         vis[i] = 1;
         dfsTraverse(adj, vis, i);
      }
   }
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
   dfs(adj, V);
   return 0;
}