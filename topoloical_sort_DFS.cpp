/*  OUTPUT
   Maths , English , ProgrammingLogic , Java , Python , HTML , CSS , JS , WebDev ,
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
   void dfs_helper(T node , map<T , bool>&visited, list<T> &ordering){
    //whenever come to the node mark it visited
     visited[node] = true;
     //try to find out a node which is neighbour of current node and not yet visited.
     for(auto neighbour : adj[node]){
         if(!visited[neighbour]){
             dfs_helper(neighbour , visited ,ordering);
         }
     }
     //at this point all the children of the current node has been visited
     //so we can add current node to the list
     //just one line of Topological Sort
     ordering.push_front(node); 
   }
   void dfs_Topological_sort(){
      map<T , bool> visited;
      list<T> ordering;
      for(auto i : adj){
          T node  = i.first;
          if(!visited[node]){
             dfs_helper(node , visited , ordering);
          }
      }
      for(auto x : ordering){
          cout<<x<<" , ";
      }
   }
};
int main(){
   graph<string> g1;
     g1.addEdge("English" , "ProgrammingLogic" , false);
     g1.addEdge("Maths" , "ProgrammingLogic", false);
     g1.addEdge("ProgrammingLogic" , "HTML", false);
     g1.addEdge("ProgrammingLogic" , "Python" , false);
     g1.addEdge("ProgrammingLogic","Java" , false);
     g1.addEdge("ProgrammingLogic" , "JS" , false);
     g1.addEdge("Python" ,"WebDev" , false);
     g1.addEdge("HTML" ,"CSS" , false);
     g1.addEdge("CSS" ,"JS" , false);
     g1.addEdge("JS" ,"WebDev" , false);
     g1.addEdge("Java" ,"WebDev" , false);
     g1.addEdge("Python" ,"WebDev" , false);
     g1.dfs_Topological_sort();
    return 0;
}