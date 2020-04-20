#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100005
int reset[MAX_N];

void KMP_preproccesing(string pat){
    int i=0 , j=-1;
    reset[0] = -1;
    while(i < pat.length()){
        while(j >=0 && pat[i] != pat[j]){
            j = reset[j];
        }
        i++;
        j++;
        reset[i] = j;
    }
}
void KMP_string_matching(string str , string pat){
    KMP_preproccesing(pat);
    int i=0 , j=0 ;
    while(i < str.length()){
        while(j>=0 && str[i] != pat[j]){
              j = reset[j];
        }
    i++;
    j++;
    if(j == pat.length()){
        cout<<"pattern is found at "<<i-j<<endl;
        j = reset[j];
    }
    }
}
int main() {
    for(int i=0 ; i<MAX_N ; i++){
        reset[i] = -1;
    }
    string str , pat;
    cin>>str>>pat;
    KMP_string_matching(str , pat);
    return 0;
}
