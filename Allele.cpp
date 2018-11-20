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

Allele::Allele(string inputNucleotideSequence, string inputVariantName, string inputVariantType)
{
	nucleotideSequence = inputNucleotideSequence;
	variantName = inputVariantName;
	variantType = inputVariantType;
};

void Allele::InputManually()
{
	cout << "Enter the variant name" << endl;
	getline(cin, variantName);
	cout << endl;

	cout << "Enter the variant type.(dominant/recessive)" << endl;
	string inputVariantType;
	while (true)
	{
		getline(cin, inputVariantType);
		cout << endl;
		if (inputVariantType != "dominant" && inputVariantType != "recessive")
		{
			cout << "Enter either 'dominant' or 'recessive'." << endl;
		}
		else
		{
			variantType = inputVariantType;
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
		if (row.size() == 3)
		{
			variantName = row.at(0);
			variantType = row.at(1);
			nucleotideSequence = row.at(2);
			file.close();
			break;
		}
		else
		{
			cout << "There was an invalid amount of data found in a row" << endl;
			cout << "Please use the example csv format" << endl;
		}
		file.close();
	}
}

void Allele::SetNucleotideSequence(string inputNucleotideSequence)
{
	nucleotideSequence = inputNucleotideSequence;
};

void Allele::SetVariantName(string inputVariantName)
{
	variantName = inputVariantName;
};

void Allele::SetVariantType(string inputVariantType)
{
	variantType = inputVariantType;
};

string Allele::GetNucleotideSequence()
{
	return nucleotideSequence;
};

string Allele::GetVariantName()
{
	return variantName;
};

string Allele::GetVariantType()
{
	return variantType;
};

void Allele::WriteToFile(ofstream &file)
{
	string fileName;
	cout << "Enter the file name" << endl;
	getline(cin, fileName);
	cout << endl;
	file.open(fileName, ios::app);
	file << variantName << "," << variantType << "," << nucleotideSequence;
	file.close();
};

bool Allele::RunUnitTests()
{
	return true;
};