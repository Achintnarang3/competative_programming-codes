/*INPUT
30
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 3825123056546413051
*/
/*OUPUT
NOT PRIME
PRIME
PRIME
NOT PRIME
PRIME
NOT PRIME
PRIME
NOT PRIME
NOT PRIME
NOT PRIME
PRIME
NOT PRIME
PRIME
NOT PRIME
NOT PRIME
NOT PRIME
PRIME
NOT PRIME
PRIME
NOT PRIME
NOT PRIME
NOT PRIME
PRIME
NOT PRIME
NOT PRIME
NOT PRIME
NOT PRIME
NOT PRIME
PRIME
PRIME
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll modular_multipliaction(ll a , ll b , ll n){
    ll res = 0;
    while(b>0){
        if(b&1ll){
            res += a;
        }
        a=a*2;
        b=b/2;
        res%=n;
        a%=n;
    }
    return res;
}
ll modular_exponentiation(ll a , ll b , ll n){
    ll res =1;
    while(b>0){
        if(b&1ll){
           res = modular_multipliaction(res , a , n);
           res %= n;
        }
    a = modular_multipliaction(a , a , n);
    a %= n;
    b /= 2;
  }
  return res;
}
bool miller_rabin(ll n){
    if(n == 1){
        return false;
    }
    if(n == 2){
        return true;
    }
    if(n%2 == 0){
        return false;
    }
    //now at this point n is odd therefore n-1 is even
    ll d = n-1;
    ll s = 0;
    while(d%2 == 0){
        s++;
        d = d/2;
    }
    // n-1 = d*pow(2 , s)
    // now d is odd
    vector<ll> a({2,3,5,7,11,13,17,19,23});
    // now a represent as random numbers
    for(ll i=0 ; i<a.size() ; i++){
        if(a[i] > n-2){
            continue;
        }
        // (a[i]^d)%n
        ll ad = modular_exponentiation(a[i] , d , n);
        if(ad%n == 1) continue;
        bool prime = false;
        for(ll r=0 ; r<=s-1 ; r++){
            //(2^r)%n
            ll rr = modular_exponentiation(2 , r , n);
            // (a^(d*2*i))%n
            ll ard = modular_exponentiation(ad , rr , n);
            if(ard%n == n-1){
                prime = true;
                break;
            }
        }
        if(prime == false) return false;
    }
    return true;
}
int main(){
    ll  t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(miller_rabin(n)){
            cout<<"PRIME"<<endl;
        }else{
            cout<<"NOT PRIME"<<endl;
        }
    }
    return 0;
}