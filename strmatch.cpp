#include<iostream>
#include<cstring>
using namespace std;
int main()
{
   int k=0,l=0;
   string text;
   string pattern;
   cout << "ENTER THE TEXT:" << endl;
   getline(cin,text);
   cout << "ENTER THE PATTERN:" << endl;
   getline(cin,pattern);
   int tcount=0;
   while(text[k]!='\0')
   {
      tcount++;
      k++;
   }
   int pcount=0;
   while(pattern[l]!='\0')
   {
      pcount++;
      l++;
   }
   int n = tcount;
   int m = pcount;
   bool found = false;
   for (int i=0;i<=n-m;i++)
   {
      int j=0;
      while(j<m && text[i+j]==pattern[j])
      {
         cout <<
         j++;
      }
      if (j==m)
      {
         cout << "THE PATTERN FOUND AT INDEX: " << i << endl;
         found = true;
      }
   }
   if(!found)
   {
      cout << "PATTERN NOT FOUND!\n";
   }
   return 0;
}