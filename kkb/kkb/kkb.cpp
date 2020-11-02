#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
#include "Functions.h"
//startup

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