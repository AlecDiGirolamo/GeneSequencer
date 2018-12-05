#pragma once
#include <string>
#include <fstream>
class Allele
{
  private:
	std::string nucleotideSequence;
	std::string traitOneName;
	std::string traitOneType;
	std::string traitTwoName;
	std::string traitTwoType;

	void InputManually();
	void InputFromFile(std::ifstream &file);

  public:
	Allele();
	Allele(std::ifstream &file);
	Allele(std::string inputTraitOneName, std::string inputTraitTwoName, std::string inputNucleotideSequence);
	Allele(std::string inputTraitOneName, std::string inputTraitOneType, std::string inputTraitTwoName, std::string inputTraitTwoType, std::string inputNucleotideSequence);

	/*
	void SetTraitOneName(std::string inputTraitOneName);
	void SetTraitOneType(std::string inputTraitOneType);
	void SetTraitTwoName(std::string inputTraitTwoName);
	void SetTraitTwoType(std::string inputTraitTwoType);
	void SetNucleotideSequence(std::string iNucleotideSequence);
	*/

	std::string GetTraitOneName();
	std::string GetTraitOneType();
	std::string GetTraitTwoName();
	std::string GetTraitTwoType();
	std::string GetNucleotideSequence();

	Allele operator+(Allele a);

	void WriteToFile(std::ofstream &file);
	bool RunUnitTests();
};
