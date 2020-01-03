#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , ans=0;
    cin>>n;
    int num;
    for(int i=0 ; i<n ; i++){
       cin>>num;
        ans = ans^num;
    }
    cout<<ans;

    return 0;
}