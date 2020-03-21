//Minimum Coin Change
#include<bits/stdc++.h>
using namespace std;
int top_down_approach(int m , int coins[] , int n , int dp[]){
    if(m == 0){
        return 0;
    }
    if(dp[m]!=0){
        return dp[m];
    }
    int ans = INT_MAX;
    for(int i=0 ; i<n ;i++){
        if(m-coins[i] >= 0){
            int subans = 1 + top_down_approach(m-coins[i] , coins , n , dp);
           ans = min(ans , subans);
        }
    }
    return dp[m] = ans;
}

int bottom_up_approach(int m , int coins[] , int n){
    int dp[100] = {0};

    for(int i=1 ; i<=m  ; i++){
        dp[i] = INT_MAX;
        for(int j=0 ; j<n ; j++){
            if(i-coins[j] >=0){
                int ans = dp[i-coins[j]] + 1;
                dp[i] = min(ans , dp[i]);
            }
        }
    }
    return dp[m];
}
int main(){
    int dp[100] = {0};
    int n;
    cin>>n;
    int coins[n];
    for(int i=0 ; i<n ; i++){
        cin>>coins[i];
    }
    int m;
    cin>>m;
    cout<<top_down_approach(m , coins, n , dp)<<endl;
    cout<<bottom_up_approach(m , coins , n)<<endl;
}