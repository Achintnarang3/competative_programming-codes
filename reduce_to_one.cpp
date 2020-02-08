#include<bits/stdc++.h>
using namespace std;
int count =0;
int memo[10000] ;
int dp[10000] = {};
int reduce_to_one(int n){
    if(n == 1){
        return 0;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    int q1 = INT_MAX;
    int q2 = INT_MAX;
    int q3 = INT_MAX;
    if(n%3 == 0) q1  = 1 + reduce_to_one(n/3);
    if(n%2 == 0) q2 = 1 + reduce_to_one(n/2);
    q3 = 1 + reduce_to_one(n-1);
    memo[n] = min(q3 , min(q1 , q2));
    return memo[n];
}

int reduce_to_one_dp(int n){     //bottom_up_approach
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    
    for(int i=4 ; i<=n ; i++){
        int q1 = INT_MAX;
        int q2 = INT_MAX;
        int q3 = INT_MAX;
    if(i%3 == 0) q1 = 1 + dp[i/3];
    if(i%2 == 0) q2 = 1 + dp[i/2];
    q3 = 1 + dp[i-1];
    int ans = min(q3 , min(q1 , q2));
    dp[i] = ans;
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    memset(memo , -1 , sizeof(memo));
    cout<<reduce_to_one(n)<<endl;
    cout<<reduce_to_one_dp(n);
    return 0;
}