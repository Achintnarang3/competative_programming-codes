#include <iostream>
using namespace std;
#define ll long long

ll fastModuloExpo(ll a , ll b ,  ll m){
    ll res =1;
    while(b>0){
        if(b&1){
          res = (res*a)%m;
        }
        a = (a*a)%m;
        b = b>>1;
    }
    return res;
}
   int main() {
    ll a , b , m;
    cin>>a>>b>>m;
    ll ans = fastModuloExpo(a ,b , m);
    cout<<ans;
return 0;
}