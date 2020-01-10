#include<iostream>
#include<vector>
using namespace std;

#define ull unsigned long long

int main(){
    vector<unsigned long long>v;
    ull n;
    cin>>n;
    for(int i =0 ; i<n;i++){
        ull num;
        cin>>num;
        if(n<=130){
            v.push_back(num);
        }
        if(n>=130){
            cout<<"Yes"<<endl;
            return 0;
        }
        //for smaller numbers apply brute force approach
        //we require 4 nested loops
        for(int i=0 ; i<n; i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        if((v[i]^v[j]^v[k]^v[l])== 0){
                            cout<<"Yes"<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}