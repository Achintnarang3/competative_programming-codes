#include<iostream>
using namespace std;
void bubblesort(int a[] , int n , int j){
    //base case
    if(n == 1){
        return;
    }
    if(j == n-1){
       return bubblesort(a , n-1 , 0);
    }
    if(a[j] > a[j+1]){
        swap(a[j] , a[j+1]);
    }
    bubblesort(a , n , j+1);
    return;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bubblesort(a , n , 0);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}