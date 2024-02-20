#include "PetriDish.h"

#include <iostream>

#include "Util.hpp"

PetriDish::PetriDish(const int range) : maxRange(range)
{
}

void PetriDish::simulate(int cycles)
{
	for (int currentCycle = 1; currentCycle <= cycles; currentCycle++)
	{
		std::cout << "Cycle: " << currentCycle << '\n';
		logContent();
		std::for_each(content.begin(), content.end(), [&](const std::shared_ptr<Bacteria>& b)
		{
			b->markForNextCycle(content);
		});
	}
}

void PetriDish::init(
	const std::vector<std::pair<std::function<std::shared_ptr<Bacteria>(double x, double y)>, int>>& initData)
{
	for (auto [ctr, amount] : initData)
	{
		for (int i = 0; i < amount; i++)
		{
			addNewBacteria(ctr);
		}
	}
}

void PetriDish::logContent() const
{
	for (const auto& bacteria : content)
	{
		std::cout << bacteria->toString() << "\n";
	}
}

void PetriDish::addNewBacteria(const std::function<std::shared_ptr<Bacteria>(double x, double y)>& ctr)
{
	double newX;
	double newY;
	do
	{
		newX = Util::random<double>(maxRange * -1, maxRange);
		newY = Util::random<double>(maxRange * -1, maxRange);
	}
	while (isOccupied(newX, newY));

	content.push_back(ctr(newX, newY));
}

bool PetriDish::isOccupied(const double x, const double y)
{
	constexpr double epsilon = 0.01;
	return std::any_of(content.begin(), content.end(), [&](const std::shared_ptr<Bacteria>& b)
	{
		return Util::getDistance(x, y, b->getX(), b->getY()) < epsilon;
	});
}

void PetriDish::executeCycle()
{
	for (auto it = content.begin(); it != content.end();)
	{
		if (it->get()->getStatus() == Bacteria::DYING)
			it = content.erase(it);
		else
			++it;
	}
}
