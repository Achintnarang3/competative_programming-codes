//minimum steps to one
#include<bits/stdc++.h>
using namespace std;
int bottom_up_appraoch(int n){
    int dp[100] = {0};
    for(int i=2 ; i<=n ; i++){
        int op1 = INT_MAX;
        int op2 = INT_MAX;
        int op3 = INT_MAX;
        if(i%2 == 0){
            op1 = dp[i/2] + 1;
        }
        if(i%3 == 0){
            op2 = dp[i/3] + 1;
        }
        op3 = dp[i-1] + 1;
        dp[i] = min(min(op1 , op2) , op3);
    }
    return dp[n];
}
int top_down_approach(int n , int dp[]){
    if(n<=1){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int op1 = INT_MAX;
    int op2 = INT_MAX;
    int op3 = INT_MAX;
    if(n%2 == 0){
        op1 = 1+top_down_approach(n/2 , dp);
    }
    if(n%3 == 0){
        op2 = 1+top_down_approach(n/3 , dp);
    }
    op3 = 1+top_down_approach(n-1 , dp);

    int ans = min(min(op1 , op2) , op3);
    return dp[n]  = ans;
}

int main(){
    int n;
    cin>>n;
    int dp[100] = {0};
    cout<<top_down_approach(n , dp)<<endl;
    cout<<bottom_up_appraoch(n)<<endl;
    return 0;
}