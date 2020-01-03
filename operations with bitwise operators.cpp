#include <bits/stdc++.h>
using namespace std;
void odd_even(int n){
    int ans = n&1;
    if(ans ==1){
        cout<<"the number is odd"<<endl;
    }else{
        cout<<"the number is even"<<endl;
    }
}
void get_bit(int n , int i){
    int mask = 1<<i;
    int ans = n&mask;
    if(ans >0){
        cout<<1<<endl;
    }
    if(ans == 0){
        cout<<0<<endl;
    }
}
void set_bit(int n , int i){
    int mask = 1<<i;
    int ans = n|mask;
    cout<<ans<<endl;
}
void clear_bit(int n , int i){
       int mask = ~(1<<i);
       int ans = n & mask;
       cout<<ans<<endl;
}
void update_bit(int n , int i, int v){
    int mask = ~(1<<i);
    int cleared_bit = n&mask;
    int ans = cleared_bit|(v<<i);
    cout<<ans<<endl;
}
void clearLastIBits(int n, int i){
    int mask = -1<<(i+1);
    int ans= n & mask;
    cout<<ans<<endl;
}
void clearRangeIToJ(int n , int i , int j){
    int a  = -1<<(j+1);
    int b = (1<<i)-1;
    int mask = a|b;
    int ans = n & mask;
    cout<<ans<<endl;
}
int main() {
    int n , i , value;
    cin>>n>>i>>value;
    odd_even(n);
    get_bit(n, i);
    set_bit(n , i);
    clear_bit(n, 1);
    update_bit(n , i , value);
    clearLastIBits(15 , 2);
    clearRangeIToJ(31 , 1 , 3);
    return 0;
}
