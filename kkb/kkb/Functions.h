#pragma once
#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
//startup
using namespace std;

int stringToNumber(string numTxt)
{
	int base = 1;
	int num = 0;
	for (int i = numTxt.size() - 1; i >= 0; i--)
	{
		num += (numTxt[i] - '0') * base;  //converts from a char to numbers
		base *= 10;
	}
	return num;
}

vector<int> divideStrings(string line)
{
	vector<int> numsArr;
	//The loop which substracs the numbers from the string
	while (line.find(" ") != string::npos)
	{

		numsArr.push_back(stringToNumber(line.substr(0, line.find(" "))));
		line = line.substr(line.find(" ") + 1, line.size() - line.find(" ") + 1);
	}
	numsArr.push_back(stringToNumber(line));
	return numsArr;
}

vector<int> Union(vector<vector<int>> sets)
{
	vector<int> uni;
	size_t i, j, n;
	bool found;
	for (i = 0; i < sets.size(); i++)     //This loop litterates through all subvectors

	{
		for (j = 0; j < sets[i].size(); j++)  //This loop itterates through the current subvector
		{
			found = 0;
			for (n = 0; n < uni.size(); n++)  //This loop check if the choosen numbers are repeated
			{
				if (uni[n] == sets[i][j])
				{
					found = 1;
					break;
				}
			}
			if (found == 0) uni.push_back(sets[i][j]);
		}
	}
	return uni;
}
vector<int> Intersection(vector<vector<int>> sets)
{   //Declaring usable variables
	vector<int> inter;
	size_t i, j, n, tek;
	bool found, foundInAll;

	for (n = 0; n < sets[0].size(); n++)     //itterates trough the elements of the first subvector
	{
		tek = sets[0][n];
		foundInAll = 1;
		for (i = 1; i < sets.size(); i++)    //itterates trough all the subvectors
		{
			found = 0;
			for (j = 0; j < sets[i].size(); j++)  //itterates all the elements of the subvector
			{
				if (sets[i][j] == tek)            //check if Intersection is found
				{
					found = 1;
					break;
				}
			}
			//check if an Intersection is not found, so there is no need to continue
			if (found == 0)
			{
				foundInAll = 0;
				break;
			}
		}
		//checks if Intersection is found in all sets
		if (foundInAll)
		{
			found = 0;
			for (i = 0; i < inter.size(); i++)      //check if the numbers in the vector are repeated
			{
				if (inter[i] == tek)
				{
					found = 1;
					break;
				}
			}
			if (found == 0) inter.push_back(tek);
		}
	}
	return inter;
}
vector<int> Substraction(vector<vector<int>> sets)
{  //Declear unusable variables
	vector<int> sub;
	size_t i, j, n, tek;
	bool found, foundInNoSet;
	//Itterates through all the elements of the first sub vector
	for (n = 0; n < sets[0].size(); n++)
	{
		tek = sets[0][n];
		foundInNoSet = 1;
		//Itterates through all sub vectors 
		for (i = 1; i < sets.size(); i++)
		{
			found = 0;
			//Itterates through all the  elements of the current subvector 
			for (j = 0; j < sets[i].size(); j++)
			{
				if (sets[i][j] == tek)
				{
					found = 1;
					break;
				}
			}
			if (found == 1)
			{
				foundInNoSet = 0;
				break;
			}
		}
		if (foundInNoSet)
		{
			found = 0;
			for (i = 0; i < sub.size(); i++)
			{
				if (sub[i] == tek)
				{
					found = 1;
					break;
				}
			}
			if (found == 0) sub.push_back(tek);
		}
	}
	return sub;
}

void Print(vector<int> vec)        //prints all the elements of a vector
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

int Readint(string msg)
{
	int a;

	while (!(cin >> a))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Incorrect value!" << endl;
		cout << msg << endl;
	}

	return a;
}

bool Menu(fstream& inputs)
{
	vector<vector<int>> sets;
	string line;
	int arrays, choice;
	cout << "Enter the number of arrays or 0 if you want to quit. " << endl;
	arrays = Readint("Enter the number of arrays or 0 if you want to quit. ");
	if (arrays == 0)
	{
		cout << "Ok, bye";
		return false;
	} if (arrays < 0)
	{
		cerr << "Incorrect input. Try again!" << endl;
		return true;
	}
	cout << "Ok, now enter your sets and press ENTER after each one." << endl;
	cin.ignore();
	for (int i = 0; i < arrays; i++)
	{
		getline(cin, line);
		inputs << line;
		inputs << "\n";
		sets.push_back(divideStrings(line));
	}
	cout << "Ok, now choose the operation you need: " << endl;
	cout << "1.Union." << endl;
	cout << "2.Intersection." << endl;
	cout << "3.Substraction." << endl;
	choice = Readint("Enter your choice again. ");
	if (choice < 1 || choice > 3)
	{
		cerr << "Incorrect input. Try again!" << endl;
		return true;
	}


	if (choice == 1) {
		cout << "The Union Of the sets is:" << endl;
		Print(Union(sets));
	}
	if (choice == 2) {
		cout << "The Intersection Of the sets is:" << endl;
		Print(Intersection(sets));
	}
	if (choice == 3) {
		cout << "The Substraction Of the sets is:" << endl;
		Print(Substraction(sets));
	}
	return true;
}
