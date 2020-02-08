#include<bits/stdc++.h>
using namespace std;

int first_occurence(int a[], int n , int key){
    int start = 0 , end =n-1 , mid;
    int ans =-1;
    while(start<=end){
        mid = (start+end)/2;
        if(a[mid] == key){
            ans = mid;
            end = mid-1;
        }else if(a[mid] > key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
}

int last_occurence(int a[], int n , int key){
    int start = 0 , end =n-1 , mid;
    int ans =-1;
    while(start<=end){
        mid = (start+end)/2;
        if(a[mid] == key){
            ans = mid;
            start = mid+1;
        }else if(a[mid] > key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    int a[]= {1 , 2 , 2 , 2 , 2 , 4  ,7};
    int n   =  7;
    cout<<"First Occurence"<<first_occurence(a , n , 2)<<endl;
    cout<<"Last Occurence"<<last_occurence(a , n , 2)<<endl;
   cout<<"Total number of elements: "<<last_occurence(a , n, 2)-first_occurence(a , n , 2)+1<<endl;
   cout<<"By Using Predefined Functions Are:"<<endl;

   int id1 = lower_bound(a , a+n , 2)-a;
   int id2 = upper_bound(a , a+n , 2)-a;
   cout<<"first occurence of 2 is->"<<id1<<endl; // 1
   cout<<"last occurence of 2 is->"<<id2<<endl;    // 5
   cout<<"Total occurences of 2 ->"<<(id2-id1)<<endl; // 4

    int id3 = lower_bound(a , a+n , 3)-a;
   int id4 = upper_bound(a , a+n , 3)-a;
   cout<<"first occurence of 3 is->"<<id3<<endl; //5 
   cout<<"last occurence of 3 is->"<<id4<<endl;  //5
   cout<<"Total occurences of 2 ->"<<(id4-id3)<<endl; //0
    return 0;
}