#include "GeneSequencer.hpp"
#include <string>
#include <iostream>

using namespace std;

bool GeneSequencer::CheckIntAnswer(string answer, unsigned int &assignInt)
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

bool testChromosomes(Chromosome chromosomeA, Chromosome chromosomeB)
{
	if (chromosomeA.GetGenes().size() != chromosomeB.GetGenes().size())
	{
		cout << "The ammount of genes in the chromosomes are not the same." << endl;
		return false;
	}
	else
	{
		for (unsigned int i = 0; i < chromosomeA.GetGenes().size(); i++)
		{
			if (chromosomeA.GetGenes().at(i).GetTraitType() != chromosomeB.GetGenes().at(i).GetTraitType())
			{
				cout << "A pair of genes did not match in the chromosomes." << endl;
				return false;
			}
		}
	}
	return true;
}

int GeneSequencer::ChooseChromosome()
{
	if (chromosomes.size() > 0)
	{
		AnalyzeChromosomes();
	}
	else
	{
		return -1;
	}
	while (true)
	{
		string answer;
		getline(cin, answer);
		cout << endl;
		unsigned int intAnswer;
		if (CheckIntAnswer(answer, intAnswer))
		{
			if (intAnswer > 0 && intAnswer <= chromosomes.size())
			{
				return intAnswer - 1;
			}
			else
			{
				cout << "There is not a chromosome pair with the given selection. Please try again" << endl;
			}
		}
		else
		{
			cout << "Please enter an integer" << endl;
		}
	}
	return -1;
}

void GeneSequencer::AnalyzeChromosomes()
{
	for (unsigned int i = 0; i < chromosomes.size(); i++)
	{
		cout << "Chromosome " << i + 1 << ": " << endl;
		chromosomes.at(i).AnalyzeGenotype();
	}
};

void GeneSequencer::CreateChromosomes()
{
	Chromosome newChromosome(inputFile);
	chromosomes.push_back(newChromosome);
	while (true)
	{
		cout << "Would you like to enter a new chromosome?(y/n)" << endl;
		string answer;
		getline(cin, answer);
		cout << endl;
		if (answer == "y")
		{
			Chromosome newChromosome(inputFile);
			chromosomes.push_back(newChromosome);
		}
		else if (answer == "n")
		{
			break;
		}
		else
		{
			cout << "Please enter either 'y' or 'n'." << endl;
		}
	}
};

void GeneSequencer::ExportChromosome(int level)
{
	int answer = ChooseChromosome();
	if (answer == -1)
	{
		cout << "There was a problem selecting a chromosome." << endl;
		return;
	}
	if (level == 1)
	{
		chromosomes.at(answer).WriteToFile(outputFile);
	}
	else
	{
		chromosomes.at(answer).ExportGene(outputFile, level);
	}
}

void GeneSequencer::ExportData()
{
	cout << "What data would you like to export?" << endl;
	cout << "1. Chromosome" << endl;
	cout << "2. Gene" << endl;
	cout << "3. Allele" << endl;
	while (true)
	{
		string answer;
		getline(cin, answer);
		cout << endl;
		unsigned int intAnswer;
		if (CheckIntAnswer(answer, intAnswer))
		{
			if (intAnswer == 1 || intAnswer == 2 || intAnswer == 3)
			{
				ExportChromosome(intAnswer);
				break;
			}
			else
			{
				cout << "Please enter either '1', '2', '3', or '4'." << endl;
			}
		}
		else
		{
			cout << "Please enter an integer." << endl;
		}
	}
}

void GeneSequencer::DoMeiosis()
{
	if (chromosomes.size() > 1)
	{
		cout << "Choose the first Chromosome: " << endl;
		Chromosome chromosomeA = chromosomes.at(ChooseChromosome());

		cout << "Choose the second Chromosome: " << endl;
		Chromosome chromosomeB = chromosomes.at(ChooseChromosome());

		if (testChromosomes(chromosomeA, chromosomeB))
		{
			chromosomes.push_back(chromosomeA + chromosomeB);
		}
	}
};

bool GeneSequencer::PowerOnSelfTest()
{
	for (unsigned int i = 0; i < chromosomes.size(); i++)
	{
		if (!chromosomes.at(i).RunUnitTest())
		{
			cout << "Chromosome " << i + 1 << " failed its test." << endl;
			return false;
		}
	}
	return true;
};
