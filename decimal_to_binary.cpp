#include<bits/stdc++.h>
using namespace std;
int decimal_to_binary(int n){

    int ans=0;
    int p=1;
    while(n>0){
        int last_bit = (n&1);
        ans += last_bit*p;
        p=p*10;
        n=n>>1;
    }
    return ans;
}
 
int main(){
    int n;
    cin>>n;
    cout<<decimal_to_binary(n);
}