//we cannot find maxmuim within [l,r] but we can finf maxmim witin [1, l]
#include <iostream>
using namespace std;
int a[100] , BIT[100] = {0};
//Range max query
void update(int index , int value , int n){
    while(index<=n){
        BIT[index] = max(BIT[index] , value);
        index += (index & (-index));
    }
}
//max query
int query(int index){
    int ans =0;
    while(index > 0){
        ans = max(BIT[index] , ans);
        index -= (index & (-index));
    }
    return ans;
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
        int index;
        cin>>index;
        cout<<query(index)<<endl;
    }
    return 0;
}
