#include<iostream>
using namespace std;
void heap(int a[], int n, int i)
{
    int large = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    int temp;

    if(left < n && a[left] > a[large])
        large = left;

    if(right < n && a[right] > a[large])
        large = right;

    if(large != i)
    {
        temp = a[i];
        a[i] = a[large];
        a[large] = temp;
        heap(a, n, large);
    }
}

int main()
{
    int n, temp;

    cout<<"ENTER NO OF ELEMENTS: ";
    cin>>n;

    int a[n];

    cout<<"ENTER ELEMENTS: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=n/2-1;i>=0;i--)
    {
        heap(a,n,i);
    }
    cout << "MAX HEAP:\n";
    cout<<"-------------------\n";
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i=n-1;i>0;i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heap(a,i,0);
    }
    cout<<endl;
    cout<<"SORTED ARRAY:\n";
    cout<<"--------------------\n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout << endl;

    return 0;
}