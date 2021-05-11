#include "Bread.hpp"
#include <map>
#include <string>
#include <fstream>

int main(int argc, char** argv)
{
	/*******************************
	 *  parsing json file
	 * *****************************/
	std::ifstream			ifs;
	std::string				line;
	std::string::size_type	pos;
	std::string::size_type	pos_quote;
	std::string::size_type	pos_comma;

	int flour = 0, water = 0, typeAmount = 0;

	/* argument check */
	if (argc != 2)
	{
		std::cout << "Error : Wrong argument\n";
		return (-1);
	}

	/* is file valid? */
	ifs.open(argv[1]);
	if (!ifs.is_open())
	{
		std::cout << "Error : file error\n";
		return (-1);
	}

	/* map container initialized */
	std::map<Bread*, std::string> data;
	std::map<Bread*, std::string>::iterator it = data.begin();

	while (getline(ifs, line) != 0)
	{
		std::string BreadType = ""; // 초기화
		flour = 0; water = 0; typeAmount = 0;

		/* parse BreadType*/
		pos = line.find("\"breadType\": \"");
		if (pos != std::string::npos)
		{
			pos_quote = line.find("\"", pos + 14);
			BreadType = line.substr(pos + 14, pos_quote - pos - 14); // BreadType

			/* cream, sugar, butter 중 하나가  아니라면, 에러 */
			if (!(!BreadType.compare("cream") || !BreadType.compare("sugar") || !BreadType.compare("butter")))
			{
				std::cerr << "wrong input.json format" << std::endl;
				exit(1);
			}

			/* recipe */
			getline(ifs, line);
			if ((pos = line.find("recipe")) == std::string::npos)
			{
				std::cerr << "wrong input.json format" << std::endl;
				exit(1);
			}

			/* flour */
			getline(ifs, line);
			if ((pos = line.find("flour")) == std::string::npos)
			{
				std::cerr << "wrong input.json format" << std::endl;
				exit(1);
			}
			if ((pos_comma = line.find(",", pos)) == std::string::npos)
			{
				std::cerr << "wrong input.json format" << std::endl;
				exit(1);
			}
			flour = std::stoi(line.substr(pos + 8, pos_comma - pos - 8));

			/* water */
			getline(ifs, line);
			if ((pos = line.find("water")) == std::string::npos)
			{
				std::cerr << "wrong input.json format" << std::endl;
				exit(1);
			}
			if ((pos_comma = line.find(",", pos)) == std::string::npos)
			{
				std::cerr << "wrong input.json format" << std::endl;
				exit(1);
			}
			water = std::stoi(line.substr(pos + 8, pos_comma - pos - 8));

			/* typeAmount */
			getline(ifs, line);
			if ((pos = line.find(":")) == std::string::npos)
			{
				std::cerr << "wrong input.json format" << std::endl;
				exit(1);
			}
			typeAmount = std::stoi(line.substr(pos + 1, line.length()));

			/* } */
			getline(ifs, line);
			if ((pos = line.find("}")) == std::string::npos)
			{
				std::cerr << "wrong input.json format" << std::endl;
				exit(1);
			}

			/* insert Bread into data container */
			data.insert(std::pair<Bread*, std::string>(Boulangerie::makeCreamBread(BreadType, flour, water, typeAmount), BreadType));
		}
	}

	/*******************************
	 *  print Bread
	 * *****************************/
	for (it = data.begin(); it != data.end(); ++it)
		(*it).first->info();
	for (it = data.begin(); it != data.end(); ++it)
		delete (*it).first;
	return (0);
}
