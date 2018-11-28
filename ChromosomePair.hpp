/*
#pragma once
#include "Chromosome.hpp"
#include <fstream>

class ChromosomePair
{
  private:
	Chromosome chromosomeA;
	Chromosome chromosomeB;
	void InputFromFile(std::ifstream &file);
	void InputManually(std::ifstream &file);
	int ChooseChromosome();
	bool CheckIntAnswer(std::string answer, int &assignAnswer);

  public:
	ChromosomePair(std::ifstream &file);

	Chromosome GetChromosomeA();
	Chromosome GetChromosomeB();

	void WriteToFile(std::ofstream &file);
	void ExportChromosome(std::ofstream &file, int level);
	bool RunUnitTest();
};
*/