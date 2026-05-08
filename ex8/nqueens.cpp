#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int x[100];
bool place(int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}
void printBoard(int n)
{
    cout << "\nSolution:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}
void NQueens(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                printBoard(n);
                exit(0);
            }
            else
            {
                NQueens(k + 1, n);
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    NQueens(1, n);
    return 0;
}
