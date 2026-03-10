#include <iostream>
#include <queue>
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

    void BFS(int start) {
        if (start < 0 || start >= vertices) {
            cout << "Invalid starting vertex!" << endl;
            return;
        }

        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS from vertex " << start << ": ";
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[v][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void BFSAll() {
        vector<bool> visited(vertices, false);
        queue<int> q;

        cout << "BFS (all components): ";
        for (int start = 0; start < vertices; start++) {
            if (!visited[start]) {
                visited[start] = true;
                q.push(start);

                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    cout << v << " ";

                    for (int i = 0; i < vertices; i++) {
                        if (adjMatrix[v][i] && !visited[i]) {
                            visited[i] = true;
                            q.push(i);
                        }
                    }
                }
            }
        }
        cout << endl;
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

    int getVertices() {
        return vertices;
    }
};

int main() {
    int vertices, edges;
    
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (source destination):" << endl;
    for (int i = 0; i < edges; i++) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    // Display the graph
    g.printMatrix();

    // BFS from a specific vertex
    int start;
    cout << "\nEnter starting vertex for BFS: ";
    cin >> start;
    g.BFS(start);

    // BFS for all components
    g.BFSAll();

    return 0;
}

