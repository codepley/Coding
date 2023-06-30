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

bool dfsRec(vector<int> adj[], vector<bool>& vis, int s, int parent){
   vis[s] = 1;
   for(auto u: adj[s]){
      if(vis[u] && u != parent){
         return true;
      }else{
         if(!vis[u])
            dfsRec(adj, vis, u, s);
      }
   }
   return false;
}

bool detectCycle(vector<int> adj[], int V){
   vector<bool> vis(V, 0);
   for(int i=0; i<V; i++){
      if(!vis[i]){
         if(dfsRec(adj, vis, i, -1) == true){
            return true;
         }
      }
   }
   return false;
}

int main() {
   int V = 6;
   vector<int> adj[V];
   addEdge(adj, 0, 1);
   addEdge(adj, 1, 2);
   addEdge(adj, 2, 3);
   addEdge(adj, 3, 4);
   addEdge(adj, 4, 5);
   addEdge(adj, 5, 6);

   bool ans = detectCycle(adj, V);
   if(ans){
      cout << "Cycle Found" << endl;
   }else{
      cout << "Cycle Not Found" << endl;
   }

   return 0;
}