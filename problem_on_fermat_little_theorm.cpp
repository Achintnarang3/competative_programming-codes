//LIGHTS NEW CAR PROBLEM BASED ON FERMAT LITTLE'S THEOREM
// Given A , B , we have to find (A Power B)%(10^9 + 7) Where A , B <= 10^100000
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;
ll convertStringToInt(string a , ll m){
    ll ans = 0;
    for(int i=0 ; i<a.size() ; i++){
        ans  = (ans*10)%m + (a[i] - '0');
        ans %= m;
    }
    return ans;
}
ll power(ll x , ll y , ll m){
    if(y == 0){
        return 1;
    }
    ll smallerAns = power(x , y/2 ,m);
    smallerAns %= m;
    smallerAns = (smallerAns*smallerAns)%m;
    if(y&1){
        return (x*smallerAns)%m;
    }
    return smallerAns;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string A , B;
        cin>>A>>B;
        ll x = convertStringToInt(A , mod);
        ll y = convertStringToInt(B , mod-1);

        ll ans = power(x , y , mod);
        cout<<ans<<endl;
    }
    return 0;
}