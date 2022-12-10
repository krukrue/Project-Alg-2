#include "MatrixChainOrder.h"
#include <vector>
using namespace std;

/**
    \brief Method
    \author Nikita Kvashnin
    \version 1.0
    \date Prosinec 2022

    Reseni zadani metodou hrubou sily 
*/
int MatrixMultiplay::MatrixChainOrder(vector <int> test)
{
    int n = test.size() - 1;
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++) { ///< Naplneni vektoru 
        for (int j = 0; j < n; j++) {
            dp[i].push_back(0);
        }
    }
    for (int i = 0; i < n; i++) { ///< Naplneni vektoru
        dp[i][i] = 0;
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int l = 1; l < n; l++) { ///< Algoritm 
        for (int i = 0; i < n - l; i++) {
            int j = i + l;                 
            dp[i][j] = INT_MAX;  ///< Prumenna pro porovnani s maximalni hodnotou
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j],
                    dp[i][k] + dp[k + 1][j] + test[i] * test[k + 1] * test[j + 1]); ///< Vyhledavani minimalne hodnoty primou hrubou silou 
            }
        }
    }
    return dp[0][n - 1]; ///< Vraceni vysledku


}
/**
    \brief Method
    \author Nikita Kvashnin
    \version 1.0
    \date Prosinec 2022

    Reseni zadani rekurzivnou metodou 
*/
int MatrixMultiplay::MatrixChainOrderSub(vector <int> p, int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int mini = INT_MAX;
    int count;

    for (k = i; k < j; k++)
    {
        /*!
        Umisteni zavorek na ruzne mista mezi prvni a posledni matici, dale 
        rekurzivny vypocet pocet nasobeni pro kazdou zavorku a vrati minimalni hodnotu
        */
        count = MatrixChainOrderSub(p, i, k) + MatrixChainOrderSub(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        mini = min(count, mini);

    }

    return mini;
}