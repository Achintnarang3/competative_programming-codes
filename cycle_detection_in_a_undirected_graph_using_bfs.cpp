
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
    bool bfs_is_cyclic(T src){
        queue<T> q;
        map<T , bool>visited;
        map<T , int>parent;
        q.push(src);
        visited[src] = true;
        parent[src] = src;

        //algorithim for cycle detection
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(auto neighbour : adj[node]){
                if(visited[neighbour] == true && parent[node]!=neighbour){  //main condition for cyclic detection
                    return true;
                }else if(! visited[neighbour]){
                    visited[neighbour] = true;
                    parent[neighbour] = node;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};
int main() {
    graph<int> g1;
    g1.addEdge(1, 2);
    g1.addEdge(1  ,4);
    g1.addEdge(2 , 3);
    g1.addEdge(3 , 4);
    if(g1.bfs_is_cyclic(1)){
        cout<<"graph is cyclic";
    }else{
        cout<<"Not cyclic";
    }
    return 0;

}
