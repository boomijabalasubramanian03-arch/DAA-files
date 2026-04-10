 #include <iostream>
using namespace std;
int length(char str[])
{
   int i=0;
   while(str[i]!='\0')
      i++;
   return i;
}
void ShiftTable(char pattern[],int m,int table[])
{
   for(int i=0;i<256;i++)
      table[i]=m;
   for(int i=0;i<m-1;i++)
      table[(int) pattern[i]]=m-1-i;
}
int horspool(char text[],char pattern[])
{
   int m=length(pattern);
   int n=length(text);
   int table[256];
   ShiftTable(pattern,m,table);
   int i=m-1;
   while(i<n)
   {
      int k=0;
      while(k<m && pattern[m-1-k]==text[i-k])
         k++;
      if(k==m)
         return i-m+1;
      i=i+table[(int) text[i]];
   }
   return -1;
}
int main()
{
   char text[200],pattern[100];
   cout<<"ENTER TEXT :";
   cin.getline(text,200);
   cout<<"ENTER PATTERN :";
   cin.getline(pattern,100);
   int pos=horspool(text,pattern);
   if(pos>0)
      cout<<"PATTERN FOUND AT POSITION :"<< pos << endl;
   else
      cout<<"PATTERN NOT FOUND!" << endl;
   return 0;
}
