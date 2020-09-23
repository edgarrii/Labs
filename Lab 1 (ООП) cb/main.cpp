#include <bits/stdc++.h>
using namespace std;

void show(int **arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<"  ";
    cout<<endl;
    }
}
int main()
{
    setlocale(LC_ALL,"Rus");
    int n;
    cout<<"Введите размер квадратной матрицы\n";
    do
    cin>>n;
    while(n<=0||n>1000);
    int **arr=new int *[n];
    cout<<"Введите массив с размером "<<n<<" x "<<n<<endl;
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    show(arr,n);
    int mod;
    cout<<"Введите модуль\n";
    cin>>mod;
    int max=arr[0][0]%mod;
    int a,b;
    a=b=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(max<(arr[i][j]%mod))
            {
                max=arr[i][j]%mod;
                a=i;
                b=j;
            }
        }
    }
    cout<<"Наибольший по модулю элемент = "<<max<<endl;
    int x,y;
    x=y=0;
    for(int i=0;i<n-1;i++)
    {
        y=0;
        if(a==i)x=1;
        for(int j=0;j<n-1;j++)
        {
            if(b==j)y=1;
            arr[i][j]=arr[i+x][j+y];
        }
    }
    show(arr,n-1);
    for(int i=0;i<n;i++)
        delete [] arr[i];
    system("pause");
    return 0;
}
