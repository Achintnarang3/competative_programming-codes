#include <bits/stdc++.h>
using namespace std;
int longest_subarray_with_sum_zero(int *a , int n){
    map<int , int> mp;
    int pre =0;
    int length = 0;
    for(int i=0 ; i<n ;i++){
        pre += a[i];
        if(a[i] == 0 and length==0){
            length = 1;
        }
        if(pre == 0){
            length = max(length , i+1 );
        }
        if(mp.find(pre) != mp.end()){
            length = max(length , i-mp[pre]);
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
    cout<<longest_subarray_with_sum_zero(a , n)<<endl;
    return 0;
}
