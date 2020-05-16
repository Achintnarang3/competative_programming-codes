/*
INPUT
6 7
1 2
2 3
3 1
3 4
4 5
5 6
6 4
OUTPUT
1 -> 1
2 -> 1
3 -> 1
4 -> 2
5 -> 2
6 -> 2
*/
/*
INPUT
6 8
1 2
2 3
3 1
3 4
4 5
5 6
6 4
5 1
OUTPUT
1 -> 1
2 -> 1
3 -> 1
4 -> 1
5 -> 1
6 -> 1
*/
//KOSARAJU ALGO
#include <bits/stdc++.h>
using namespace std;
const int N =100005;
//gr -> input graph
//grr -> reverse of the input graph
vector<int> gr[N] , grr[N];
vector<int>order;
int visited[N] , comp[N] ;
void dfs(int src){
    visited[src] = 1;
    for(auto child : gr[src]){
        if(!visited[child]){
            dfs(child);
        }
    }
    order.push_back(src);
}
void dfs_reverse(int cur , int col){
    visited[cur] = 1;
    comp[cur] = col;
    for(auto child: grr[cur]){
        if(!visited[child]){
            dfs_reverse(child , col);
        }
    }
}
int main() {
    int n , m;
    cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int x , y;
        cin>>x>>y;
        gr[x].push_back(y);
        grr[y].push_back(x);
    }
    //now we have to perform dfs from every node
    //because there can be more than one connected components
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    memset(visited , 0 , sizeof(visited));
    //perform dfs on reverse graph
    int col = 1;
    for(int i=n-1 ; i>=0 ; i--){
        if(!visited[order[i]]){
            dfs_reverse(order[i] , col);
            col++;
        }
    }
    for(int i=1 ; i<=n ; i++){
        cout<<i<<" -> "<<comp[i]<<endl;
    }
return 0;
}
