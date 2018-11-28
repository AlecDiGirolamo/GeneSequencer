#pragma once
#include "Allele.hpp"
#include <string>
#include <fstream>

class Gene
{
  private:
	std::string name;
	std::string traitType;
	std::string nucleotideSequence;
	Allele alleleA;
	Allele alleleB;
	Allele expressedTraits;
	void InputFromFile(std::ifstream &file);
	void InputManually(std::ifstream &file);
	int ChooseAllele();
	bool CheckIntAnswer(std::string answer, int &assignInt);

  public:
	Gene(std::string inputName, std::string inputTraitType, Allele inputExpressedTraits, Allele inputAlleleA, Allele inputAlleleB);
	Gene(std::ifstream &file);

	/*
	void SetName(std::string inputName);
	void SetTraitType(std::string inputTraitType);
	void SetExpressedTraits(Allele inputExpressedTraits);
	void SetAlleleA(Allele inputAlleleA);
	void SetAlleleB(Allele inputAlleleB);
	*/

	std::string GetName();
	std::string GetTraitType();
	std::string GetNucleotideSequence();
	Allele GetAlleleA();
	Allele GetAlleleB();

	Allele GetExpressedTrait();
	void CalculateExpressedTrait();

	Gene operator+(Gene g);

	void WriteToFile(std::ofstream &file);
	void ExportAllele(std::ofstream &file);
	bool RunUnitTest();
};