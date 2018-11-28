#pragma once
#include "Chromosome.hpp"
#include <fstream>
#include <vector>

class GeneSequencer
{
  private:
	std::ofstream outputFile;
	std::ifstream inputFile;
	std::vector<Chromosome> chromosomes;
	int ChooseChromosome();
	bool CheckIntAnswer(std::string answer, unsigned int &assignInt);
	void ExportChromosome(int level);
	bool testChromosomes(Chromosome chromosomeA, Chromosome chromosomeB);

  public:
	void AnalyzeChromosomes();
	void CreateChromosomes();
	void ExportData();
	void DoMeiosis();
	bool PowerOnSelfTest();
};