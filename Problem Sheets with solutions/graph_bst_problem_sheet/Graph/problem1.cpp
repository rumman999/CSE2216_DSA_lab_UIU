#include <iostream>
using namespace std;

class Graph{
    int V;
    bool directed;
    int adj[100][100];
    int visited[100];

public:
    Graph(int v, bool dir){
        V = v;
        directed = dir;

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v){
        u--;
        v--;
        adj[u][v] = 1;

        if(!directed) adj[v][u] = 1;
    }

    void printAdjMatrix(){
        cout << "Adjacency Matrix: " << endl;

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                 cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printAdjList(){
        cout << "Adjacency List: " << endl;

        for(int i=0;i<V;i++){
            cout << i+1 << ": ";
            for(int j=0;j<V;j++){
                 if(adj[i][j]==1){
                    cout << j+1 << " ";
                 }
            }
            cout << endl;
        }
    }
};

int main(){

    Graph g(4,false);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.printAdjMatrix();
    g.printAdjList();

    return 0;
}