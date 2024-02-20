// BacterialProblems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <functional>
#include <iostream>
#include <map>
#include <vector>

#include "Bacillus.h"
#include "Coccus.h"
#include "Spirillum.h"
#include "Bacteria.h"
#include "PetriDish.h"


int main()
{
	std::function<std::shared_ptr<Bacteria>(double x, double y)> BACILLUS_CTR = [](double x, double y)
	{
		return std::make_shared<Bacillus>(x, y);
	};
	std::function<std::shared_ptr<Bacteria>(double x, double y)> COCCUS_CTR = [](double x, double y)
	{
		return std::make_shared<Coccus>(x, y);
	};
	std::function<std::shared_ptr<Bacteria>(double x, double y)> SPIRILLUM_CTR = [](double x, double y)
	{
		return std::make_shared<Spirillum>(x, y);
	};

	PetriDish dish(50);

	std::vector<std::pair<std::function<std::shared_ptr<Bacteria>(double x, double y)>, int>> initData;
	initData.emplace_back(BACILLUS_CTR, 10);
	initData.emplace_back(COCCUS_CTR, 10);
	initData.emplace_back(SPIRILLUM_CTR, 10);

	dish.init(initData);
	dish.simulate(10);
	return 0;
}
