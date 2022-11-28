#include <iostream>
#include <vector>
#include "MatrixChainOrder.h"

using namespace std;


int main()
{
    vector <int> test = { 7 ,5, 3, 6, 5 };
    MatrixMultiplay mm;
    cout << (mm.MatrixChainOrder(test)) << endl;
}


