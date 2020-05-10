/* space optimised version of seive
more space  = more range of prime numbers you can store
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
int main() {
    seive();
    for(int i=0 ; i<=100 ; i++){
        cout<<primes[i]<<" ";
    }
    return 0;
}
