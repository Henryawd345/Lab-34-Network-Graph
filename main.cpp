#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

class Graph{
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int vertices) : V(vertices){
        adj.resize(V);
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

    }

    void printAdjacencyList() const{
        cout << "Graph's adjacency list: " << endl;
        for (int i = 0; i < V; i++){
            cout << i << " --> ";
            for (const auto &edge : adj[i]){
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            cout << endl;
        }
    }

    void DFS(int start) const{
        vector<bool> visited(V, false);
        stack<int> st;

        cout << "DFS starting from vertex " << start << ":" << endl;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                visited[node] = true;
                cout << node << " ";

                for (const auto &edge : adj[node]){
                    int neighbor = edge.first;
                    if (!visited[neighbor]) {
                        st.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }

    void BFS(int start) const {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS starting from vertex " << start << ":" << endl;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (const auto &edge : adj[node]) {
                int neighbor = edge.first;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};




int main() {




}