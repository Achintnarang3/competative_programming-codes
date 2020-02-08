#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool isValid(ll books[] , ll n , ll k , ll ans){
    int students = 1;
    ll current_pages = 0;
    for(int i=0 ; i<n ;i++){
        if(current_pages+books[i] > ans){
            current_pages = books[i];
            students++;
            if(students > k){
                return false;
            }
        }else{
            current_pages += books[i];
        }
    }
    return true;
}

ll binarySearchBooks(ll books[] , ll n , ll k){
    ll total_pages = 0;
    ll s = 0 , e = 0 , mid;
    for(int i=0; i<n ; i++){
        total_pages += books[i];
        s = max(s , books[i]);
    }
    e = total_pages;
    ll finalAns = s;
    while(s<=e){
        mid =(s+e)/2;

        if(isValid(books , n , k , mid)){
            finalAns = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return finalAns;
}

int main(){
    ll n , k ;
    ll books[100005];

    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>books[i];
    }
    ll ans = binarySearchBooks(books , n , k);
    cout<<ans;
    return 0;
}