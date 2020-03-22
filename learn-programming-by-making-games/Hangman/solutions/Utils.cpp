/*
 * Utils.cpp
 *
 *  Created on: Sep 22, 2016
 *      Author: serge
 */


#include "Utils.h"
#include <iostream>
#include <cctype>

using namespace std;


char GetCharacter(const char * prompt, const char* error)
{

	const int IGNORE_CHARS = 256;

	char input;
	bool failure;

	do
	{
		failure = false;

		cout << prompt;
		cin >> input;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << error << endl;
			failure = true;
		}
		else
		{
			cin.ignore(IGNORE_CHARS, '\n');

			if(isalpha(input))
			{
				input = tolower(input);
			}
			else
			{
				cout << error << endl;
				failure = true;
			}
		}

	}while(failure);

	return input;
}

char GetCharacter(const char *prompt, const char* error, const char validInput[], int validInputLength)
{

	const int IGNORE_CHARS = 256;

	char input;
	bool failure;

	do
	{
		failure = false;

		cout << prompt;
		cin >> input;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			cout << error << endl;
			failure = true;
		}
		else
		{
			cin.ignore(IGNORE_CHARS, '\n');

			if(isalpha(input))
			{
				input = tolower(input);

				for(int i = 0; i < validInputLength; i++)
				{
					if(input == validInput[i])
					{
						return input;
					}
				}
			}

			cout << error << endl;
			failure = true;

		}

	}while(failure);

	return input;
}

void ClearScreen()
{
	//system("cls"); //for windows only!
	system("clear");
}


void WaitForKeyPress()
{
	//system("pause"); //Windows only!

	system("read -n 1 -s -p \"Press any key to continue...\";echo");
}


