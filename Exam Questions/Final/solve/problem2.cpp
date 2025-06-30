#include <iostream>
#include <queue>
using namespace std;

class Graph{
    int V;
    bool directed;
    int adj[100][100];
    int colored[100];

public:
    Graph(int v, bool dir){
        V = v;
        directed = dir;

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                adj[i][j]=0;
            }
        }
    }

    void init(){
        for(int i=0;i<V;i++){
            colored[i] = -1;
        }
    }

    void addEdge(int u, int v){
        adj[u][v] = 1;

        if(!directed) adj[v][u] = 1;
    }

    void printAdjacencyMatrix(){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool checkBipartite(int start){
        queue<int> q;
        q.push(0);
        colored[0] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v=0;v<V;v++){
                if(adj[u][v] == 1){
                    if(colored[v] == -1){
                        colored[v] = !colored[u];
                        q.push(v);
                    }
                    else if(colored[v] == colored[u]){
                        return false;
                    }
                }
            }
        }

        return true;
    }

};

int main(){

    Graph g(4,true);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.init();

    if(g.checkBipartite(0)){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }

    return 0;
}