#include <iostream>
#include<cstring>
using namespace std;

#define ll long long
ll a[1000005] , prefixSum[1000005];
int main() {
    ll t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        ll sum =0;
        memset(prefixSum , 0 ,sizeof prefixSum);

        prefixSum[0] = 1;
        for(int i =0 ; i<n; i++){
           cin>>a[i];
           sum+=a[i];
           sum%=n;
           sum = (sum+n)%n;
           //first make the number positive 
           //then update the frequency
           prefixSum[sum]++;
        }
        ll ans = 0;
        for(int i =0 ; i<n; i++){
          //  cout<<prefixSum[i]<<" ";
            ll no = prefixSum[i];
            ans += ((no)*(no-1))/2;
        }
          cout<<ans<<endl;
    }
    return 0;
}
