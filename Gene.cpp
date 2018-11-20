//#include "Allele.hpp"
#include "Gene.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool Gene::CheckIntAnswer(string answer, int &assignInt)
{
	for (unsigned int i = 0; i < answer.size(); i++)
	{
		if (answer.at(i) <= '0' || answer.at(i) >= '9')
		{
			return false;
		}
	}
	assignInt = stoi(answer);
	return true;
}

void Gene::InputFromFile(ifstream &file)
{
	while (true)
	{

		string fileName;
		cout << "Enter the file name" << endl;
		getline(cin, fileName);
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
		if (row.size() == 8)
		{
			name = row.at(0);
			traitType = row.at(1);
			alleleA = Allele(row.at(2), row.at(3), row.at(4));
			alleleB = Allele(row.at(5), row.at(6), row.at(7));
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

void Gene::InputManually(ifstream &file)
{
	cout << "Enter the name of the Gene." << endl;
	getline(cin, name);
	cout << endl;

	cout << "Enter the trait type of the Gene." << endl;
	getline(cin, traitType);
	cout << endl;

	cout << "Allele A:" << endl;
	alleleA = Allele(file);
	cout << "Allele B:" << endl;
	alleleB = Allele(file);
}

int Gene::ChooseAllele()
{
	cout << "Choose an allele: " << endl;
	cout << "1. Allele A: " << endl;
	cout << "Variant Name: " << alleleA.GetVariantName() << endl;
	cout << "Variant Type: " << alleleA.GetVariantType() << endl;
	cout << "Nucleotide Sequence" << alleleA.GetNucleotideSequence() << endl;
	cout << endl;
	cout << "1. Allele B: " << endl;
	cout << "Variant Name: " << alleleB.GetVariantName() << endl;
	cout << "Variant Type: " << alleleB.GetVariantType() << endl;
	cout << "Nucleotide Sequence" << alleleB.GetNucleotideSequence() << endl;
	while (true)
	{
		string answer;
		getline(cin, answer);
		cout << endl;
		if (int intAnswer = stoi(answer))
		{
			if (intAnswer != 1 && intAnswer != 2)
			{
				cout << "Please choose either '1' or '2'." << endl;
			}
			else
			{
				return intAnswer;
			}
		}
	}
	return 0;
}

Gene::Gene(std::string inputName, std::string inputTraitType, Allele inputAlleleA, Allele inputAlleleB)
{
	name = inputName;
	traitType = inputTraitType;
	alleleA = inputAlleleA;
	alleleB = inputAlleleB;
}

Gene::Gene(ifstream &file)
{

	while (true)
	{
		cout << "Would you like to enter the gene manually or by file?(manual/file)" << endl;
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
			InputManually(file);
			break;
		}
		else
		{
			InputFromFile(file);
		}
	}
}

void Gene::SetName(string inputName)
{
	name = inputName;
}

void Gene::SetTraitType(string inputTraitType)
{
	traitType = inputTraitType;
}

void Gene::SetAlleleA(Allele inputAlleleA)
{
	alleleA = inputAlleleA;
}

void Gene::SetAlleleB(Allele inputAlleleB)
{
	alleleB = inputAlleleB;
}

string Gene::GetName()
{
	return name;
}

string Gene::GetTraitType()
{
	return traitType;
}

Allele Gene::GetAlleleA()
{
	return alleleA;
}

Allele Gene::GetAlleleB()
{
	return alleleB;
}

Allele Gene::GetExpressedTrait()
{
	if (alleleA.GetVariantType() == "dominant")
	{
		return alleleA;
	}
	else
	{
		return alleleB;
	}
}

void Gene::WriteToFile(ofstream &file)
{
	string fileName;
	cout << "Enter the file name." << endl;
	getline(cin, fileName);
	cout << endl;
	file.open(fileName, ios::app);
	file << name << "," << traitType << "," << alleleA.GetVariantName() << "," << alleleA.GetVariantType() << "," << alleleA.GetNucleotideSequence() << "," << alleleB.GetVariantName() << "," << alleleB.GetVariantType() << "," << alleleB.GetNucleotideSequence();
	file.close();
}

void Gene::ExportAllele(ofstream &file)
{
	int answer = ChooseAllele();
	if (answer == 1)
	{
		alleleA.WriteToFile(file);
	}
	else
	{
		alleleB.WriteToFile(file);
	}
}

bool Gene::RunUnitTest()
{
	return true;
};