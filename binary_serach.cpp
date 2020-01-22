#include <iostream>
using namespace std;
int binary_search(int a[], int n , int key){
    int start = 0  , end =n-1;
    int mid;
    while(start<=end){
        mid = (start+end)/2;
        
        if(a[mid] == key){
            //found 
            return mid;
        }else if(a[mid] > key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return -1;
}
int main() {
    int n;
    cin>>n;
    int a[n] , key;
    for(int i=0 ; i<n ; i++){
        cin>>a[i];
    }
    cout<<"Enter the element you want to search: " ;
    cin>>key;
    cout<<endl;
    int serach_index = binary_search(a , n , key);
    if(serach_index == -1){
        cout<<key<<" is not found"<<endl;
    }else
    cout<<key<<" is present at: "<<serach_index<<endl;

    return 0;
}
