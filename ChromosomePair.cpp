/*
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
				inputChromosome.AddGene(Gene(row.at(0), row.at(1), Allele(row.at(2), row.at(3), row.at(4), row.at(5), row.at(6)), Allele(row.at(7), row.at(8), row.at(9), row.at(10), row.at(11))));
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

*/