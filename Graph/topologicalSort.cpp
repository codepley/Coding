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

bool topologicalSortCycle(vector<int> adj[], int V){
   vector<int> indegree(V, 0);

   for(int i=0; i<V; i++){
      for(auto u: adj[i]){
         indegree[u]++;
      }
   }

   queue<int> q;
      int count = 0;

   for(int i=0; i<V; i++){
      if(indegree[i] == 0){
         q.push(i);
      }
   }
   while(!q.empty()){
      int p = q.front();
      q.pop();
      cout << p << " ";
      for(auto u: adj[p]){
         indegree[u]--;
         if(indegree[u] == 0){
            q.push(u);
         }
      }
      count++;
   }
   if(count != V){
      return true;
   }
   return false;
}


void topologicalSort(vector<int> adj[], int V){
   vector<int> indegree(V, 0);

   for(int i=0; i<V; i++){
      for(auto u: adj[i]){
         indegree[u]++;
      }
   }

   queue<int> q;
   for(int i=0; i<V; i++){
      if(indegree[i] == 0){
         q.push(i);
      }
   }

   while(!q.empty()){
      int p = q.front();
      q.pop();
      cout << p << " ";
      for(auto u: adj[p]){
         indegree[u]--;
         if(indegree[u] == 0){
            q.push(u);
         }
      }
   }
}

int main() {
   int V = 5;
   vector<int> adj[V+1];
   addEdge(adj, 0, 2);
   addEdge(adj, 0, 3);
   addEdge(adj, 2, 3);
   addEdge(adj, 1, 3);
   addEdge(adj, 1, 4);

   cout << "Topological Sort is:- \n";
   // topologicalSort(adj, V);
   bool isCycle = topologicalSortCycle(adj, V);
   cout << endl;
   if(isCycle){
      cout << "Has Cycle" << endl;
   }else{
      cout << "Does not have cycle" << endl;
   }
   return 0;
}