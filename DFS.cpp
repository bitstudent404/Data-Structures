#include <iostream>
usiing namespace std;

void DFS(int graph[10][10], int n, int start, bool visited[10]) {
    visited[start] = true;
    cout << start << " ";

    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(graph, n, i, visited);
        }
    }
}

int main(){
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;       
    int graph[10][10];

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    int start;
    cout << "Enter the starting vertex: ";      
    cin >> start;
    bool visited[10] = {false};
    cout << "DFS Traversal: ";
    DFS(graph, n, start, visited);
    return 0;
}