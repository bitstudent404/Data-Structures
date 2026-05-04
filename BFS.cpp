#include <iostream>
#include <ctime>
#include <queue>
using namespace std;

void BFS(int graph[10][10], int n, int start) {
    bool visited[10] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
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
    cout << "BFS Traversal: ";
    BFS(graph, n, start);
    return 0;
}