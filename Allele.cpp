#include "Allele.hpp"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//Default??
Allele::Allele(){};

Allele::Allele(string inputNucleotideSequence, string inputVariantName, string inputVariantType)
{
	nucleotideSequence = inputNucleotideSequence;
	variantName = inputVariantName;
	variantType = inputVariantType;
};

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

void Allele::WriteAlleleToFile(ofstream &file)
{
	string fileName;
	cout << "Please enter the file name" << endl;
	getline(cin, fileName);
	file.open(fileName, ios::app);
	file << variantName << "," << variantType << "," << nucleotideSequence;
	file.close();
};

bool Allele::RunUnitTests()
{
	return true;
};