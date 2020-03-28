/* OUTPUT
   English --> Maths --> ProgrammingLogic --> HTML --> Python --> Java --> CSS --> JS --> WebDev --> 
*/

#include <bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
    map<T , list<T>> adj;
    public:
    void addEdge(T u , T v , bool bidir = true){
        adj[u].push_back(v);
        if(bidir == true){
            adj[v].push_back(u);
        }
    }
    void bfs_topological_sort(){
        queue<T> q;
        map<T , int>indegree;
        for(auto i : adj){
            // i is a pair of (node, list_of_nodes)
            T node = i.first;
            indegree[node] = 0;
        }
        //initialize the indegrees of all the nodes
        for(auto i : adj){
            T u = i.first;
            for(auto v : adj[u]){
                indegree[v]++;
            }
        }
        //push all the nodes which have indegrees zero
        for(auto i : adj){
            T node = i.first;
            if(indegree[node] == 0){
                q.push(node);
            }
        }
        //algorithim
        while(!q.empty()){
            T node = q.front();
            cout<<node<<" --> ";
            q.pop();
            for(auto neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
    }
};
int main() {
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
     g1.bfs_topological_sort();
    return 0;

}
