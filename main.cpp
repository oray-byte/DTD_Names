// Author: @Owen Miller-Fast (oray-byte)
// Date: 08/16/2021

#ifdef _WIN32
const char clearCommand[4] = "cls";
#else
const char clearCommand[6] = "clear";
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::string;
using std::cin;

void saveState(ifstream& fin, const string& fileName, vector<string>& state);
void inputData(ofstream& fout, ifstream& fin, const string& fileName, vector<string>& state);
void addState(ofstream& fout, const string& fileName, vector<string>& state);
void showInfo(ifstream& fin, const string& fileName, vector<string>& state);

int main()
{
	ifstream fin;
	ofstream fout;
	vector<string> state;

	saveState(fin, "output.txt", state);
	inputData(fout, fin, "output.txt", state);
	addState(fout, "output.txt", state);

	return 0;
}

void saveState(ifstream& fin, const string& fileName, vector<string>& state)
{
	fin.open(fileName);
	string temp;

	while (getline(fin, temp))
	{
		state.push_back(temp);
	}

	fin.close();
}

void inputData(ofstream& fout, ifstream& fin,  const string& fileName, vector<string>& state)
{
	fout.open(fileName);
	int userInput = 0;
	string temp;
	bool exitCondition = true;

	while (exitCondition)
	{
		cout << "[1] Enter data\n[2] View Data\n[3] Exit" << endl;
		cout << "\nYour input: ";
		cin >> userInput;
		cin.clear();
		cin.ignore();

		switch (userInput)
		{
			case 1:
				system(clearCommand);
				cout << "Name: ";
				getline(cin, temp);
				fout << "Name: " << temp << endl;

				system(clearCommand);
				cout << "Hometown: ";
				getline(cin, temp);
				fout << "<b>Hometown:</b> " << temp << endl;

				system(clearCommand);
				cout << "Major: ";
				getline(cin, temp);
				fout << "<b>Major:</b> " << temp << endl;

				system(clearCommand);
				cout << "School year: ";
				getline(cin, temp);
				fout << "<b>School year:</b> " << temp <<  endl;

				system(clearCommand);
				cout << "Pledge class: ";
				getline(cin, temp);
				fout << "<b>Pledge class:</b> " << temp << "\n" << endl;

				system(clearCommand);

				break;
			case 2:
				system(clearCommand);
				fout.close();
				cout << "***DATA***" << endl << endl;
				showInfo(fin, fileName, state);
				fout.open(fileName);
				break;
			case 3:
				exitCondition = false;
				system(clearCommand);
				break;
			default:
				break;
		}

	}
}

void addState(ofstream& fout, const string& fileName, vector<string>& state)
{
	int counter = 0;
	for (string info : state)
	{
		fout << info << endl;
		if (counter == 4)
		{
			fout << endl;
			counter = 0;
		}
	}
	fout.close();
}

void showInfo(ifstream& fin, const string& fileName, vector<string>& state)
{
	saveState(fin, fileName, state);
	int counter = 0;
	for (string row : state)
	{
		cout << row << endl;
		if (counter == 4)
		{
			cout << endl;
		}
	}
}