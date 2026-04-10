#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   int n,x1,x2,y1,y2;
   cout << "ENTER NO OF POINTS:"<< endl;
   cin >> n;
   double x[n],y[n];
   if (n<2)
   {
      cout << "ENTER ATLEAST 2 POINTS:"<< endl;
      return 0;
   }
   for (int i=0;i<n;i++)
   {
      cout << "ENTER X AND Y POINTS :"<< endl;
      cin >> x[i] >> y[i];
   }
   double mindis = 999999.0;
   for (int i=0;i<n;i++)
   {
      for(int j=i+1;j<n;j++)
      {
         double dist = sqrt(pow(x[j]-x[i],2)+pow(y[j]-y[i],2));
         if (dist<mindis)
         {
            mindis = dist;
            x1 = x[i];
            y1 = y[i];
            x2 = x[j];
            y2 = y[j];
         }
         cout << "DISTANCE BETWEEN THE POINTS (" << x[i] << "," << y[i] << "), (" << x[j] << "," << y[j] <<") IS : " << dist << endl;
         cout << "------------------------------------------------------------------\n";
      }
   }
   cout << "THE CLOSEST DISTANCE IS : "<< mindis << endl;
   cout << "THE POINTS HAVING SHORTEST DISTANCE ARE ( " << x1 << "," << y1 << " ),( "<<x2<<","<<y2<<" )\n";
   return 0;
}