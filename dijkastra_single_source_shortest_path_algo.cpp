/*OUTPUT 
Agra is located at 2
Amritsar is located at 0
Bhopal is located at 4
Delhi is located at 1
Jaipur is located at 3
Mumbai is located at 7
*/
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
    map<T , list< pair<T , int>>> m;
    public:
    void addEdge(T u , T v , int dist , bool bidir = true){
        m[u].push_back(make_pair(v , dist));
        if(bidir == true){
            m[v].push_back(make_pair(u , dist));
        }
    }
    void printadjlist(){
        for(auto j : m){
            cout<<j.first<<"-->";
            for(auto l : m[j.first]){
                cout<<"("<<l.first<<","<<l.second<<")";
            }
            cout<<endl;
        }
    }
    void dijkastra(T src){
        map<T , int>dist;
        //set all the distances to infinity
        for(auto i : m){
            dist[i.first] = INT_MAX;
        }
        dist[src] = 0;
        //make a set to find out the node with a minimum distance and set by default sort according to first member
        set<pair<int , T>>s;
        s.insert(make_pair(0, src));

        while(!s.empty()){
            //find the pair at the front
            auto p = *(s.begin());
            T node = p.second;
            int nodedist = p.first;
            s.erase(s.begin());
            //iterate over the neighbours of the current node
            for(auto childpair : m[node]){
                if(nodedist + childpair.second < dist[childpair.first]){

                    //in set , updation  of particular is not possible 
                    //so we have remove the old pair and insert new pair to simulation updation
                    
                    T dest = childpair.first;
                    auto f = s.find(make_pair(dist[dest] , dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[dest] = nodedist + childpair.second;
                    s.insert(make_pair(dist[dest] , dest));
                }
            }
        }
        for(auto d : dist){
            cout<<d.first<<" is located at "<<d.second<<endl;
        }
    }
};

int main() {
    graph<string> india;
    india.addEdge("Amritsar" ,"Delhi" , 1);
    india.addEdge("Amritsar" ,"Jaipur" , 4);
    india.addEdge("Jaipur" ,"Delhi" , 2);
    india.addEdge("Jaipur" ,"Mumbai" , 8);
    india.addEdge("Bhopal" ,"Agra" , 2);
    india.addEdge("Mumbai" ,"Bhopal" , 3);
    india.addEdge("Agra" ,"Delhi" , 1);
    //india.printadjlist();
    india.dijkastra("Amritsar");
    return 0;
}

