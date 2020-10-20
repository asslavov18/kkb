#include <iostream> 
#include <vector>
using namespace std;
bool Menu()
{
	vector<vector<int>> a;
	vector<int> c;
	int n;
	int num;
	cout << "Enter the number of arrays";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		while (cin.get() != '\n')
		{
			cin >> num;
			c.push_back(num);
		}
		a.push_back(c);
		c.erase(c.begin(),c.end());
	}
	for (int i = 0;i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	/*
	1.obedinenie
	2.sechenie
	3.razlika
	4.simetrichna razlika
	5.Podmnojestvo
	*/
	return true;
}

int main()
{
	while (Menu());
}