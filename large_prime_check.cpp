/* space optimised version of seive
more space  = more range of prime numbers you can store
To check prime over number of order nearly 10^14
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n = 10000000;
bitset<10000005>bit;
vector<ll>primes;
void seive(){
    bit.set(); // set all to 1
    bit[0] = 0;
    bit[1] = 0;
    for(ll i=2 ; i<=n ; i++){
        if(bit[i] == 1){
            primes.push_back(i);
            for(ll j=i*i ; j<=n ; j+=i){
                bit[j] = 0;
            }
        }
    }
}
bool isPrime(ll num){
    if(num <= n){
        return bit[num];
    }
    for(ll i=0; primes[i]*primes[i]<=n ; i++){
        if(num%primes[i] == 0){
            return false;
        }
    }
    return true;
}
int main() {
    seive();
    if(isPrime(2147483647)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
