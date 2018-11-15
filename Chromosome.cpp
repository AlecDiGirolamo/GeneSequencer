#include "Gene.hpp"
#include "Chromosome.hpp"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

Chromosome::Chromosome(){};

Chromosome::Chromosome(int inputNumber)
{
	number = inputNumber;
}

void Chromosome::AnalyzeGenotype()
{
	for (unsigned int i = 0; i < genes.size(); i++)
	{
		cout << "Name: " << genes.at(i).GetName() << endl;
		cout << "Genetic trait: " << genes.at(i).GetTraitType() << endl;
		cout << "Expressed allele: " << genes.at(i).GetExpressedTrait().GetVariantName() << "-dominant" << endl;
		cout << "Nucleotide sequence: " << genes.at(i).GetExpressedTrait().GetNucleotideSequence() << endl
			 << endl;
	}
};

void Chromosome::InputFromFile(std::ifstream &file)
{
	string fileName;
	cout << "Please enter the file name" << endl;
	getline(cin, fileName);
	file.open(fileName);
	string line;
	while (getline(file, line)) // read a whole line of the file
	{
		stringstream ss(line); // put it in a stringstream (internal stream)
		vector<string> row;
		string data;
		while (getline(ss, data, ',')) // read (string) items up to a comma
		{
			row.push_back(data);
		}

		AddGene(Gene(row.at(0), row.at(1), Allele(row.at(2), row.at(3), row.at(4)), Allele(row.at(5), row.at(6), row.at(7))));
	}
	file.close();
};

void Chromosome::OutputToFile(std::ofstream &file){

};

void Chromosome::AddGene(Gene inputGene)
{
	genes.push_back(inputGene);
};

int Chromosome::GetNumber()
{
	return number;
}

Gene Chromosome::FindGene(std::string name){

};

Chromosome operator+(Chromosome inputChromosome){

};

bool Chromosome::RunUnitTest(){

};
