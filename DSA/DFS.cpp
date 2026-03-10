#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int v) : vertices(v) {
        adjMatrix.resize(v, vector<int>(v, 0));
    }

    void addEdge(int src, int dest) {
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            adjMatrix[src][dest] = 1;
            adjMatrix[dest][src] = 1;
        }
    }

    void addDirectedEdge(int src, int dest) {
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            adjMatrix[src][dest] = 1;
        }
    }

    // Recursive DFS
    void DFS(int start) {
        if (start < 0 || start >= vertices) {
            cout << "Invalid starting vertex!" << endl;
            return;
        }

        vector<bool> visited(vertices, false);
        
        cout << "DFS from vertex " << start << ": ";
        DFSHelper(start, visited);
        cout << endl;
    }

    void DFSHelper(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[v][i] && !visited[i]) {
                DFSHelper(i, visited);
            }
        }
    }

    // Iterative DFS using stack
    void DFSIterative(int start) {
        if (start < 0 || start >= vertices) {
            cout << "Invalid starting vertex!" << endl;
            return;
        }

        vector<bool> visited(vertices, false);
        stack<int> s;

        visited[start] = true;
        s.push(start);

        cout << "DFS (iterative) from vertex " << start << ": ";
        while (!s.empty()) {
            int v = s.top();
            s.pop();
            cout << v << " ";

            for (int i = vertices - 1; i >= 0; i--) {
                if (adjMatrix[v][i] && !visited[i]) {
                    visited[i] = true;
                    s.push(i);
                }
            }
        }
        cout << endl;
    }

    // DFS for all components
    void DFSAll() {
        vector<bool> visited(vertices, false);
        
        cout << "DFS (all components): ";
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                DFSAllHelper(i, visited);
            }
        }
        cout << endl;
    }

    void DFSAllHelper(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[v][i] && !visited[i]) {
                DFSAllHelper(i, visited);
            }
        }
    }

    void printMatrix() {
        cout << "\nAdjacency Matrix:" << endl;
        cout << "   ";
        for (int i = 0; i < vertices; i++) cout << i << " ";
        cout << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool isEdge(int src, int dest) {
        return adjMatrix[src][dest] == 1;
    }
};

int main() {
    int v, e;
    
    cout << "Enter number of vertices: ";
    cin >> v;

    Graph g(v);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter edges (source destination):" << endl;
    for (int i = 0; i < e; i++) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    // Display the graph
    g.printMatrix();

    // DFS from a specific vertex
    int start;
    cout << "\nEnter starting vertex for DFS: ";
    cin >> start;
    g.DFS(start);

    // Iterative DFS
    g.DFSIterative(start);

    // DFS for all components
    g.DFSAll();


    return 0;
}

