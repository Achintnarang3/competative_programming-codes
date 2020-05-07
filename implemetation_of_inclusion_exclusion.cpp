/* WE HAVE TO FIND THE NUMBERS FROM 1 TO 999 WHICH ARE DIVISIBLE BY (2 , 3 , 5) */
#include <iostream>
using namespace std;
int main() {
    int a[] = {2 , 3 , 5, 7};
    int n  = sizeof(a)/sizeof(int);
    int num = 999;
    int ans = 0;
    for(int i=1 ; i<(1<<n); i++){
        int temp = 1;
        int pos = 0;
        int mask = i;
        int bits = __builtin_popcount(mask);
        while(mask>0){
            int lastbit = (mask&1);
            if(lastbit){
              temp*=a[pos];
            }
           mask = (mask>>1);
           pos++; 
        }
    if(bits%2 != 0){
        ans += (num/temp);
    }else{
        ans -= (num/temp);
    }
    }
    cout<<ans;
    return 0;
}
