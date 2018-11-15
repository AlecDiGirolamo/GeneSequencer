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
	Allele GetAllele(std::string alleleNumber);
	int ChooseChromosome();

  public:
	void AnalyzeChromosome();
	void CreateChromosome();
	void ImportChromosome();
	void ExportChromosome();
	Chromosome DoMeiosis(Chromosome chromosomeA, Chromosome chromosomeB);
	void SequenceChromosome(Chromosome inputChromosome);
	bool PowerOnSelfTest();
};