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

/* if 문을 사용하지 않고 저장할 수 있는 구조를 만들자 */
Bread* Boulangerie::makeCreamBread(const std::string& type, int flour, int water, int varType)
{
	return (new CreamBread(type, flour, water, varType));
}

/* if 문을 사용하지 않고 저장할 수 있는 구조를 만들자 */
Bread* Boulangerie::makeSugarBread(const std::string& type, int flour, int water, int varType)
{
	return (new SugarBread(type, flour, water, varType));
}

/* if 문을 사용하지 않고 저장할 수 있는 구조를 만들자 */
Bread* Boulangerie::makeButterBread(const std::string& type, int flour, int water, int varType)
{
	return (new ButterBread(type, flour, water, varType));
}