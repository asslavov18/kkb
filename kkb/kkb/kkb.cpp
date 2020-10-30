#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
//startup
using namespace std;
/*
vector<int> template(vector<vector<int>>){
	

}
*/
int stringToNumber(string numTxt) {
	int base = 1;
	int num = 0;
	for (int i = numTxt.size()-1; i >= 0; i--)
	{
		num += (numTxt[i] - 48) * base;
		base *= 10;
	}
	return num;
}

vector<int> divideStrings(string line) {
	vector<int> numsArr;
	while (line.find(" ") != string::npos)
	{		
		numsArr.push_back(stringToNumber(line.substr(0, line.find(" "))));
		line = line.substr(line.find(" ") + 1, line.size() - line.find(" ") + 1);
	}
	numsArr.push_back(stringToNumber(line));
	return numsArr;
}



bool Menu(fstream& inputs)
{ 
	vector<vector<int>> sets;
	string line;
	int arrays;
	cout << "Enter the numbers of arrays or -1 if u want to quit. " << endl;
	cin >> arrays;
	if (arrays == -1)
	{
		return false;
	}
	cin.ignore();
	for (int i = 0; i < arrays; i++)
	{
		getline(cin, line);
		inputs << line;
		inputs << "\n";
		sets.push_back(divideStrings(line));
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
	fstream inputs;
	string line;
	inputs.open("Inputs.txt");
	if (inputs.is_open())
	{
		while (Menu(inputs));
	}
	inputs.close();
}