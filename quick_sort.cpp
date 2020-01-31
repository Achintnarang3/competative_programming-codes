#include<bits/stdc++.h>
using namespace std;

int partition(int *a , int start , int end){
    int i = start-1;
    int j = start;
    int pivot = a[end];
    for(j = start ; j<=end-1 ; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i] , a[j]);
        }
    }
    swap(a[i+1] , a[end]); // moves the pivot element to its sorted position
    return i+1;
}

void quicksort(int *a , int start , int end){
    if(start >= end){
        return;
    }
    int p = partition(a , start , end);
    quicksort(a , start , p-1);
    quicksort(a , p+1 , end);
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n ;i++){
        cin>>a[i];
    }
    quicksort(a , 0 , n-1);

    for(int i=0 ; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
