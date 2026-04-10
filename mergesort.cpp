#include<iostream>
using namespace std;
void merge(int a[],int l,int m,int r)
{
   int i=l,j=m+1,k=0;
   int temp[50];
   while(i<=m && j<=r)
   {
      if(a[i]<=a[j])
      {
         temp[k++] = a[i++];
      }
      else
      {
         temp[k++] = a[j++];
      }
   }
   while(i<=m)
   {
      temp[k++] = a[i++];
   }
   while(j<=r)
   {
      temp[k++] = a[j++];
   }
   for(int i=l,k=0;i<=r;i++,k++)
   {
      a[i] = temp[k];
   }
}
void mergesort(int a[],int l,int r)
{
   if(l<r)
   {
      int m = (l+r)/2;
      mergesort(a,l,m);
      mergesort(a,m+1,r);
      merge(a,l,m,r);
   }
}
int main()
{
   int n,a[20];
   cout<<"ENTER NO OF ELEMENTS:";
   cin>>n;
   cout<<"ENTER ELEMENTS:"<<endl;
   for(int i=0;i<n;i++)
   {
      cin>>a[i];
   }
   mergesort(a,0,n-1);
   cout<<"SORTED ARRAY:";
   for(int i=0;i<n;i++)
   {
      cout<<a[i]<<" ";
   }
   cout << endl;
   return 0;
}