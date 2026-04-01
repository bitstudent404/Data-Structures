# include <iostream>
#include <climits>
using namespace std;

#define MAX 100

void prims(int graph[MAX][MAX], int v){
    bool selected[MAX] = {false};

    selected[0] = true;

    int no_edge = 0;
    int total_cost = 0;

    cout << "\nEdges in MST:\n";

    while (no_edge < v - 1){
        int min = INT_MAX;
        int x = 0,y = 0;
         for (int i = 0; i< v; i++){
            if (selected[i]){
                for (int j = 0; j < v; j++){
                    if (!selected[j] && graph[i][j]){
                        if (min > graph[i][j]){
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
         }
         cout << x << "-" << y << ":" << graph[x][y] << endl;
         total_cost += graph[x][y];
         selected[y] = true;
         no_edge++;
    }
    cout << "Total Cost of MST :" << total_cost << endl;
}

int main(){
    int v;
    int graph[MAX][MAX];

    cout << "Enter Number of Vertices: ";
    cin >> v;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i< v; i++){
        for (int j = 0; j < v; j++){
            cin >> graph[i][j];
        }
    }
    prims(graph,v);

    return 0;
}

