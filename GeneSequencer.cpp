#include "GeneSequencer.hpp"
#include <string>
#include <iostream>

using namespace std;

Allele GeneSequencer::GetAllele(string alleleNumber)
{
	string variant;
	string type;
	string sequence;
	cout << "What is the " << alleleNumber << " variant?" << endl;
	getline(cin, variant);
	cout << "What is the " << alleleNumber << " type?(dominant or recessive)" << endl;
	getline(cin, type);
	while (true)
	{
		if (type != "dominant" && type != "recessive")
		{
			cout << "Please choose either dominant or recessive" << endl;
			getline(cin, type);
		}
		else
		{
			break;
		}
	}
	cout << "What is the " << alleleNumber << " nucleotide sequence?" << endl;
	getline(cin, sequence);
	return Allele(sequence, variant, type);
}

int GeneSequencer::ChooseChromosome()
{

	cout << "Please choose a chromosome" << endl;
	AnalyzeChromosome();
	if (chromosomes.size() > 0)
	{
		string userChoice;
		getline(cin, userChoice);
		while (true)
		{
			if (int intUserChoice = stoi(userChoice))
			{
				if (intUserChoice < 1 || intUserChoice > chromosomes.size())
				{
					cout << "There are no chromosomes with that number." << endl;
				}
				else
				{
					return intUserChoice - 1;
				}
			}
			else
			{
				cout << "Please enter an integer." << endl;
			}
		}
	}
}

void GeneSequencer::AnalyzeChromosome()
{
	// ask about chromosome storage
	if (chromosomes.size() < 0)
	{
		cout << "There are currently no chromosomes saved." << endl;
	}
	else
	{
		for (unsigned int i = 0; i < chromosomes.size(); i++)
		{
			cout << "Chromosome " << chromosomes.at(i).GetNumber() << ": " << endl;
			chromosomes.at(i).AnalyzeGenotype();
			cout << endl;
		}
	}
};

void GeneSequencer::CreateChromosome()
{
	Chromosome newChromosome(chromosomes.size() + 1);
	while (true)
	{
		string name;
		string trait;
		cout
			<< "What is the name of the new gene?" << endl;
		getline(cin, name);
		cout << "What is the gene trait?" << endl;
		getline(cin, trait);
		Allele alleleA = GetAllele("Allele 1");
		Allele alleleB = GetAllele("Allele 2");

		if (alleleA.GetVariantType() == alleleB.GetVariantType())
		{
			cout << "Alleles cannot both be " << alleleA.GetVariantType() << "." << endl;
			cout << "Please re-enter the alleles." << endl;
			continue;
		}
		else
		{
			newChromosome.AddGene(Gene(name, trait, alleleA, alleleB));
		}

		cout << "Would you like to enter another gene?(y,n)" << endl;
		string answer;
		getline(cin, answer);
		while (true)
		{
			if (answer != "y" && answer != "n")
			{
				cout << "Please enter either 'y' or 'n'." << endl;
				getline(cin, answer);
			}
			else
			{
				break;
			}
		}
		if (answer == "n")
		{
			break;
		}
	}
	chromosomes.push_back(newChromosome);
};

void GeneSequencer::ImportChromosome()
{
	chromosomes.at(0).InputFromFile(inputFile);
};
void GeneSequencer::ExportChromosome(){};
Chromosome GeneSequencer::DoMeiosis(Chromosome chromosomeA, Chromosome chromosomeB){};
void GeneSequencer::SequenceChromosome(Chromosome inputChromosome){};
bool GeneSequencer::PowerOnSelfTest(){};