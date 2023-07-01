#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
   adj[u].push_back(v);
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

void dfs(vector<int> adj[], vector<bool>& vis, stack<int>& st, int s){
   vis[s] = 1;
   for(auto u: adj[s]){
      if(!vis[u]){
         dfs(adj, vis, st, u);
      }
   }
   st.push(s);
   cout << "Pushed " << s << " in the stack\n";
}

void topologicalDFS(vector<int> adj[], int V){
   stack<int> st;
   vector<bool> vis(V, 0);
   for(int i=0; i<V; i++){
      if(!vis[i]){
         dfs(adj, vis, st, i);
      }
   }

   while(st.empty() == false){
      cout << st.top() << " ";
      st.pop();
   }
}

int main() {
   int V = 5;
   vector<int> adj[V+1];
   addEdge(adj, 0, 1);
   addEdge(adj, 1, 3);
   addEdge(adj, 2, 3);
   addEdge(adj, 2, 4);
   addEdge(adj, 3, 4);

   // printGraph(adj, V);
   topologicalDFS(adj, V);
   return 0;
}