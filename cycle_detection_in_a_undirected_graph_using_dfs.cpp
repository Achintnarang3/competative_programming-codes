
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
    bool dfs_cycle_helper(T node , map<T , bool>&visited , T parent){
        visited[node] = true;
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                bool cycle_detected = dfs_cycle_helper(neighbour  , visited , node);
                if(cycle_detected){
                    return true;
                }
            }else if(neighbour != parent){
                return true;
            }
        }
        return false;
    }
    //check for undirected graph
    bool dfs_is_cyclic(){
        map<T , bool> visited;
        for(auto i : adj){
            T node = i.first;
            if(!visited[node]){
                bool ans = dfs_cycle_helper(node , visited , node);
                if(ans){
                    return true;
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
    if(g1.dfs_is_cyclic()){
        cout<<"graph is cyclic";
    }else{
        cout<<"Not cyclic";
    }
    return 0;

}
