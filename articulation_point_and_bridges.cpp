#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> graph[N];
int discovered[N] , lowest[N] ;
int t; //time
set<int> art_p;
vector<pair<int , int>> bridge;
void dfs(int curr , int par){
    int no_child = 0;
    discovered[curr] = t;
    lowest[curr] = t;
    t++;
    for(auto child : graph[curr]){
        //not visited
        if(discovered[child] == 0){
            dfs(child , curr);
            no_child++;
            lowest[curr] = min(lowest[child] , lowest[curr]);
            //articulation point
            if(par != 0 && lowest[child]  >= discovered[curr]){
                art_p.insert(curr);
            }
            //bridges
            if(lowest[child] > discovered[curr]){
                bridge.push_back(make_pair(curr , child));
            }
        }else if(child != par){
            //backEdge
            //cycle is found
            lowest[curr] = min(lowest[curr] , discovered[child]);
        }
    }
    //separate casse for the root to be articulation point
    if(par == 0 && no_child >=2){
      art_p.insert(curr);
    }

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
    t = 1;
    dfs(1 , 0);
    for(auto x : art_p){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
