#include <iostream>
using namespace std;
int searchIn(int a[] , int start , int end , int key){
    int mid = (start+end)/2;
    //base case
    if(start > end){
        return -1;
    }
    //recursive case
    if(a[mid] == key){
        return mid;
    }
    if(a[start] <= a[mid]){   //left part is sorted
          if(key >= a[start] && key <= a[mid]){  // checking in left part
              return searchIn(a , start , mid-1 , key);
          }else{
              return searchIn(a , mid+1, end , key);  // checking in right part
          }
    }
    if(key >= a[mid] && key <= a[end]){      // seraching in right part
        return searchIn(a , mid+1 , end , key);
    }else{
        return searchIn(a , start , mid-1 , key);
    }
}
int main() {
    
    int a[] = {5 , 6, 7 , 1 , 2 , 3 , 4};
    int key;
    cin>>key;
    cout<<"The element is present at index "<<searchIn(a , 0 , 6 , key);
    return 0;
}
