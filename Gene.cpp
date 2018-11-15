#include "Allele.hpp"
#include "Gene.hpp"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Gene::Gene(){};

Gene::Gene(string inputName, string inputTraitType, Allele inputAlleleA, Allele inputAlleleB)
{
	name = inputName;
	traitType = inputTraitType;
	alleleA = inputAlleleA;
	alleleB = inputAlleleB;
};

void Gene::SetName(string inputName)
{
	name = inputName;
};

void Gene::SetTraitType(string inputTraitType)
{
	traitType = inputTraitType;
};

void Gene::SetAlleleA(Allele inputAlleleA)
{
	alleleA = inputAlleleA;
};

void Gene::SetAlleleB(Allele inputAlleleB)
{
	alleleB = inputAlleleB;
};

string Gene::GetName()
{
	return name;
};

string Gene::GetTraitType()
{
	return traitType;
}

Allele Gene::GetAlleleA()
{
	return alleleA;
};

Allele Gene::GetAlleleB()
{
	return alleleB;
};

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
};

bool Gene::RunUnitTest()
{
	return true;
};

void Gene::WriteToFile(ofstream &file)
{
	cout << "Please enter the file name" << endl;
	string fileName;
	getline(cin, fileName);
	file.open(fileName, ios::app);
	file << name << "," << traitType << "," << alleleA.GetVariantName() << "," << alleleA.GetVariantType() << "," << alleleA.GetNucleotideSequence() << "," << alleleB.GetVariantName() << "," << alleleB.GetVariantType() << "," << alleleB.GetNucleotideSequence();
	file.close();
};