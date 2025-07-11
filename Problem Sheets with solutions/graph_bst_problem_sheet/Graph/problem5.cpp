#include <iostream>
#include <stack>
using namespace std;

class Graph{
    int V;
    bool directed;
    int adj[100][100];
    bool visited[100];
    bool pathVisited[100];

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
            visited[i] = false;
            pathVisited[i]= false;
        }
    }

    bool dfs(int i){
        visited[i] = true;
        pathVisited[i] = true;

        for(int v=0;v<V;v++){
            if(adj[i][v]==1){
                if(!visited[v]){
                    if(dfs(v)) return true;
                }
                else if(pathVisited[v]){
                    return true;
                }
            }
        }
        pathVisited[i] = false;
        return false;
    }

    bool hasCycle(){
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i))
                    return true;
            }
        }
        return false;
    }
    
};

int main(){

    Graph g(4,true);

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,2);

    g.init();

    if(g.hasCycle()){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    
    return 0;
}