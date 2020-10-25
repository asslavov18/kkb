#include <iostream> 
#include <vector>
#include <string>

using namespace std;
int stringToNumber(string numTxt) {
	// will do later
	return 0;
}

void divideStrings(string line) {
	vector<int> numsArr;
	while (line.find(" ") != string::npos)
	{
		cout << line.substr(0, line.find(" ")) << endl;
		stringToNumber(line.substr(0, line.find(" ")));
		line = line.substr(line.find(" ") + 1, line.size() - line.find(" ") + 1);
	}
	cout << line;
	stringToNumber(line);
}



bool Menu()
{
	vector<string> lines;
	string line;
	int arrays;
	cin >> arrays;
	cin.ignore();
	for (int i = 0; i < arrays; i++)
	{
		getline(cin, line);
		lines.push_back(line);
	}
	for (int i = 0; i < arrays; i++)
	{
		cout << lines[i] << endl;
	}
	divideStrings(lines[0]);
	return true;
}

int main()
{
	while (Menu());
}