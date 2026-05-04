#include <iostream>
#include <ctime>
using namespace std;    
#define V 5
#define INF 1000000
void topologicalSortUtil(int graph[V][V], int v, bool visited[], int &index, int stack[]){
    visited[v] = true;

    for (int i = 0; i < V; i++){
        if (graph[v][i] && !visited[i]){
            topologicalSortUtil(graph, i, visited, index, stack);
        }
    }

    stack[index++] = v;
}

void topologicalSort(int graph[V][V]){
    bool visited[V];
    int stack[V];
    int index = 0;

    for (int i = 0; i < V; i++){
        visited[i] = false;
    }

    for (int i = 0; i < V; i++){
        if (!visited[i]){
            topologicalSortUtil(graph, i, visited, index, stack);
        }
    }

    cout << "Topological Sort: ";
    for (int i = index - 1; i >= 0; i--){
        cout << stack[i] << " ";
    }
    cout << endl;
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
    topologicalSort(graph);
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nTime taken: " << time_taken << " seconds" << endl;

    return 0;
}