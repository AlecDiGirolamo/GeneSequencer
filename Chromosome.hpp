#pragma once
#include "Gene.hpp"
#include <vector>
#include <string>

class Chromosome
{
  private:
	int number;
	std::vector<Gene> genes;

  public:
	Chromosome();
	Chromosome(int inputNumber);

	void AnalyzeGenotype();
	void InputFromFile(std::ifstream &file);
	void OutputToFile(std::ofstream &file);
	void AddGene(Gene inputGene);
	int GetNumber();
	Gene FindGene(std::string name);
	Chromosome operator+(Chromosome inputChromosome);
	bool RunUnitTest();
};