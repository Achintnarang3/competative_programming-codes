#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> graph[N];
//visited array has three states
//0 -> not visted
//1 -> visited and coloured in 1
//2 -> visited and coloured in 2
//therfore (3-col) will help to do so
int visited[N]; 
bool odd_cycle;
void dfs(int curr , int par , int col){
    visited[curr] = col;
    for(auto child : graph[curr]){
        //not visited
        if(visited[child] == 0){
            dfs(child , curr , 3-col);
        }else if(child != par && col == visited[child]){
            //back edge and odd cycle
            odd_cycle = 1;
        }   
    }
    return;
}
int main() {
    int n , m;
    cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int x , y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1  , 0 , 1);
    if(odd_cycle){
        cout<<"NO IT IS NOT BIPARTITE! \n";
    }else{
        cout<<"YES IT IS BIPARTITE! \n";
    }
    return 0;
}
