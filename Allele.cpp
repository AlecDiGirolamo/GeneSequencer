#include "Allele.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

Allele::Allele(){};

Allele::Allele(ifstream &file)
{
	while (true)
	{
		cout << "Would you like to enter the allele manually or by file?(manual/file)" << endl;
		string answer;
		getline(cin, answer);
		cout << endl;
		if (answer != "manual" && answer != "file")
		{
			cout << "Enter either 'manual' or 'file'." << endl;
			cout << endl;
		}
		else if (answer == "manual")
		{
			InputManually();
			break;
		}
		else
		{
			InputFromFile(file);
			break;
		}
	}
};

Allele::Allele(string inputTraitOneName, string inputTraitOneType, string inputTraitTwoName, string inputTraitTwoType, string inputNucleotideSequence)
{
	nucleotideSequence = inputNucleotideSequence;
	traitOneName = inputTraitOneName;
	traitOneType = inputTraitOneType;
	traitTwoName = inputTraitTwoName;
	traitTwoType = inputTraitTwoType;
};

void Allele::InputManually()
{
	cout << "Enter the first trait name" << endl;
	getline(cin, traitOneName);
	cout << endl;

	cout << "Enter the first trait type.(dominant/recessive)" << endl;
	string inputTraitOneType;
	while (true)
	{
		getline(cin, inputTraitOneType);
		cout << endl;
		if (inputTraitOneType != "dominant" && inputTraitOneType != "recessive")
		{
			cout << "Enter either 'dominant' or 'recessive'." << endl;
		}
		else
		{
			traitOneType = inputTraitOneType;
			break;
		}
	}

	cout << "Enter the second trait name" << endl;
	getline(cin, traitTwoName);
	cout << endl;

	cout << "Enter the second trait type.(dominant/recessive)" << endl;
	string inputTraitTwoType;
	while (true)
	{
		getline(cin, inputTraitTwoType);
		cout << endl;
		if (inputTraitTwoType != "dominant" && inputTraitTwoType != "recessive")
		{
			cout << "Enter either 'dominant' or 'recessive'." << endl;
		}
		else
		{
			traitTwoType = inputTraitTwoType;
			break;
		}
	}

	cout << "Enter the nucleotide sequnce" << endl;
	getline(cin, nucleotideSequence);
	cout << endl;
}

void Allele::InputFromFile(ifstream &file)
{
	while (true)
	{

		string fileName;
		cout << "Enter the file name" << endl;
		getline(cin, fileName);
		cout << endl;
		file.open(fileName);

		string line;
		getline(file, line);
		stringstream ss(line); // put it in a stringstream (internal stream)
		vector<string> row;
		string data;
		while (getline(ss, data, ',')) // read (string) items up to a comma
		{
			row.push_back(data);
		}
		if (row.size() == 5)
		{
			traitOneName = row.at(0);
			traitOneType = row.at(1);
			traitTwoName = row.at(2);
			traitTwoType = row.at(3);
			nucleotideSequence = row.at(4);
			file.close();
			break;
		}
		else
		{
			cout << "There was an invalid amount of data found in a row." << endl;
			cout << "Please use the example csv format." << endl;
		}
		file.close();
	}
}
/*
void Allele::SetNucleotideSequence(string inputNucleotideSequence)
{
	nucleotideSequence = inputNucleotideSequence;
};

void Allele::SetTraitOneName(string inputTraitOneName)
{
	traitOneName = inputTraitOneName;
};

void Allele::SetTraitOneType(string inputTraitOneType)
{
	traitOneType = inputTraitOneType;
};

void Allele::SetTraitTwoName(string inputTraitTwoName)
{
	traitTwoName = inputTraitTwoName;
};

void Allele::SetTraitTwoType(string inputTraitTwoType)
{
	traitTwoType = inputTraitTwoType;
};
*/
string Allele::GetNucleotideSequence()
{
	return nucleotideSequence;
};

string Allele::GetTraitTwoName()
{
	return traitTwoName;
};

