#include "MatrixChainOrder.h"
#include <vector>
using namespace std;

int MatrixMultiplay::MatrixChainOrder(vector <int> test)
{
    int n = test.size() - 1;
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i].push_back(0);
        }
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int l = 1; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            int j = i + l;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j],
                    dp[i][k] + dp[k + 1][j] + test[i] * test[k + 1] * test[j + 1]);
            }
        }
    }
    return dp[0][n - 1];


}