#include <bits/stdc++.h>
using namespace std;

int clearRangeIToJ(int n , int i , int j){
    int a  = -1<<(j+1);
    int b = (1<<i)-1;
    int mask = a|b;
    int ans = n & mask;
    return ans;
}

void replaceBits(int n  , int i , int j , int m){
    int n_ = clearRangeIToJ(n , i , j);
    int ans = n_|(m<<i);
    cout<<ans;

}
int main() {
    int n , i ,j , m;
    cin>>n>>i>>j>>m;
    replaceBits(15 , 1 , 3 ,2);
    return 0;
}
