/* OUTPUT
   Amritsar , Jaipur , Delhi , Bhopal , Mumbai , Bangalore , Agra , 
   Andaman , Nicobar , 
   The graph has 2 components .
*/

#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{
     map<T , list<T>> adj;
public:
    graph(){
        //map uses dynamic memory allocation , so no need to input number of edges.
    }
    void addEdge(T u , T v , bool bidir = true){  
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
      cout<<endl;
      int component = 1;
      for(auto i : adj){
          T node  = i.first;
          if(!visited[node]){
             dfs_helper(node , visited);
             component++;
          }
      }
   cout<<endl<<"The graph has "<<component<<" components .";
   }
};
int main(){
   graph<string> g1;
     g1.addEdge("Amritsar" , "Jaipur");
     g1.addEdge("Amritsar" , "Delhi");
     g1.addEdge("Delhi" , "Jaipur");
     g1.addEdge("Mumbai" , "Jaipur");
     g1.addEdge("Mumbai","Bhopal");
     g1.addEdge("Delhi" , "Bhopal");
     g1.addEdge("Mumbai" ,"Bangalore");
     g1.addEdge("Agra" ,"Delhi");
     g1.addEdge("Andaman" ,"Nicobar");
     g1.dfs("Amritsar");
    return 0;
}