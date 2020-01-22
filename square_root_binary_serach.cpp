#include<iostream>
using namespace std;

float square_root_binary_search(int n , int p){
    //integer part
    int start  = 0 , end = n  , mid;
    float ans;
    while(start<=end){
        mid = (start+end)/2;
         if(mid*mid == n){
             ans = mid;
             return ans;
             break;
         }
         if(mid*mid < n){
             start = mid+1;
             ans = mid;
         }else{
             end = mid-1;
         }
    }

    //fractional Part
    float inc = 0.1;
    for(int i=0; i<p; i++){
        while(ans*ans <= n){
            ans += inc;
        }
        // ans*ans > n
        ans = ans-inc;
        inc = inc/10;
    }

    return ans;
}
int main(){
       cout<<square_root_binary_search(49 , 1)<<endl;
       cout<<square_root_binary_search(10 , 3)<<endl;
       cout<<square_root_binary_search(2 , 5)<<endl;
}