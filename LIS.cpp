//Longest Increasing Subsequence
#include <iostream>
using namespace std;
int LIS(int a[] , int n){ 
    int dp[100] ={1};
    int best = -1;
    for(int i=1 ; i<n ; i++){
        for(int j=0 ; j<i ; j++){
            if(a[j] <= a[i]){
                int current_length = 1 + dp[j];
                dp[i] = max(dp[i] , current_length);
            }
        }
        best = max(dp[i] , best);
    }
    return best;
}
int main() {
    
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n ;i++){
        cin>>a[i];
    }
    cout<<LIS(a , n)<<endl;
    return 0;
}
