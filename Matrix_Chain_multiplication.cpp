#include<iostream>
using namespace std;

int mul_num(int arr[],int n)
{
    int sol[n][n]={0};
    for(int d=1;d<n-1;d++)
    {
        for(int i=1;i<n-d;i++)
        {
            int j=i+d;
            int min=32767;
            for(int k=i;k<=j-1;k++)
            {
                int cost=sol[i][k]+sol[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(cost<min)
                {
                    min=cost;
                }
            }
            sol[i][j]=min;
        }
    }
    return sol[1][n-1];
}
int main()
{
    int n;
    cout<<"Enter the size of sequence array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the sequnce array\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"The least required number of multiplications are: "<<mul_num(arr,n);
    return 0;
}