#ifndef BREAD_HPP
# define BREAD_HPP

#include <iostream>
#include <string>

class Bread;
// Bread Factory
class Boulangerie
{
public:
	static Bread* makeCreamBread(const std::string& type, int flour, int water, int varType);
	static Bread* makeSugarBread(const std::string& type, int flour, int water, int varType);
	static Bread* makeButterBread(const std::string& type, int flour, int water, int varType);
};

class Bread
{
public:
	virtual void info() = 0;
	virtual ~Bread();
};

class CreamBread : public Bread
{
public:
	CreamBread(const std::string& type, int flour, int water, int varType);
	void info(void);
private:
	const std::string& mType;
	int mFlour;
	int mWater;
	int mVarType;
};

class SugarBread : public Bread
{
public:
	SugarBread(const std::string& type, int flour, int water, int varType);
	void info(void);
private:
	const std::string& mType;
	int mFlour;
	int mWater;
	int mVarType;
};

class ButterBread : public Bread
{
public:
	ButterBread(const std::string& type, int flour, int water, int varType);
	void info(void);
private:
	const std::string& mType;
	int mFlour;
	int mWater;
	int mVarType;
};

#endif