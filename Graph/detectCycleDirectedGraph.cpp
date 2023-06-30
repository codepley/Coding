#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
   adj[u].push_back(v);
   // adj[v].push_back(u);
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

bool dfsRec(vector<int> adj[], vector<bool>& vis, int s, vector<bool>& recSt){
   vis[s] = 1;
   recSt[s] = 1;
   for(auto u: adj[s]){
      if(!vis[u] && dfsRec(adj, vis, u, recSt)){
         return true;
      }else if(recSt[u] == true){
         return true;
      }
   }
   recSt[s] = false;
   return false;
}

bool detectCycle(vector<int> adj[], int V){
   vector<bool> vis(V, 0);
   vector<bool> recSt(V, 0);
   for(int i=0; i<V; i++){
      if(!vis[i]){
         if(dfsRec(adj, vis, i, recSt) == true){
            return true;
         }
      }
   }
   return false;
}

int main() {
   int V = 6;
   vector<int> adj[V];
   // addEdge(adj, 0, 1);
   // addEdge(adj, 1, 2);
   // addEdge(adj, 1, 3);
   // addEdge(adj, 2, 5);
   // addEdge(adj, 3, 4);
   // addEdge(adj, 3, 5);
   // addEdge(adj, 3, 6);
   addEdge(adj, 0, 1);
   addEdge(adj, 1, 2);
   addEdge(adj, 2, 3);
   // addEdge(adj, 3, 1);


   bool ans = detectCycle(adj, V);
   if(ans){
      cout << "Cycle Found" << endl;
   }else{
      cout << "Cycle Not Found" << endl;
   }
   // printGraph(adj, V);

   return 0;
}