string Allele::GetTraitTwoType()
{
	return traitTwoType;
};

string Allele::GetTraitOneName()
{
	return traitOneName;
};

string Allele::GetTraitOneType()
{
	return traitOneType;
};

Allele Allele::operator+(Allele a)
{

	srand(time(NULL));
	string tempTraitOne;
	string tempTraitOneType;
	string tempTraitTwo;
	string tempTraitTwoType;

	if (this->GetTraitOneType() == a.GetTraitOneType())
	{
		int randNum = rand() % 2 + 1;
		if (randNum == 1)
		{
			tempTraitOne = this->GetTraitOneName();
			tempTraitOneType = this->GetTraitOneType();
		}
		else
		{
			tempTraitOne = a.GetTraitOneName();
			tempTraitOneType = a.GetTraitOneType();
		}
	}
	else if (this->GetTraitOneType() == "dominant")
	{
		int randNum = rand() % 4 + 1;
		if (randNum == 1)
		{
			tempTraitOne = a.GetTraitOneName();
			tempTraitOneType = a.GetTraitOneType();
		}
		else
		{
			tempTraitOne = this->GetTraitOneName();
			tempTraitOneType = this->GetTraitOneType();
		}
	}
	else
	{
		int randNum = rand() % 4 + 1;
		if (randNum == 1)
		{
			tempTraitOne = this->GetTraitOneName();
			tempTraitOneType = this->GetTraitOneType();
		}
		else
		{
			tempTraitOne = a.GetTraitOneName();
			tempTraitOneType = a.GetTraitOneType();
		}
	}

	//trait 2
	if (this->GetTraitTwoType() == a.GetTraitTwoType())
	{
		int randNum = rand() % 2 + 1;
		if (randNum == 1)
		{
			tempTraitTwo = this->GetTraitTwoName();
			tempTraitTwoType = this->GetTraitTwoType();
		}
		else
		{
			tempTraitTwo = a.GetTraitTwoName();
			tempTraitTwoType = a.GetTraitTwoType();
		}
	}
	else if (this->GetTraitTwoType() == "dominant")
	{
		int randNum = rand() % 4 + 1;
		if (randNum == 1)
		{
			tempTraitTwo = a.GetTraitTwoName();
			tempTraitTwoType = a.GetTraitTwoType();
		}
		else
		{
			tempTraitTwo = this->GetTraitTwoName();
			tempTraitTwoType = this->GetTraitTwoType();
		}
	}
	else
	{
		int randNum = rand() % 4 + 1;
		if (randNum == 1)
		{
			tempTraitTwo = this->GetTraitTwoName();
			tempTraitTwoType = this->GetTraitTwoType();
		}
		else
		{
			tempTraitTwo = a.GetTraitTwoName();
			tempTraitTwoType = a.GetTraitTwoType();
		}
	}
	string tempNuc;
	tempNuc += this->GetNucleotideSequence().at(0);
	tempNuc += this->GetNucleotideSequence().at(1);
	tempNuc += a.GetNucleotideSequence().at(0);
	tempNuc += a.GetNucleotideSequence().at(1);

	return Allele(tempTraitOne, tempTraitOneType, tempTraitTwo, tempTraitTwoType, tempNuc);
}

void Allele::WriteToFile(ofstream &file)
{
	string fileName;
	cout << "Enter the file name" << endl;
	getline(cin, fileName);
	cout << endl;
	file.open(fileName, ios::app);
	file << traitOneName << "," << traitOneType << "," << traitTwoName << "," << traitTwoType << "," << nucleotideSequence;
	file.close();
};

bool Allele::RunUnitTests()
{
	if (traitOneName != "dominant" && traitOneName != "recessive")
	{
		cout << "Trait one type not 'dominant' or 'recessive'" << endl;
		return false;
	}
	if (traitTwoName != "dominant" && traitTwoName != "recessive")
	{
		cout << "Trait two type not 'dominant' or 'recessive'" << endl;
		return false;
	}
	return true;
};