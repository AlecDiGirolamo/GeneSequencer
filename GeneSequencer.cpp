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

int GeneSequencer::ChooseChromosomePair()
{
	if (chromosomePairs.size() > 0)
	{
		AnalyzeChromosomePairs();
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
			if (intAnswer > 0 && intAnswer <= chromosomePairs.size())
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

void GeneSequencer::AnalyzeChromosomePairs()
{
	for (unsigned int i = 0; i < chromosomePairs.size(); i++)
	{
		cout << "Chromosome Pair: " << i + 1 << endl;
		cout << "Chromosome A: " << endl;
		cout << "Genes" << endl;
		chromosomePairs.at(i).GetChromosomeA().AnalyzeGenotype();

		cout << "Chromosome B: " << endl;
		cout << "Genes: " << endl;
		chromosomePairs.at(i).GetChromosomeB().AnalyzeGenotype();
		cout << endl;
	}
};

void GeneSequencer::CreateChromosomePairs()
{

	while (true)
	{
		ChromosomePair newChromosomePair(inputFile);
		chromosomePairs.push_back(newChromosomePair);
		cout << "Would you like to enter a new chromosome pair?(y/n)" << endl;
		string answer;
		getline(cin, answer);
		cout << endl;
		if (answer == "y")
		{
			ChromosomePair newChromPair(inputFile);
			chromosomePairs.push_back(newChromPair);
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

void GeneSequencer::ExportChromosomePair(int level)
{
	int answer = ChooseChromosomePair();
	if (level == 1)
	{
		chromosomePairs.at(answer).WriteToFile(outputFile);
	}
	else
	{
		chromosomePairs.at(answer).ExportChromosome(outputFile, level);
	}
}

void GeneSequencer::ExportData()
{
	cout << "What data would you like to export?" << endl;
	cout << "1. Chromosome Pair" << endl;
	cout << "2. Chromosome" << endl;
	cout << "3. Gene" << endl;
	cout << "4. Allele" << endl;
	while (true)
	{
		string answer;
		getline(cin, answer);
		cout << endl;
		unsigned int intAnswer;
		if (CheckIntAnswer(answer, intAnswer))
		{
			if (intAnswer == 1 || intAnswer == 2 || intAnswer == 3 || intAnswer == 4)
			{
				ExportChromosomePair(intAnswer);
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

Chromosome GeneSequencer::DoMeiosis(Chromosome chromosomeA, Chromosome chromosomeB){

};

bool GeneSequencer::PowerOnSelfTest()
{
	return true;
};
