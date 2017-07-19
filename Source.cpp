#include <windows.h>
#include <iostream>
#include <string>
#include <random>
#include <thread>
#include <chrono>

using namespace std;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

string top = "_______";
string rope = "|   |";
string head = "|  (_)";
string arms = "| \\ | /";
string body = "|   |";
string legs = "|  / \\";
string bottom = "    |";
string stand = " _  | __";
int guesses = 8;

void slow_print(const string& message, unsigned int millis_per_char)
{
	for (const char c : message)
	{
		cout << c << flush;

		sleep_for(milliseconds(millis_per_char));
	}
}

void _top()
{
	if (guesses == 7)
	{
		cout << top << endl;
	}
}

void _rope()
{
	if(guesses == 6)
	{
		cout << top << endl;
		cout << rope << endl;
	}
}

void _head()
{
	if(guesses == 5) 
	{
		cout << top << endl;
		cout << rope << endl;
		cout << head << endl;
	}
}

void _arms()
{
	if(guesses == 4)
	{
		cout << top << endl;
		cout << rope << endl;
		cout << head << endl;
		cout << arms << endl;
	}
}

void _body()
{
	if (guesses == 3)
	{
		cout << top << endl;
		cout << rope << endl;
		cout << head << endl;
		cout << arms << endl;
		cout << body << endl;
	}
}

void _legs()
{
	if (guesses == 2)
	{
		cout << top << endl;
		cout << rope << endl;
		cout << head << endl;
		cout << arms << endl;
		cout << body << endl;
		cout << legs << endl;
	}
}

void _bottom()
{
	if (guesses == 1)
	{
		cout << top << endl;
		cout << rope << endl;
		cout << head << endl;
		cout << arms << endl;
		cout << body << endl;
		cout << legs << endl;
		cout << bottom << endl;
	}
}

void _stand()
{
	if (guesses == 0)
	{
		cout << top << endl;
		cout << rope << endl;
		cout << head << endl;
		cout << arms << endl;
		cout << body << endl;
		cout << legs << endl;
		cout << bottom << endl;
		cout << stand << endl;
	}
}

int main()
{
	string GameTitle = "Hangman";
	//SetConsoleTitle(_T(GameTitle));
	system("Color A");

	cout << "(c) Artemy Starikovich Games" << endl << endl;

	cout << "The Game starts." << endl;

	random_device rd;

	int x = rd() % 15;


	char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	string WordsToGuess[15] = { "apple", "banana", "orange", "coconut", "donkey", "electricity", "wizard", "knowledge", "successfully", "knob", "back", "understandable", "free", "uncle", "selection" };
	string word = WordsToGuess[x];

	char letter;

		string proc = word;
		for(int i = 0; i < proc.length(); i++)
		{
			proc[i] = '_';
		}

	while(true)
	{
		if(guesses != 0)
		{
			slow_print("Guess a letter", 30);
			cout << endl << endl;
		}
		if(guesses < 0)
		{
			guesses = 0;
		}
		cin >> letter;
		cout << endl;
		if(guesses == 0)
		{
			string message = "Hangman is dead :C";
			slow_print(message, 30);

			cout << endl << "Game OVER!" << endl;

			Sleep(5000);
			exit(1);
		}




		bool isInWord = false;
		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] == letter)
			{
				isInWord = true;
				if(word[i] == letter)
				{
					proc[i] = letter;
				}
				string correct = "Correct - " + proc;
				slow_print(correct, 30);
				cout << endl;

				if(proc == word)
				{
					cout << endl << endl << "Congratulations, You won!" << endl << endl;
					Sleep(5000);
					exit(1);
				}
			}
		}

		if(isInWord == false)
		{
			guesses -= 1;
			if(guesses > 0)
			{
				if (letter ==  '0' || letter == '1' || letter == '2' || letter == '3' || letter == '4' || letter == '5' || letter == '6' || letter == '7' || letter == '8' || letter == '9')
				{
					cout << "Enter a letter, not a number you idiot, you have " << guesses << " guesses left." << endl;
				}
				else{
					cout << "Incorrect, you now have " << guesses << " guesses left" << endl;
				}
				
			}
			_top();
			_rope();
			_head();
			_arms();
			_body();
			_legs();
			_bottom();
			_stand();
		}
	}

}
