// ROD CUTTING PROBLEM - DP
#include<iostream>
using namespace std;
int bottom_up_approach(int price[] , int total_length){
    int dp[100] = {0};

    for(int len = 1 ; len<=total_length ; len++){
        int best = 0;
        for(int cut = 1 ; cut<=len ; cut++){
          best = max(best , price[cut] + dp[len-cut]);
        }
        dp[len] = best;
    }
    return dp[total_length];
}
int top_down_approach(int price[] , int total_length , int dp[]){
    if(total_length == 0){
        return 0;
    }
    if(dp[total_length] != 0){
        return dp[total_length];
    }
    int best = 0;
    for(int i=1 ; i<=total_length ; i++){
       int maximum = price[i] + top_down_approach(price , total_length-i , dp);
       best = max(best , maximum);
    }
    return dp[total_length] = best;
}
int main(){
    int total_length;
    cin>>total_length;  //given total length of the rod
    int price[total_length];  
    for(int eachlen = 1 ; eachlen<=total_length ; eachlen++){  //taking input for each price of the length
        cin>>price[eachlen];
    }
    int dp[100] = {0};
    cout<<top_down_approach(price , total_length , dp)<<endl;
    cout<<bottom_up_approach(price , total_length)<<endl;
    return 0;
}