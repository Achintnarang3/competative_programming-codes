#include <bits/stdc++.h>
using namespace std;
int longest_consecutive_subsequence_1(int a[]  , int n){ // O(max - min)
    map<int , bool> mp;
    int maximum = INT_MIN;
    int minimum = INT_MAX;
    for(int i=0 ; i<n ; i++){
        mp[a[i]] = true;
        maximum = max(maximum , a[i]);
        minimum = min(minimum , a[i]);
    }
    int count = 0  , ans = 0;
    for(int i=minimum ; i<=maximum+1 ; i++){
        if(mp[i] == true){
            count++;
        }else{
           ans = max(ans , count);
           count = 0;
        }
    }
    return ans;
}
int longest_consecutive_subsequence_2(int a[]  , int n){ // O(n) time
    unordered_set<int> s;
    for(int i=0 ; i<n ; i++){
        s.insert(a[i]);
    }
    int ans = 0;
    for(int i=0 ; i<n  ; i++){
        if(s.find(a[i]-1) != s.end()){
            continue;
        }else{
            int count =0;
            int  x = a[i]; // left boundry
            while(s.find(x) != s.end()){
                count++;
                x++;
            }
            ans = max(ans  ,  count);
        }
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    cout<<longest_consecutive_subsequence_1(a , n)<<endl;
    cout<<longest_consecutive_subsequence_2(a , n)<<endl;
    return 0;
}
