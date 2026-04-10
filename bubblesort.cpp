#include<iostream>
using namespace std;
int main()
{
   int temp,n;
   cout<<"ENTER THE NO OF ELEMENTS:\n";
   cin >> n;
   int a[n];
   cout << "ENTER THE ELEMENTS:\n";
   for (int i=0;i<n;i++)
   {
      cin>>a[i];
   }
   for (int i=0;i<n-1;i++)
   {
      int flag = 0;
      for (int j=0;j<n-1-i;j++)
      {
         if (a[j]>a[j+1])
         {
            temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
            flag = 1;
         }
      }
      if(!flag)
      {
         break;
      }
   }
   cout<<"BUBBLE SORT!\n";
   cout << "SORTED ARRAY IS :\n";
   for (int i=0;i<n;i++)
   {
      cout << a[i] << "\t";
   }
   cout << "\n";
}
