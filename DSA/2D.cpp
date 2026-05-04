#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int W) {
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w],
                               value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            } 
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n), value(n);

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    int result = knapsack(weight, value, W);

    cout << "Maximum value that can be obtained = " << result << endl;

    return 0;
}