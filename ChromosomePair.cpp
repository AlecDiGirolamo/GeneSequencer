#include "ChromosomePair.hpp"
#include "Chromosome.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool ChromosomePair::CheckIntAnswer(string answer, int &assignInt)
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

void ChromosomePair::InputFromFile(ifstream &file)
{

	while (true)
	{

		Chromosome inputChromosome;
		string fileName;
		cout << "Enter the file name" << endl;
		getline(cin, fileName);
		cout << endl;
		file.open(fileName);

		Chromosome emptyChromosome;
		bool chromSeperatorFound = false;
		bool validDataCount = true;

		string line;
		while (getline(file, line)) // read a whole line of the file
		{
			if (line == "")
			{
				chromosomeA = inputChromosome;
				inputChromosome = emptyChromosome;
				chromSeperatorFound = true;
				continue;
			}
			stringstream ss(line); // put it in a stringstream (internal stream)
			vector<string> row;
			string data;
			while (getline(ss, data, ',')) // read (string) items up to a comma
			{
				row.push_back(data);
			}

			if (row.size() == 8)
			{
				inputChromosome.AddGene(Gene(row.at(0), row.at(1), Allele(row.at(2), row.at(3), row.at(4)), Allele(row.at(5), row.at(6), row.at(7))));
			}
			else
			{
				cout << "There was an invalid amount of data found in a row" << endl;
				cout << "Please use the example csv format" << endl;
				validDataCount = false;
				break;
			}
		}
		if (chromSeperatorFound && validDataCount)
		{
			chromosomeB = inputChromosome;
			file.close();
			break;
		}
		else if (!chromSeperatorFound)
		{
			cout << "There was not a second chromosome distinguished in the file." << endl;
			cout << "Please follow the example csv file format." << endl;
		}
		else
		{
			cout << "An invalid amount of data was found in a row." << endl;
			cout << "Please follow the example csv file format." << endl;
		}

		file.close();
	}
}

void ChromosomePair::InputManually(ifstream &file)
{
	cout << "Chromosome A:" << endl;
	chromosomeA = Chromosome(file);
	cout << "Chromosome B:" << endl;
	chromosomeB = Chromosome(file);
}

int ChromosomePair::ChooseChromosome()
{
	cout << "Choose a chromosome: " << endl;
	cout << "1. Chromosome A: " << endl;
	chromosomeA.AnalyzeGenotype();
	cout << endl;
	cout << "2. Chromosome B: " << endl;
	chromosomeA.AnalyzeGenotype();
	while (true)
	{
		string answer;
		getline(cin, answer);
		cout << endl;
		int intAnswer;
		if (CheckIntAnswer(answer, intAnswer))
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
		else
		{
			cout << "Please enter an integer." << endl;
		}
	}
	return 0;
}

ChromosomePair::ChromosomePair(ifstream &file)
{

	cout << "Would you like to enter the pair manually or by file?(manual/file)" << endl;
	while (true)
	{
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
Chromosome ChromosomePair::GetChromosomeA()
{
	return chromosomeA;
}
Chromosome ChromosomePair::GetChromosomeB()
{
	return chromosomeB;
}
void ChromosomePair::WriteToFile(std::ofstream &file)
{
	string fileName;
	cout << "Enter the file name." << endl;
	getline(cin, fileName);
	cout << endl;
	file.open(fileName, ios::app);
	for (unsigned int i = 0; i < chromosomeA.GetGenes().size(); i++)
	{
		file << chromosomeA.GetGenes().at(1).GetName() << "," << chromosomeA.GetGenes().at(i).GetTraitType() << "," << chromosomeA.GetGenes().at(i).GetAlleleA().GetVariantName() << "," << chromosomeA.GetGenes().at(i).GetAlleleA().GetVariantType() << "," << chromosomeA.GetGenes().at(i).GetAlleleA().GetNucleotideSequence() << "," << chromosomeA.GetGenes().at(i).GetAlleleB().GetVariantName() << "," << chromosomeA.GetGenes().at(i).GetAlleleB().GetVariantType() << "," << chromosomeA.GetGenes().at(i).GetAlleleB().GetNucleotideSequence() << endl;
	}
	file << endl;
	for (unsigned int i = 0; i < chromosomeB.GetGenes().size(); i++)
	{
		file << chromosomeB.GetGenes().at(1).GetName() << "," << chromosomeB.GetGenes().at(i).GetTraitType() << "," << chromosomeB.GetGenes().at(i).GetAlleleA().GetVariantName() << "," << chromosomeB.GetGenes().at(i).GetAlleleA().GetVariantType() << "," << chromosomeB.GetGenes().at(i).GetAlleleA().GetNucleotideSequence() << "," << chromosomeB.GetGenes().at(i).GetAlleleB().GetVariantName() << "," << chromosomeB.GetGenes().at(i).GetAlleleB().GetVariantType() << "," << chromosomeB.GetGenes().at(i).GetAlleleB().GetNucleotideSequence() << endl;
	}
	file.close();
};

void ChromosomePair::ExportChromosome(ofstream &file, int level)
{
	int answer = ChooseChromosome();
	if (level == 2)
	{
		if (answer == 1)
		{
			chromosomeA.WriteToFile(file);
		}
		else
		{
			chromosomeB.WriteToFile(file);
		}
	}
	else
	{
		if (answer == 1)
		{
			chromosomeA.ExportGene(file, level);
		}
		else
		{
			chromosomeB.ExportGene(file, level);
		}
	}
}

bool ChromosomePair::RunUnitTest()
{
	return true;
}