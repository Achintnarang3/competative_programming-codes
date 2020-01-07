#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
   int t;
   cin>>t;
   ll n;
   ll primes[] = {2 , 3 , 5 ,7  , 11 , 13 , 17 , 19};
   for(ll i =0 ; i<t ; i++){
         cin>>n;
       ll subsets = (1<<8)-1;
       ll ans = 0;
       for(int i = 1 ; i<=subsets ; i++){
           ll denominator = 1ll;
           ll setbits = __builtin_popcount(i);

           for(ll j =0 ; j<=7 ; j++){
               if(i & (1<<j)){
                   denominator = denominator*primes[j];
               }
           }
           if((setbits&1)){
               ans += n/denominator;
       }else{
           ans -= n/denominator;
       }
       }
       cout<<ans<<endl;
   }
}