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
    void bfs(T src){
        queue<T> q;
        map<T , int> distance; //To check which nodes are visited.
        map<T , T>parent;
        for(auto i : adj){
            distance[i.first] = INT_MAX;
        }

        q.push(src);
        distance[src] = 0;
        while(!q.empty()){

            T node = q.front();
            //cout<<node<<" ";
            q.pop();

            // now we have to put neighbours of the node into the queue and find their shortest distance

            for(auto neighbour : adj[node]){
                if(distance[neighbour] == INT_MAX){
                    q.push(neighbour);
                    distance[neighbour] = distance[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }
        for(auto i : adj){
            T node = i.first;
            cout<<"The distance of "<<node<<" from "<<src<<" is "<<distance[node]<<endl;
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