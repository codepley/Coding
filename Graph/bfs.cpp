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

void bfs(vector<int> adj[], int V){
   vector<bool> vis(V+1, 0);
   queue<int> q;
   q.push(0);
   vis[0] = 1;
   while(!q.empty()){
      int p = q.front();
      q.pop();
      cout << p << " ";
      for(auto u: adj[p]){
         if(!vis[u]){
            vis[u] = 1;
            q.push(u);
         }
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
   bfs(adj, V);
   return 0;
}