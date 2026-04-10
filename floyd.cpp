#include<iostream>
using namespace std;
int main()
{
   int n;
   cout << "ENTER NO OF VERTICES:" << endl;
   cin>>n;
   int D[n][n];
   //cout << "ENTER WEIGHT OF THE MATRIX:" << endl;
   cout << "ENTER PATH (9999 FOR NO PATH):" << endl;
   for (int i=0;i<n;i++)
   {
      for (int j=0;j<n;j++)
      {
         cin >> D[i][j];
      }
   }
   for (int k=0;k<n;k++)
   {
      for (int i=0;i<n;i++)
      {
         for (int j=0;j<n;j++)
         {
            if (D[i][k] + D[k][j] < D[i][j])
            {
               D[i][j] = D[i][k] + D[k][j];
            }
         }
      }
   }
   cout << "SHORTEST DISTANCE MATRIX:" << endl;
   for (int i=0;i<n;i++)
   {
      for (int j=0;j<n;j++)
      {
         cout << D[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}
