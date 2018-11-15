#pragma once
#include <string>
#include <fstream>
class Allele
{
  private:
	std::string nucleotideSequence;
	std::string variantName;
	std::string variantType;

  public:
	Allele();
	Allele(std::string iNucleotideSequence, std::string iVariantName, std::string iVariantType);

	void SetNucleotideSequence(std::string iNucleotideSequence);
	void SetVariantName(std::string iVariantName);
	void SetVariantType(std::string iVariantType);
	std::string GetNucleotideSequence();
	std::string GetVariantName();
	std::string GetVariantType();

	void WriteAlleleToFile(std::ofstream &file);
	bool RunUnitTests();
};
