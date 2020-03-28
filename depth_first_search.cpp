#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{
     map<T , list<T>> adj;
public:
    graph(){
        //map uses dynamic memory allocation , so no need to input number of edges.
    }
    void addEdge(T u , T v , bool bidir){  
       adj[u].push_back(v);
       if(bidir == true){
           adj[v].push_back(u);
       }
    }
   void dfs_helper(T node , map<T , bool>&visited){
    //whenever come to the node mark it visited
     visited[node] = true;
     cout<<node<<" , ";
     //try to find out a node which is neighbour of current node and not yet visited.
     for(auto neighbour : adj[node]){
         if(!visited[neighbour]){
             dfs_helper(neighbour , visited);
         }
     } 
   }
   void dfs(T src){
      map<T , bool>visited;
      dfs_helper(src , visited);
   }
};
int main(){
   graph<int> g1;
     g1.addEdge(0 , 1 , true);
     g1.addEdge(0 , 4 , true);
     g1.addEdge(1 , 2, true);
     g1.addEdge(2 , 4 , true);
     g1.addEdge(2  , 3 ,true);
     g1.addEdge(3 , 5 , true);
     g1.addEdge(3 , 4 ,true);
     
     g1.dfs(0);

    return 0;
}