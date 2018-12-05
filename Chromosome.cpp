#include "Gene.hpp"
#include "Chromosome.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

bool Chromosome::CheckIntAnswer(string answer, unsigned int &assignInt)
{
	if (answer.size() == 0)
	{
		return false;
	}
	for (unsigned int i = 0; i < answer.size(); i++)
	{
		if (!isdigit(answer.at(i)))
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
		file.open(fileName);
		string line;
		bool dataIsValid = false;

		while (getline(file, line))
		{

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
					cout << "Nucleotide sequence has an invalid amount of character." << endl;
					break;
				}
				string tempName = row.at(0);
				string tempTraitType = row.at(1);
				Allele tempAlleleA = Allele(row.at(4), row.at(5), row.at(6));
				Allele tempAlleleB = Allele(row.at(7), row.at(8), row.at(9));
				string tempOneType;
				string tempTwoType;
				if (row.at(2) == tempAlleleA.GetTraitOneName())
				{
					tempOneType = tempAlleleA.GetTraitOneType();
				}
				else
				{
					tempOneType = tempAlleleB.GetTraitOneType();
				}
				if (row.at(3) == tempAlleleA.GetTraitTwoName())
				{
					tempTwoType = tempAlleleA.GetTraitTwoType();
				}
				else
				{
					tempTwoType = tempAlleleB.GetTraitTwoType();
				}

				Allele tempExpressedTraits = Allele(row.at(2), tempOneType, row.at(3), tempTwoType, "00");
				if ((tempExpressedTraits.GetTraitOneName() != tempAlleleA.GetTraitOneName() && tempExpressedTraits.GetTraitOneName() != tempAlleleB.GetTraitOneName()) || (tempExpressedTraits.GetTraitTwoName() != tempAlleleA.GetTraitTwoName() && tempExpressedTraits.GetTraitTwoName() != tempAlleleB.GetTraitTwoName()))
				{
					cout << "The expressed alleles do not match any of the given alleles in a gene." << endl;
					break;
				}
				else
				{
					genes.push_back(Gene(tempName, tempTraitType, tempExpressedTraits, tempAlleleA, tempAlleleB));
					dataIsValid = true;
				}
			}
			else
			{
				cout << "There was an invalid amount of data found in a row." << endl;
				cout << "Please use the example csv format." << endl;
				break;
			}
		}

		file.close();
		if (dataIsValid)
		{
			break;
		}
		else
		{
			cout << "There was a problem with the selected file." << endl;
		}
	}
};

void Chromosome::InputManually(ifstream &file)
{
	while (true)
	{
		genes.push_back(Gene(file));
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
			genes.push_back(Gene(file));
		}
		else
		{
			break;
		}
	}
};

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
				cout << "No gene with that number was found." << endl;
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

void Chromosome::ExportGene(ofstream &file, int level)
{
	int answer = ChooseGene();
	if (level == 2)
	{
		genes.at(answer).WriteToFile(file);
	}
	else
	{
		genes.at(answer).ExportAllele(file);
	}
};

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
			 << genes.at(i).GetAlleleA().GetTraitTwoName() << ","
			 << genes.at(i).GetAlleleA().GetNucleotideSequence() << ","
			 << genes.at(i).GetAlleleB().GetTraitOneName() << ","
			 << genes.at(i).GetAlleleB().GetTraitTwoName() << ","
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
		if (!genes.at(i).RunUnitTest())
		{
			cout << "Gene " << i + 1 << " failed its test." << endl;
			return false;
		}
	}
	if (genes.size() == 0)
	{
		cout << "Invalid gene count" << endl;
		return false;
	}
	return true;
};
