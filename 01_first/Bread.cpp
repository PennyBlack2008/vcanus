#include "Bread.hpp"

Bread::~Bread(void)
{
}

CreamBread::CreamBread(const std::string& type, int flour, int water, int varType)
	: mType(type)
	, mFlour(flour)
	, mWater(water)
	, mVarType(varType)
{
	(void)mType;
}

void	CreamBread::info(void)
{
	std::cout << "BreadType: Cream" << "\n"\
				<< "recipe\n"\
				<< "flour: " << this->mFlour << "\n"\
				<< "water: " << this->mWater << "\n"\
				<< "cream: " << this->mVarType << "\n" << std::endl;
}


SugarBread::SugarBread(const std::string& type, int flour, int water, int varType)
	: mType(type)
	, mFlour(flour)
	, mWater(water)
	, mVarType(varType)
{
	(void)mType;
}

void	SugarBread::info(void)
{
	std::cout << "BreadType: Sugar" << "\n"\
				<< "recipe\n"\
				<< "flour: " << this->mFlour << "\n"\
				<< "water: " << this->mWater << "\n"\
				<< "sugar: " << this->mVarType << "\n" << std::endl;
}

ButterBread::ButterBread(const std::string& type, int flour, int water, int varType)
	: mType(type)
	, mFlour(flour)
	, mWater(water)
	, mVarType(varType)
{
	(void)mType;
}

void	ButterBread::info(void)
{
	std::cout << "BreadType: Butter" << "\n"\
				<< "recipe\n"\
				<< "flour: " << this->mFlour << "\n"\
				<< "water: " << this->mWater << "\n"\
				<< "butter: " << this->mVarType << "\n" << std::endl;
}


Bread* Bread::makeBread(const std::string& type, int flour, int water, int varType)
{
	if (!type.compare("cream"))
		return (new CreamBread(type, flour, water, varType));
	else if (!type.compare("sugar"))
		return (new SugarBread(type, flour, water, varType));
	else if (!type.compare("butter"))
		return (new ButterBread(type, flour, water, varType));
	return (NULL);
}