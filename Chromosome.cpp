#include "Gene.hpp"
#include "Chromosome.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

bool Chromosome::CheckIntAnswer(string answer, unsigned int &assignInt)
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

Chromosome::Chromosome(vector<Gene> inputGenes)
{
	genes = inputGenes;
};

Chromosome::Chromosome(ifstream &file)
{

	while (true)
	{
		cout << "Would you like to enter the chromosome manually or by file?(manual/file)" << endl;
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

void Chromosome::InputFromFile(std::ifstream &file)
{
	while (true)
	{

		string fileName;
		cout << "Enter the file name" << endl;
		getline(cin, fileName);
		cout << endl;

		file.open(fileName);
		string line;
		bool validDataCount = false;
		while (getline(file, line)) // read a whole line of the file
		{
			stringstream ss(line); // put it in a stringstream (internal stream)
			vector<string> row;
			string data;
			while (getline(ss, data, ',')) // read (string) items up to a comma
			{
				row.push_back(data);
			}
			if (row.size() == 14)
			{
				AddGene(Gene(row.at(0), row.at(1), Allele(row.at(2), "dominant", row.at(3), "dominant", "0000"), Allele(row.at(4), row.at(5), row.at(6), row.at(7), row.at(8)), Allele(row.at(9), row.at(10), row.at(11), row.at(12), row.at(13))));
				validDataCount = true;
			}
			else
			{
				break;
			}
		}
		if (validDataCount)
		{
			file.close();
			break;
		}
		else
		{
			cout << "There was an invalid amount of data found in a row" << endl;
			cout << "Please use the example csv format" << endl;
			genes = {};
		}
		file.close();
	}
};

void Chromosome::InputManually(ifstream &file)
{
	AddGene(Gene(file));
	while (true)
	{
		cout << "Would you like to enter another gene?(y/n)" << endl;
		string answer;
		getline(cin, answer);
		cout << endl;
		if (answer != "y" && answer != "n")
		{
			cout << "Enter either 'y' or 'n'." << endl;
		}
		else if (answer == "y")
		{
			AddGene(Gene(file));
		}
		else
		{
			break;
		}
	}
}

int Chromosome::ChooseGene()
{
	cout << "Choose a gene: " << endl;
	AnalyzeGenotype();

	while (true)
	{
		string answer;
		getline(cin, answer);
		cout << endl;
		unsigned int intAnswer;
		if (CheckIntAnswer(answer, intAnswer))
		{
			if (intAnswer < 1 || intAnswer > genes.size())
			{
				cout << "No gene with that number was found" << endl;
			}
			else
			{
				return intAnswer - 1;
			}
		}
	}
	return 0;
}

void Chromosome::AnalyzeGenotype()
{
	for (unsigned int i = 0; i < genes.size(); i++)
	{
		cout << "Gene " << i + 1 << ": " << endl;
		cout << "Name: " << genes.at(i).GetName() << endl;
		cout << "Genetic trait: " << genes.at(i).GetTraitType() << endl;
		cout << "Expressed allele: " << endl;
		cout << "Trait One: " << genes.at(i).GetExpressedTrait().GetTraitOneName() << endl;
		cout << "Trait Two: " << genes.at(i).GetExpressedTrait().GetTraitTwoName() << endl;
		cout << "Nucleotide sequence: " << genes.at(i).GetNucleotideSequence() << endl
			 << endl;
	}
};

vector<Gene> Chromosome::GetGenes()
{
	return genes;
}

void Chromosome::AddGene(Gene inputGene)
{
	genes.push_back(inputGene);
};

void Chromosome::ExportGene(ofstream &file, int level)
{
	int answer = ChooseGene();
	if (level == 1)
	{
		genes.at(answer).WriteToFile(file);
	}
	else
	{
		genes.at(answer).ExportAllele(file);
	}
}

void Chromosome::WriteToFile(std::ofstream &file)
{
	string fileName;
	cout << "Enter the file name." << endl;
	getline(cin, fileName);
	cout << endl;
	file.open(fileName, ios::app);
	for (unsigned int i = 0; i < genes.size(); i++)
	{
		file << genes.at(i).GetName() << "," << genes.at(i).GetTraitType() << ","
			 << genes.at(i).GetExpressedTrait().GetTraitOneName() << ","
			 << genes.at(i).GetExpressedTrait().GetTraitTwoName() << ","
			 << genes.at(i).GetAlleleA().GetTraitOneName() << ","
			 << genes.at(i).GetAlleleA().GetTraitOneType() << ","
			 << genes.at(i).GetAlleleA().GetTraitTwoName() << ","
			 << genes.at(i).GetAlleleA().GetTraitTwoType() << ","
			 << genes.at(i).GetAlleleA().GetNucleotideSequence() << ","
			 << genes.at(i).GetAlleleB().GetTraitOneName() << ","
			 << genes.at(i).GetAlleleB().GetTraitOneType() << ","
			 << genes.at(i).GetAlleleB().GetTraitTwoName() << ","
			 << genes.at(i).GetAlleleB().GetTraitTwoType() << ","
			 << genes.at(i).GetAlleleB().GetNucleotideSequence() << endl;
	}
	file.close();
};

Chromosome Chromosome::operator+(Chromosome c)
{
	vector<Gene> newGenes;
	for (unsigned int i = 0; i < this->genes.size(); i++)
	{
		if (this->genes.at(i).GetName() == c.genes.at(i).GetName())
		{
			newGenes.push_back(this->genes.at(i) + c.genes.at(i));
		}
	}
	return Chromosome(newGenes);
}

bool Chromosome::RunUnitTest()
{
	for (unsigned int i = 0; i < genes.size(); i++)
	{
		if (genes.at(i).RunUnitTest())
		{
			cout << "Gene " << i + 1 << " failed its test." << endl;
			return false;
		}
	}
	return true;
};
