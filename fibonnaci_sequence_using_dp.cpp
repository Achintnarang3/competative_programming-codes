#include <iostream>
using namespace std;
int memo[1000];
int dp[1000] = {};
int bottom_up_approach_fib(int n){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2 ; i<=n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int top_down_approach_fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(memo[n] != -1) return memo[n];

    int ans = top_down_approach_fib(n-1) + top_down_approach_fib(n-2);
    memo[n] = ans;
    return memo[n];
}
int main() {
    int n;
    cin>>n;
    for(int i=0 ; i<=n ; i++){
        memo[i] = -1;
    }
    cout<<top_down_approach_fib(n)<<endl;
    cout<<bottom_up_approach_fib(n)<<endl;
    return 0;
}
