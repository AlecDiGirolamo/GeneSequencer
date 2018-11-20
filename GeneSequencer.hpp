#pragma once
#include "ChromosomePair.hpp"
#include <fstream>
#include <vector>

class GeneSequencer
{
  private:
	std::ofstream outputFile;
	std::ifstream inputFile;
	std::vector<ChromosomePair> chromosomePairs;
	int ChooseChromosomePair();
	bool CheckIntAnswer(std::string answer, unsigned int &assignInt);
	void ExportChromosomePair(int level);

  public:
	void AnalyzeChromosomePairs();
	void CreateChromosomePairs();
	void ExportData();
	Chromosome DoMeiosis(Chromosome chromosomeA, Chromosome chromosomeB);
	bool PowerOnSelfTest();
};