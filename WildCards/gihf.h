#pragma once
#include <string>
#include <iostream>
#include <string>

using FString = std::string;

using namespace std;

//Global helper function: get correct user input
template<class T >
T GetUserInput(FString OutString)
{
	T UserInput;
	bool bValid = false;
	while (!bValid)
	{
		cout << OutString << endl;
		cin >> UserInput;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			auto TypeName = typeid(UserInput).name();
			cout << "Please enter correct input of " << TypeName << endl;
		}
		else
			bValid = true;
	}
	return UserInput;
};