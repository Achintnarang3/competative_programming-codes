#include <bits/stdc++.h>
using namespace std;
int longest_subarray_with_sum_k(int *a , int n  , int k){
    map<int , int> mp;
    int pre =0;
    int length = 0;
    for(int i=0 ; i<n ;i++){
        pre += a[i];
        if(pre == k){
            length = max(length , i+1 );
        }
        if(mp.find(pre-k) != mp.end()){
            length = max(length , i-mp[pre-k]);
        }else{
            mp[pre] = i;
      }
    }
    return length;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    cout<<longest_subarray_with_sum_k(a , n,k)<<endl;
    return 0;
}
