#include <iostream>
using namespace std;
void sumMatrix(int mat[3][3], int sec[3][3], int res[3][3]) 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            res[i][j] = mat[i][j] + sec[i][j];
        }
    }
}

int main() 
{
    int orig[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int trans[3][3];
    
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            trans[j][i] = orig[i][j];
        }
    }
    
    int res[3][3];

    sumMatrix(orig, trans, res);

    cout << "Результат сложения:\n";
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}