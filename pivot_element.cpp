#include<iostream>
using namespace std;

int main(){
    int a[] = {6 ,7 , 1 , 2, 3 , 4 , 5};
    int n = sizeof(a)/sizeof(int);
    int start = 0, end = n-1 ,mid;

    while(start<=end){
        mid = (start+end)/2;
        if(a[mid] > a[mid+1] && mid<end){
            cout<<mid<<" ";
            break;
        }
        if(a[mid] < a[mid-1] && mid > start){
            cout<<mid-1<<" ";
            break;
        }
        if(a[mid] <= a[start]){
           end = mid-1;
        }else{
            start = mid+1;
        }
    }
    if(start > end){
        cout<<"pivot element is not found";
    }
    return 0;
}