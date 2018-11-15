/*	Project:    Gene Sequencer
	Name:       Alec DiGirolamo
    Partner:    None
    Class:      CSC 1810 - Section 1
*/

#include <iostream>
#include "GeneSequencer.hpp"
#include "Chromosome.hpp"
#include <string>
using namespace std;

int displayMenu()
{
	cout << "Please select one of the following menu options." << endl;
	cout << "1. Create Chromosome" << endl;
	cout << "2. Analyze Chromosome" << endl;
	cout << "3. Output Chromsome to File" << endl;
	cout << "4. Input Chromosome from File" << endl;
	cout << "5. Combine Chromosomes" << endl;
	cout << "6. Exit" << endl;

	string userChoice;
	getline(cin, userChoice);
	while (true)
	{
		if (userChoice == "1")
		{
			return 1;
		}
		else if (userChoice == "2")
		{
			return 2;
		}
		else if (userChoice == "3")
		{
			return 3;
		}
		else if (userChoice == "4")
		{
			return 4;
		}
		else if (userChoice == "5")
		{
			return 5;
		}
		else if (userChoice == "6")
		{
			return 6;
		}
		else
		{
			cout << "Please choose one of the given menu options." << endl;
			getline(cin, userChoice);
		}
	}
}

int main(int argc, char *argv[])
{
	GeneSequencer geneSequencer;

	int userChoice;

	while ((userChoice = displayMenu()) != 6)
	{
		switch (userChoice)
		{
		case 1:
			geneSequencer.CreateChromosome();
			break;
		case 2:
			geneSequencer.AnalyzeChromosome();
			break;
		case 3:
			geneSequencer.ExportChromosome();
			break;
		case 4:
			geneSequencer.ImportChromosome();
			break;
		case 5:
			geneSequencer.DoMeiosis(Chromosome(), Chromosome());
			break;
		default:
			cout << "There was a problem with the selected menu option: " << userChoice << endl;
			break;
		}
	}

	{
		cout << "Hit enter to exit:";
		cin.get();
	}
	return 0;
}