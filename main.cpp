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

    void printNetworkTopology(const vector<string>& nodeNames, const vector<string>& nodeRoles) const {
    cout << "Data Center Network Topology:\n";
    cout << "=============================\n";

    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << " (" << nodeNames[i]
             << " - " << nodeRoles[i] << ") connects to:\n";

        for (const auto& edge : adj[i]) {
            int neighbor = edge.first;
            int latency = edge.second;
            cout << "  -> Node " << neighbor << " (" << nodeNames[neighbor]
                 << ") - Latency: " << latency << " ms\n";
            }
        cout << endl;
        }
    }


    void DFS(int start) const{
        vector<bool> visited(V, false);
        stack<int> st;

        st.push(start);

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

    Graph g(9);

    g.addEdge(0, 1, 8);
    g.addEdge(0, 2, 21);

    
    g.addEdge(1, 2, 6);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 4);

   
    g.addEdge(2, 7, 11);
    g.addEdge(2, 8, 8);

    
    g.addEdge(3, 4, 9);

    
    g.addEdge(5, 6, 10);
    g.addEdge(5, 7, 15);
    g.addEdge(5, 8, 5);

   
    g.addEdge(6, 7, 3);
    g.addEdge(6, 8, 7);

    vector<string> nodeNames = {
        "Gateway Router",   
        "Auth Server",      
        "Database Cluster",  
        "Logging Service",  
        "Cache Server",     
        "Media Server",      
        "Analytics Node",  
        "Backup Server",     
        "API Server"         
    };

    vector<string> nodeRoles = {
        "External entry point",
        "User authentication",
        "Stores application data",
        "Collects system logs",
        "Speeds up frequent reads",
        "Serves videos & images",
        "Runs reports & ML jobs",
        "Stores long-term backups",
        "Handles client API calls"
    };

    g.printNetworkTopology(nodeNames, nodeRoles);

    cout << "Network Trace (DFS) from Node 0 (Gateway Router):\n";
    cout << "Purpose: Simulating a deep diagnostic path through the network\n";
    g.DFS(0);

    cout << "\nLayer-by-Layer Network Inspection (BFS) from Node 0 (Gateway Router):\n";
    cout << "Purpose: Checking which services are reachable by increasing 'distance'\n";
    g.BFS(0);

    return 0;
}