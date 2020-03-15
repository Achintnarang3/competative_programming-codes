#include <iostream>
using namespace std;
int a[100] , BIT[100] = {0};
//Range sum query
void update(int index , int inc , int n){
    while(index<=n){
        BIT[index] += inc ;
        index += (index & (-index));
    }
}
//sum query
int query(int index){
    int sum =0 ;
    while(index > 0){
        sum += BIT[index];
        index -= (index & (-index));
    }
    return sum;
}
int main() {
    int n;
    cin>>n;
    //build BIT
    for(int i=1 ; i<=n ; i++){
        cin>>a[i];
        update(i , a[i] , n);
    }
    //query
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<query(r) - query(l-1)<<endl;
    }
    return 0;
}
