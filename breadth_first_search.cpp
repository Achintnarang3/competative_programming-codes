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
    void print(){
        for(auto i : adj){
            cout<<i.first<<" -> ";
            for(auto entry : i.second){
                cout<<entry<<" , " ;
            }
            cout<<endl;
        }
    }
    void bfs(T src){
        queue<T> q;
        map<T , bool> visited; //To check which nodes are visited.
        
        q.push(src);
        visited[src] = true;
        while(!q.empty()){

            T node = q.front();
            cout<<node<<" ";
            q.pop();

            // now we have to put neighbours of the node into the queue and mark them visted

            for(auto neighbour : adj[node]){
                if(visited[neighbour] == false){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
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
     
     g1.bfs(0);
    return 0;
}