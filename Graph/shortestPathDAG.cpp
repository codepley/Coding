#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w) {
   adj[u].push_back(make_pair(v, w));
}

void printGraph(vector<pair<int, int>> adj[], int V) {
   for(int i=0; i<V; i++){
      cout << i << "->";
      for(auto u: adj[i]){
         cout << "(" << u.first << ", " << u.second << ") ";
      }
      cout << endl;
   }
}

vector<int> topologicalSort(vector<pair<int, int> > adj[], int V){
   vector<int> indegree(V, 0);
   vector<int> ans;
   for(int i=0; i<V; i++){
      for(auto u: adj[i]){
         indegree[u.first]++;
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
      ans.push_back(p);
      for(auto u: adj[p]){
         indegree[u.first]--;
         if(indegree[u.first] == 0){
            q.push(u.first);
         }
      }
   }
   return ans;
}

vector<int> shortestPathDAG(vector<pair<int, int>> adj[], int V, int s){
   vector<int> topoSort = topologicalSort(adj, V);
   cout << "Topo vector:-\n";
   for(auto u: topoSort){
      cout << u << " ";
   }cout << endl;
   vector<int> dist(V, INT_MAX);
   dist[s] = 0;
   for(auto u: topoSort){
      if(dist[u] != INT_MAX){
         for(auto v: adj[u]){
            if(dist[v.first] > dist[u] + v.second){
               dist[v.first] = dist[u] + v.second;
            }
         }
      }
   }
   return dist;
}

int main() {
   int V = 6;
   vector<pair<int, int>> adj[V+1];
   addEdge(adj, 0, 1, 2);
   addEdge(adj, 0, 4, 1);
   addEdge(adj, 1, 2, 3);
   addEdge(adj, 2, 3, 6);
   addEdge(adj, 4, 2, 2);
   addEdge(adj, 4, 5, 4);
   addEdge(adj, 5, 3, 1);

   printGraph(adj, V);
   vector<int> ans = shortestPathDAG(adj, V, 0);
   for(auto u: ans){
      cout << u << " ";
   }
   return 0;
}