#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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


    vector<int> shortestPath(int start, int dest){
        vector<int> dist(V, INT_MAX);
        vector<int> parent(V, -1);

        queue<int> q;
        start--;
        dest--;
        q.push(start);
        dist[start]=0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v=0;v<V;v++){
                if(adj[u][v] == 1){
                    if(dist[u]+1<dist[v]){
                        dist[v] = dist[u]+1;
                        q.push(v);
                        parent[v] = u;
                    }
                }
            }
        }

        vector<int> path;

        int curr = dest;

        if(dist[dest]==INT_MAX) {
            return {};
        }

        while(curr != -1){
            path.push_back(curr+1);
            curr = parent[curr];
        }

        reverse(path.begin(), path.end());

        return path;
    }
};

int main(){

    Graph g(6,false);

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(4,6);
    g.addEdge(5,6);
 

    g.init();
    
    vector<int> path = g.shortestPath(1,6);

    for(int i: path){
        cout << i << " ";
    }

    cout << endl;
    
    return 0;
}