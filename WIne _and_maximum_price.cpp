//WINE AND MAXIMUM PRICE
#include <bits/stdc++.h>
using namespace std;
int top_down_approach(int start , int end , int year , int dp[][100] , int p[]){
    if(start > end){
        return 0;
    }
    if(dp[start][end] != 0){
        return dp[start][end];
    }

    int ans1 = p[start]*year + top_down_approach(start+1 , end , year+1 , dp , p);
    int ans2 = p[end]*year + top_down_approach(start , end-1 , year+1 , dp , p);

    return dp[start][end] = max(ans1 , ans2);
}

int main() {
    
    int n;
    cin>>n;
    int p[n];
    for(int i=0 ; i<n ; i++){
        cin>>p[i];
    }
    int dp[100][100]={0};
    cout<<top_down_approach(0 , n-1 , 1 , dp , p)<<endl;
    cout<<bottom_up_approach(n , p)<<endl;
    return 0;
}
