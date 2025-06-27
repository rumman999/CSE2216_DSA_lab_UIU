#include <iostream>
#include <stack>
using namespace std;

class Graph{
    int V;
    bool directed;
    int adj[100][100];
    bool visited[100];

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
        }
    }

    void DFS(int start){
        stack<int> st;
        start--;
        st.push(start);
        visited[start] = true;

        cout << "DFS: ";
        while(!st.empty()){
            int u = st.top();
            st.pop();

            cout << u+1 << " ";
            for(int v=V-1;v>=0;v--){
                if(adj[u][v]==1 && !visited[v]){
                    st.push(v);
                    visited[v] = true;
                }
            }
        }
        cout << endl;
    }
};

int main(){

    Graph g(5,false);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,5);

    g.init();
    g.DFS(1);
    
    return 0;
}