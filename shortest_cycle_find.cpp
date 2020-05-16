#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> graph[N];
void bfs(int src , int n ,int &ans){
    vector<int>distance(n+1 , INT_MAX);
    queue<int>  pq;
    pq.push(src);
    distance[src] = 0;
    while(!pq.empty()){
        int node = pq.front();
        pq.pop();
        for(auto child : graph[node]){
            //not visited
             if(distance[child] == INT_MAX){
                 distance[child] = distance[node] + 1;
                 pq.push(child);
             }else if(distance[child] >= distance[node]){
                //back edge is encountered
                ans = min(ans , distance[child] + distance[node] + 1);
             }      
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
    int ans = n+1;
    for(int i=1 ; i<=n ; i++){
        bfs(i , n , ans);
    }
    if(ans == n+1){
        cout<<"No cycle is present"<<endl;
    }else{
        cout<<"shortest cycle is present of length "<<ans<<endl;
    }
    return 0;
}
