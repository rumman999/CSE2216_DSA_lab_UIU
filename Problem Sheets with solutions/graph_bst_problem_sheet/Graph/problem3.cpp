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

    void init(){
        for(int i=0;i<V;i++){
            colored[i] = -1;
        }
    }

    bool Bipartite(int start){
        queue<int> q;
        start--;
        q.push(start);
        colored[start] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v=V-1;v>=0;v--){
                if(adj[u][v]==1){
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

    Graph g(5,false);

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);
 

    g.init();
    
    if(g.Bipartite(1)){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    
    return 0;
}