//MAXIMUM SUBARRAY SUM
#include<bits/stdc++.h>
using namespace std;
int maximum_subarray_sum(int a[] , int n){
    int dp[100] = {0};
    
    if(a[0] > 0){
        dp[0] = a[0];
    }else{
        dp[0] = 0;
    }
    int max_so_far = dp[0];
    for(int i=1 ; i<n ; i++){
        dp[i] = dp[i-1] + a[i];
        if(dp[i] < 0){ dp[i] = 0 ; }
         
         max_so_far = max(max_so_far , dp[i]);
    }
    return max_so_far;
}
int kadane_algo(int a[] , int n){

    int max_so_far = a[0]; 
    int curr_max = a[0]; 

    for (int i = 1; i < n; i++) 
   { 
		curr_max = max(a[i], curr_max+a[i]); 
		max_so_far = max(max_so_far, curr_max); 
   } 
      return max_so_far; 
} 
int main(){

    int a[] = {-3 , 2 , 5, -1 , 6 , 3 , -2 , 7 , -5 ,2};
    int n = sizeof(a)/sizeof(int);

    cout<<maximum_subarray_sum(a, n)<<endl;
    cout<<kadane_algo(a, n)<<endl;
    return 0;
}