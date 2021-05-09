#ifndef BREAD_HPP
# define BREAD_HPP

#include <iostream>
#include <string>

class Bread
{
public:
	//Factory 함수 -> makeBread
	static Bread* makeBread(const std::string& type, int flour, int water, int varType);
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