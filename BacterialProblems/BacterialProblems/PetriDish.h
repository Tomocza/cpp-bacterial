#pragma once
#include <map>
#include <memory>
#include <vector>
#include <functional>

#include "Bacteria.h"

class PetriDish
{
public:
	PetriDish(int range);

	void simulate(int cycles);
	void init(
		const std::vector<std::pair<std::function<std::shared_ptr<Bacteria>(double x, double y)>, int>>& initData);

private:
	int maxRange;
	std::vector<std::shared_ptr<Bacteria>> content;
	void logContent() const;
	void addNewBacteria(const std::function<std::shared_ptr<Bacteria>(double x, double y)>& ctr);
	bool isOccupied(double x, double y);
	void executeCycle();
};
