#include<iostream>
using namespace std;
int main()
{
   int temp,n,min;
   cout << "ENTER THE SIZE OF THE ARRAY:" << endl;
   cin >> n;
   int a[n];
   cout << "ENTER THE ELEMENTS:"<< endl;
   for (int i=0;i<n;i++)
   {
      cin>>a[i];
   }
   for (int i=0;i<n-1;i++)
   {
      min = i;
      for (int j=i+1;j<n;j++)
      {
         if(a[j]<a[min])
         {
            min = j;
         }
      }
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
   }
   cout << "SELECTION SORT!\n";
   cout << "THE SORTED ARRAY IS :"<< endl;
   for (int k=0;k<n;k++)
   {
      cout << a[k] << "\t";
   }
   cout << "\n";
}
