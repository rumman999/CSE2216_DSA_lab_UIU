#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Graph{
    int V;
    bool directed;
    int adj[100][100];

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


    vector<int> shortestPath(int start){
        vector<int> dist(V, INT_MAX);

        queue<int> q;
        q.push(start);
        dist[q.front()] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v=0;v<V;v++){
                if(adj[u][v]==1){
                    if(dist[v]>dist[u]+1){
                        dist[v]=dist[u]+1;
                        q.push(v);
                    }
                }
            }

        }

        return dist;

    }
};

int main(){

    Graph g(5,false);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,4);
    g.addEdge(3,4);
 
    
    vector<int> distances = g.shortestPath(0);

    for(int i: distances){
        if(i==INT_MAX){
            cout << -1 << " ";
        } else{
            cout << i << " ";
        }
    }

    cout << endl;
    
    return 0;
}