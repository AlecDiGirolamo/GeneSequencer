#pragma once
#include "Allele.hpp"
#include <string>
#include <fstream>

class Gene
{
  private:
	std::string name;
	std::string traitType;
	Allele alleleA;
	Allele alleleB;
	void InputFromFile(std::ifstream &file);
	void InputManually(std::ifstream &file);
	int ChooseAllele();
	bool CheckIntAnswer(std::string answer, int &assignInt);

  public:
	Gene(std::string inputName, std::string inputTraitType, Allele inputAlleleA, Allele inputAlleleB);
	Gene(std::ifstream &file);

	void SetName(std::string inputName);
	void SetTraitType(std::string inputTraitType);
	void SetAlleleA(Allele inputAlleleA);
	void SetAlleleB(Allele inputAlleleB);
	std::string GetName();
	std::string GetTraitType();
	Allele GetAlleleA();
	Allele GetAlleleB();

	Allele GetExpressedTrait();

	void WriteToFile(std::ofstream &file);
	void ExportAllele(std::ofstream &file);
	bool RunUnitTest();
};