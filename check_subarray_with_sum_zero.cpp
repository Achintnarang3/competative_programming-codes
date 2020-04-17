#include <bits/stdc++.h>
using namespace std;
bool check_subarray_with_sum_zero(int *a , int n){
    set<int> s;
    int pre =0;
    for(int i=0 ; i<n ;i++){
        pre += a[i];
        if(pre == 0 or s.find(pre)!=s.end()){
            return true;
        }
        s.insert(pre);
    }
    return false;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    if(check_subarray_with_sum_zero(a  ,  n)){
      cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
