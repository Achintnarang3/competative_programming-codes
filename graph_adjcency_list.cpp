//Print The Adjanency List.
#include <iostream>
#include<list>
using namespace std;
class graph{
    int v;
    list<int> *l;
    public:

    graph(int e){
        v = e;
        l = new list<int> [v];
    }
    void addEdge(int v1 , int v2 , bool bidir = true){
        l[v1].push_back(v2);
        if(bidir == true){
            l[v2].push_back(v1);
        }
    }
    void printAdjList(){
        for(int i=0 ; i<v ; i++){
            cout<<i<<"->";
            for(int vertex : l[i] ){
                cout<<vertex<<" ,";
            }
            cout<<endl;
        }
    }
};
int main() {

  graph g(5);
  g.addEdge(0 , 4);
  g.addEdge(0 , 1);
  g.addEdge(4 , 3);
  g.addEdge(1 , 2);
  g.addEdge(2 , 3);
  g.addEdge(1 , 3);

  g.printAdjList();
  return 0;
}
