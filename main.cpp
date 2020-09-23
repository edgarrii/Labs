#include <bits/stdc++.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "Enter the size of the array, press ENTER and enter the array itself:" << endl;
	int n;
	cin >> n;

	//received the matrix size
	int** a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	int el = 0;
	//has allocated a place for the matrix and the element you are looking for
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			cin >> a[i][k];
			if (abs(a[i][k]) > el)
				el = abs(a[i][k]);
		}
	}
	//got an array and max element by module
	int xd, yd;
	bool flag = false;
	//coordinates of the searched number, flag proverki poiska
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			if (a[i][k] == el)
			{
				flag = true;
				yd = i;
				xd = k;
				break;
			}
		}
		if (flag == true)
			break;
	}

	cout << "\n";

	if (flag == false)
	{
		cout << "Integer is not found";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (yd != i)
		{
			for (int k = 0; k < n; k++)
			{
				if (xd != k)
				{
					cout << a[i][k] << " ";
				}
			}
			cout << "\n";
		}
	}

	cout << "\n";



	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
	//relieved the memory

	return 0;
}
