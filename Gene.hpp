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

  public:
	Gene();
	Gene(std::string inputName, std::string inputTraitType, Allele inputAlleleA, Allele inputAlleleB);

	void SetName(std::string inputName);
	void SetTraitType(std::string inputTraitType);
	void SetAlleleA(Allele inputAlleleA);
	void SetAlleleB(Allele inputAlleleB);

	std::string GetName();
	std::string GetTraitType();
	Allele GetAlleleA();
	Allele GetAlleleB();

	Allele GetExpressedTrait();
	bool RunUnitTest();
	void WriteToFile(std::ofstream &file);
};