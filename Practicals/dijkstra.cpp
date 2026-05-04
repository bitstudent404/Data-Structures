#include <iostream>
using namespace std;

#define V 5
#define INF 1000000

// Find minimum distance node
int minDistance(int dist[], bool visited[]){
    int min = INF, min_index;

    for (int i = 0; i < V; i++){
        if (!visited[i] && dist[i] < min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra function
void dijkstra(int graph[V][V], int src){
    int dist[V];
    bool visited[V];

    // Initialize
    for (int i = 0; i < V; i++){
        dist[i] = INF;
        visited[i] = false;
    }

    dist[src] = 0;

    // Main loop
    for (int count = 0; count < V - 1; count++){
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++){
            if (!visited[v] && graph[u][v] &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]){
                    
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // ✅ PRINT RESULT (IMPORTANT)
    cout << "\nVertex\tDistance from Source\n";
    for (int i = 0; i < V; i++){
        cout << i << "\t" << dist[i] << endl;
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

    dijkstra(graph, 0);

    return 0;
}
