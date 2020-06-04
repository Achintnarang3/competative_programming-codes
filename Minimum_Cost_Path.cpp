#include <bits/stdc++.h>
using namespace std;
int minimum_cost_path(int r , int c , int cost[][10] , int dp[][10]){
    for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
           //base case
           if(i==0 && j==0){
               dp[i][j] = cost[0][0];
           }else if(i==0){
               dp[i][j] = dp[0][j-1] + cost[0][j];
           }else if(j==0){
               dp[i][j] = dp[i-1][0] + cost[i][0];
           }else{
               dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + cost[i][j];
           }
        }
    }
    return dp[r-1][c-1];
}
int main() {
    int n , m;
    cin>>n>>m;
    int mat[10][10] ;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin>>mat[i][j];
        }
    }
    int dp[10][10] = {0};
    cout<<minimum_cost_path(n , m , mat , dp);
    return 0;
}
