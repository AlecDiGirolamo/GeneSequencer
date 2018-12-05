//#include "Allele.hpp"
#include "Gene.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

bool Gene::CheckIntAnswer(string answer, int &assignInt)
{
	if (answer.size() == 0)
	{
		return false;
	}
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

		stringstream ss(line);
		vector<string> row;
		string data;
		while (getline(ss, data, ','))
		{
			row.push_back(data);
		}
		if (row.size() == 10)
		{
			if (row.at(6).size() != 2 || row.at(9).size() != 2)
			{
				cout << "Nucleotide sequence of an allele has an invalid amount of characters." << endl;
				continue;
			}

			name = row.at(0);
			traitType = row.at(1);
			alleleA = Allele(row.at(4), row.at(5), row.at(6));
			alleleB = Allele(row.at(7), row.at(8), row.at(9));
			nucleotideSequence = row.at(6);
			nucleotideSequence += row.at(9);

			string tempOneType;
			string tempTwoType;
			if (row.at(2) == alleleA.GetTraitOneName())
			{
				tempOneType = alleleA.GetTraitOneType();
			}
			else
			{
				tempOneType = alleleB.GetTraitOneType();
			}
			if (row.at(3) == alleleA.GetTraitTwoName())
			{
				tempTwoType = alleleA.GetTraitTwoType();
			}
			else
			{
				tempTwoType = alleleB.GetTraitTwoType();
			}

			expressedTraits = Allele(row.at(2), tempOneType, row.at(3), tempTwoType, "00");
			if ((expressedTraits.GetTraitOneName() != alleleA.GetTraitOneName() && expressedTraits.GetTraitOneName() != alleleB.GetTraitOneName()) || (expressedTraits.GetTraitTwoName() != alleleA.GetTraitTwoName() && expressedTraits.GetTraitTwoName() != alleleB.GetTraitTwoName()))
			{
				cout << "The expressed alleles do not match any of the given alleles." << endl;
			}

			else
			{
				file.close();
				break;
			}
		}
		else
		{
			cout << "There was an invalid amount of data found in a row" << endl;
			cout << "Please use the example csv format" << endl;
		}
		file.close();
	}
};

void Gene::InputManually(ifstream &file)
{
	cout << "Enter the name of the Gene." << endl;
	getline(cin, name);
	cout << endl;

	cout << "Enter the trait type of the Gene." << endl;
	getline(cin, traitType);
	cout << endl;

	cout << "Enter the nucleotide sequence." << endl;
	getline(cin, nucleotideSequence);
	cout << endl;

	cout << "Allele A:" << endl;
	alleleA = Allele(file);
	cout << "Allele B:" << endl;
	alleleB = Allele(file);
	CalculateExpressedTrait();
}

int Gene::ChooseAllele()
{
	cout << "Choose an allele: " << endl;
	cout << "1. Allele A: " << endl;
	cout << "First Trait Name: " << alleleA.GetTraitOneName() << endl;
	cout << "First Trait Type: " << alleleA.GetTraitOneType() << endl;
	cout << "Second Trait Name: " << alleleA.GetTraitTwoName() << endl;
	cout << "Second Trait Type: " << alleleA.GetTraitTwoType() << endl;
	cout << "Nucleotide Sequence: " << alleleA.GetNucleotideSequence() << endl;
	cout << endl;
	cout << "2. Allele B: " << endl;
	cout << "First Trait Name: " << alleleB.GetTraitOneName() << endl;
	cout << "First Trait Type: " << alleleB.GetTraitOneType() << endl;
	cout << "Second Trait Name: " << alleleB.GetTraitTwoName() << endl;
	cout << "Second Trait Type: " << alleleB.GetTraitTwoType() << endl;
	cout << "Nucleotide Sequence: " << alleleB.GetNucleotideSequence() << endl;

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

Gene::Gene(string inputName, string inputTraitType, Allele inputExpressedTraits, Allele inputAlleleA, Allele inputAlleleB)
{
	name = inputName;
	traitType = inputTraitType;
	expressedTraits = inputExpressedTraits;
	alleleA = inputAlleleA;
	alleleB = inputAlleleB;
	nucleotideSequence = inputAlleleA.GetNucleotideSequence();
	nucleotideSequence += inputAlleleB.GetNucleotideSequence();
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
			break;
		}
	}
}
/*
void Gene::SetName(string inputName)
{
	name = inputName;
}

void Gene::SetTraitType(string inputTraitType)
{
	traitType = inputTraitType;
}

void Gene::SetExpressedTraits(Allele inputExpressedTraits){
	expressedTraits = inputExpressedTraits;
}

void Gene::SetAlleleA(Allele inputAlleleA)
{
	alleleA = inputAlleleA;
}

void Gene::SetAlleleB(Allele inputAlleleB)
{
	alleleB = inputAlleleB;
}
*/
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

string Gene::GetNucleotideSequence()
{
	return nucleotideSequence;
}

void Gene::CalculateExpressedTrait()
{
	expressedTraits = alleleA + alleleB;
}

Allele Gene::GetExpressedTrait()
{
	return expressedTraits;
}

Gene Gene::operator+(Gene g)
{
	Allele tempAlleleA = this->GetAlleleA() + g.GetAlleleA();
	Allele tempAlleleB = this->GetAlleleB() + g.GetAlleleB();
	Gene tempGene = Gene(name, traitType, Allele(), tempAlleleA, tempAlleleB);
	tempGene.CalculateExpressedTrait();
	return tempGene;
}

void Gene::WriteToFile(ofstream &file)
{
	string fileName;
	cout << "Enter the file name." << endl;
	getline(cin, fileName);
	cout << endl;
	file.open(fileName, ios::app);
	file << name << "," << traitType << ","
		 << expressedTraits.GetTraitOneName() << ","
		 << expressedTraits.GetTraitTwoName() << ","
		 << alleleA.GetTraitOneName() << ","
		 << alleleA.GetTraitTwoName() << ","
		 << alleleA.GetNucleotideSequence() << ","
		 << alleleB.GetTraitOneName() << ","
		 << alleleB.GetTraitTwoName() << ","
		 << alleleB.GetNucleotideSequence() << "," << endl;
	file.close();
};

void Gene::ExportAllele(ofstream &file)
{
	int answer = ChooseAllele();
	if (answer == 2)
	{
		alleleA.WriteToFile(file);
	}
	else
	{
		alleleB.WriteToFile(file);
	}
};

bool Gene::RunUnitTest()
{
	if (!alleleA.RunUnitTests())
	{
		cout << "Allele A failed its test." << endl;
		return false;
	}
	if (!alleleB.RunUnitTests())
	{
		cout << "Allele B failed its test." << endl;
		return false;
	}
	if (expressedTraits.GetTraitOneName() != alleleA.GetTraitOneName() && expressedTraits.GetTraitOneName() != alleleB.GetTraitOneName())
	{
		cout << "Expressed trait one does not match any either allele's expressed trait one" << endl;
		return false;
	}
	if (expressedTraits.GetTraitTwoName() != alleleA.GetTraitTwoName() && expressedTraits.GetTraitTwoName() != alleleB.GetTraitTwoName())
	{
		cout << "Expressed trait one does not match any either allele's expressed trait one" << endl;
		return false;
	}
	return true;
};