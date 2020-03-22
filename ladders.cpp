/* you are given two values n , k . You have to reach nth step by taking at max k jumps.
   You have to output the  total number of ways to reach the nth step */
#include <iostream>
using namespace std;
int bottom_up_approach(int n, int k){
     int dp[100] = {0};
     dp[0]= 1;
     for(int i=1 ; i<=n ; i++){
            dp[i] = 0;
            for(int j=1 ; j<=k ; j++){
                if(i-j >=0){
                    dp[i] += dp[i-j];
                }
            }
     }
     return dp[n];
}
int top_down_approach(int n , int k , int dp[]){
     if(n == 0){
         return 1;
     }
     if(dp[n] != 0){
         return dp[n];
     }
     int ways = 0;
     for(int i=1 ; i<=k ; i++){
         if(n-i >=0){
             ways += top_down_approach(n-i , k , dp);
         }
     }
     return dp[n] = ways;
}
int main() {
    int n, k;
    cin>>n>>k;
    int dp[100] = {0};
    cout<<top_down_approach(n , k , dp)<<endl;
    cout<<bottom_up_approach(n, k)<<endl;
    return 0;
}
