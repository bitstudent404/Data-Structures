#include <iostream>
#include <ctime>
using namespace std;
#define V 5
#define INF 1000000

void primMST(int graph[V][V]){
    int parent[V];
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++){
        dist[i] = INF;
        visited[i] = false;
    }

    dist[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++){
        int min = INF, min_index;

        for (int v = 0; v < V; v++){
            if (!visited[v] && dist[v] < min){
                min = dist[v];
                min_index = v;
            }
        }

        visited[min_index] = true;

        for (int v = 0; v < V; v++){
            if (graph[min_index][v] && !visited[v] && graph[min_index][v] < dist[v]){
                parent[v] = min_index;
                dist[v] = graph[min_index][v];
            }
        }
    }

    cout << "\nEdge\tWeight\n";
    for (int i = 1; i < V; i++){
        cout << parent[i] << " - " << i << "\t" << graph[parent[i]][i] << endl;
    }
}

int main(){
    int graph[V][V];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            cin >> graph[i][j];
        }
    }

    clock_t start = clock();
    primMST(graph);
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nTime taken: " << time_taken << " seconds" << endl;

    return 0;
}