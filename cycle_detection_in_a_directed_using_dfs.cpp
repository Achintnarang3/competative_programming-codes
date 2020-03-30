/*  CYCLE DETECTION IN DIRECTED GRAPH USING DFS*/
#include <iostream>
#include<map>
#include<list>
using namespace std;
template<typename T>
class graph{
   map<T , list<T>> adjlist;
   public:
   void addEgde(T u , T v , bool bidir){
       adjlist[u].push_back(v);
       if(bidir == true){
           adjlist[v].push_back(u);
       }
   }
   bool cyclicHelper(T node , map<T , bool>&visited , map<T , bool>&instack){
        //process the node - visited and instack
        visited[node] = true;
        instack[node] = true;

        for(auto neighbour : adjlist[node]){
            //now we have two options
            //the current node is not visited but its further branch leads to cycle
            if(!visited[neighbour] && cyclicHelper(neighbour , visited , instack) || instack[neighbour]){
                return true;
            }
        }
        //pop out the current node from the instack
        instack[node] = false;
        return false;
   }
   bool isCyclic(){
       map<T, bool>visited;
       map<T ,bool>instack;

       //to check for cycle in every dfs tree
       for(auto i : adjlist){
           T node = i.first;
           if(!visited[node]){
              bool cyclePresent = cyclicHelper(node , visited , instack);
              if(cyclePresent){
                  return true;
              }
           }
       }
       return false;
   }

};

int main() {
    graph<int> g;
    g.addEgde(0,2,false);
    g.addEgde(0,1,false);
    g.addEgde(2,3,false);
    g.addEgde(2,4,false);
   // g.addEgde(3,0,false);  //this is back edge which leads to cycle in the graph
    g.addEgde(4,5,false);
    g.addEgde(1,5,false);

    if(g.isCyclic()){
        cout<<"Graph Contains Cycle!";
    }else{
        cout<<"Graph does not contain Cycle!";
    }
    return 0;
}
