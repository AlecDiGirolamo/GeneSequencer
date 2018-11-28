#pragma once
#include "Gene.hpp"
#include <vector>
#include <string>

class Chromosome
{
  private:
	std::vector<Gene> genes;
	void InputFromFile(std::ifstream &file);
	void InputManually(std::ifstream &file);
	int ChooseGene();
	bool CheckIntAnswer(std::string answer, unsigned int &assignInt);

  public:
	Chromosome(std::vector<Gene> inputGenes);
	Chromosome(std::ifstream &file);

	std::vector<Gene> GetGenes();

	void AnalyzeGenotype();
	void AddGene(Gene inputGene);

	Chromosome operator+(Chromosome c);

	void ExportGene(std::ofstream &file, int level);
	void WriteToFile(std::ofstream &file);
	bool RunUnitTest();
};