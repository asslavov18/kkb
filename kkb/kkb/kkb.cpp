#include <iostream> 
#include <vector>
#include <string>
using namespace std;
int toNumber(string a) {
	int c=1;
	int sum = 0;
	for (int i = a.size()-1; i >= 0; i--)
	{
		sum += (a[i] - 48) * c;
		c *= 10;
	}
	return sum;

}

bool Menu()
{
	vector<vector<int>> a;
	int n,b;
	cout << "Enter the number of arrays";
	cin >> n;
	string m,c;
	for (int i = 0; i <= n; i++) {
		getline(cin, m);
		b = m.find(" ");
		c = m.substr(0, b);
		cout << toNumber(c) << endl;
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