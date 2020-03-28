#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{

    map<T , list<T>> adj;
    public:
    graph(){
        //map uses dynamic memory allocation , so no need to input number of edges.
    }
    void addEdge(T u , T v , bool bidir){
       
       adj[u].push_back(v);
       if(bidir == true){
           adj[v].push_back(u);
       }
    }

    void print(){

        for(auto i : adj){
            cout<<i.first<<" -> ";
            for(auto entry : i.second){
                cout<<entry<<" , " ;
            }
            cout<<endl;
        }
    }
};
int main(){
     
     graph<string> g1;
     g1.addEdge("putin" , "modi" , false);
     g1.addEdge("putin" , "trumo" , false);
     g1.addEdge("putin" , "pope" ,false);
     g1.addEdge("modi" ,"trump" , true);
     g1.addEdge("modi" , "yogi" , true);
     g1.addEdge("yogi", "prabhu" , false);
     g1.addEdge("prabhu" , "modi" , false);
     
     g1.print();
    return 0;
}