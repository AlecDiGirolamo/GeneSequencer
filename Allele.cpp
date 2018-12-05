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
	traitOneName = inputTraitOneName;
	traitOneType = inputTraitOneType;
	traitTwoName = inputTraitTwoName;
	traitTwoType = inputTraitTwoType;
	nucleotideSequence = inputNucleotideSequence;
}
Allele::Allele(string inputTraitOneName, string inputTraitTwoName, string inputNucleotideSequence)
{
	nucleotideSequence = inputNucleotideSequence;
	traitOneName = inputTraitOneName;
	traitTwoName = inputTraitTwoName;
	if (isupper(nucleotideSequence.at(0)))
	{
		traitOneType = "dominant";
	}
	else
	{
		traitOneType = "recessive";
	}

	if (isupper(nucleotideSequence.at(1)))
	{
		traitTwoType = "dominant";
	}
	else
	{
		traitTwoType = "recessive";
	}
};

void Allele::InputManually()
{
	cout << "Enter the first trait name" << endl;
	getline(cin, traitOneName);
	cout << endl;

	cout << "Enter the second trait name" << endl;
	getline(cin, traitTwoName);
	cout << endl;

	cout << "Enter the nucleotide sequnce" << endl;
	while (true)
	{
		getline(cin, nucleotideSequence);
		cout << endl;
		if (nucleotideSequence.size() == 2)
		{
			break;
		}
		else
		{
			cout << "Invalid sequence length." << endl;
		}
	}
	cout << endl;

	if (isupper(nucleotideSequence.at(0)))
	{
		traitOneType = "dominant";
	}
	else
	{
		traitOneType = "recessive";
	}

	if (isupper(nucleotideSequence.at(1)))
	{
		traitTwoType = "dominant";
	}
	else
	{
		traitTwoType = "recessive";
	}
};

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
		stringstream ss(line);
		vector<string> row;
		string data;
		while (getline(ss, data, ','))
		{
			row.push_back(data);
		}
		if (row.size() == 3)
		{
			traitOneName = row.at(0);
			traitTwoName = row.at(1);
			nucleotideSequence = row.at(2);

			if (isupper(nucleotideSequence.at(0)))
			{
				traitOneType = "dominant";
			}
			else
			{
				traitOneType = "recessive";
			}

			if (isupper(nucleotideSequence.at(1)))
			{
				traitTwoType = "dominant";
			}
			else
			{
				traitTwoType = "recessive";
			}
			if (nucleotideSequence.size() == 2)
			{
				file.close();
				break;
			}
			file.close();
		}
		else
		{
			cout << "There was an invalid amount of data found in a row." << endl;
			cout << "Please use the example csv format." << endl;
		}
		file.close();
	}
};
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
	string tempNuc;

	if (this->GetTraitOneType() == a.GetTraitOneType())
	{
		int randNum = rand() % 2 + 1;
		if (randNum == 1)
		{
			tempTraitOne = this->GetTraitOneName();
			tempNuc = this->GetNucleotideSequence().at(0);
		}
		else
		{
			tempTraitOne = a.GetTraitOneName();
			tempNuc = a.GetNucleotideSequence().at(0);
		}
	}
	else if (this->GetTraitOneType() == "dominant")
	{
		int randNum = rand() % 4 + 1;
		if (randNum == 1)
		{
			tempTraitOne = a.GetTraitOneName();
			tempNuc = a.GetNucleotideSequence().at(0);
		}
		else
		{
			tempTraitOne = this->GetTraitOneName();
			tempNuc = this->GetNucleotideSequence().at(0);
		}
	}
	else
	{
		int randNum = rand() % 4 + 1;
		if (randNum == 1)
		{
			tempTraitOne = this->GetTraitOneName();
			tempNuc = this->GetNucleotideSequence().at(0);
		}
		else
		{
			tempTraitOne = a.GetTraitOneName();
			tempNuc = a.GetNucleotideSequence().at(0);
		}
	}

	//trait 2
	if (this->GetTraitTwoType() == a.GetTraitTwoType())
	{
		int randNum = rand() % 2 + 1;
		if (randNum == 1)
		{
			tempTraitTwo = this->GetTraitTwoName();
			tempNuc += this->GetNucleotideSequence().at(1);
		}
		else
		{
			tempTraitTwo = a.GetTraitTwoName();
			tempNuc += a.GetNucleotideSequence().at(1);
		}
	}
	else if (this->GetTraitTwoType() == "dominant")
	{
		int randNum = rand() % 4 + 1;
		if (randNum == 1)
		{
			tempTraitTwo = a.GetTraitTwoName();
			tempNuc += a.GetNucleotideSequence().at(1);
		}
		else
		{
			tempTraitTwo = this->GetTraitTwoName();
			tempNuc += this->GetNucleotideSequence().at(1);
		}
	}
	else
	{
		int randNum = rand() % 4 + 1;
		if (randNum == 1)
		{
			tempTraitTwo = this->GetTraitTwoName();
			tempNuc += this->GetNucleotideSequence().at(1);
		}
		else
		{
			tempTraitTwo = a.GetTraitTwoName();
			tempNuc += a.GetNucleotideSequence().at(1);
		}
	}

	return Allele(tempTraitOne, tempTraitTwo, tempNuc);
}

void Allele::WriteToFile(ofstream &file)
{
	string fileName;
	cout << "Enter the file name" << endl;
	getline(cin, fileName);
	cout << endl;
	file.open(fileName, ios::app);
	file << traitOneName << "," << traitTwoName << "," << nucleotideSequence;
	file.close();
};

bool Allele::RunUnitTests()
{
	if (traitOneType != "dominant" && traitOneType != "recessive")
	{
		cout << "Trait one type not 'dominant' or 'recessive'" << endl;
		return false;
	}
	if (traitTwoType != "dominant" && traitTwoType != "recessive")
	{
		cout << "Trait two type not 'dominant' or 'recessive'" << endl;
		return false;
	}
	if (nucleotideSequence.size() != 2)
	{
		cout << "Nucleotide seqeunce has an invalid amount of characters." << endl;
		return false;
	}
	if (isupper(nucleotideSequence.at(0)) && traitOneType != "dominant")
	{
		cout << "Trait one type does not match nucleotide sequence" << endl;
		return false;
	}
	else if (islower(nucleotideSequence.at(0)) && traitOneType != "recessive")
	{
		cout << "Trait one type does not match nucleotide sequence" << endl;
		return false;
	}
	if (isupper(nucleotideSequence.at(1)) && traitTwoType != "dominant")
	{
		cout << "Trait two type does not match nucleotide sequence" << endl;
		return false;
	}
	else if (islower(nucleotideSequence.at(1)) && traitTwoType != "recessive")
	{
		cout << "Trait two type does not match nucleotide sequence" << endl;
		return false;
	}
	return true;
};