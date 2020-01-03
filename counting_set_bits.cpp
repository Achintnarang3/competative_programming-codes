#include<bits/stdc++.h>
using namespace std;
int count_bits_slow(int n){
    int ans=0;
    while(n>0){
        ans+=(n&1);
        n=n>>1;
    }
    return ans;
}
int count_bits_fast(int n){
    int ans=0;
    while(n>0){
        n=n&(n-1);
        ans++;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<count_bits_slow(n)<<endl;
    cout<<count_bits_fast(n)<<endl;
    cout<<"built in function: "<<__builtin_popcount(n);
}