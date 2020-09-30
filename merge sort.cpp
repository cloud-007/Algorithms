///merge sort class
#include<iostream>
using namespace std;
int a[]={},temp[]={};
void mergesort(int l,int h)
{
    if(l==h)
        return;
    int mid=(l+h)/2;
    mergesort(l,mid);
    mergesort(mid+1,h);
    int i=l,j=mid+1;
    for(int k=l; k<=h; k++)
    {
        if(j==h+1)
        {
            temp[k]=a[i++];
        }
        else if(i==mid+1)
        {
            temp[k]=a[j++];
        }
        else
        {
            if(a[i]<=a[j])
            {
                temp[k]=a[i++];
            }
            else
            {
                temp[k]=a[j++];
            }
        }
    }
    for(int k=l;k<=h;k++)
        a[k]=temp[k];
}

int main()
{
    int x;
    cin>>x;
    for(int i=0;i<x;i++)
        cin>>a[i];
    mergesort(0,x-1);
    for(int i=0;i<x;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}
