#pragma once
#include "Bacteria.h"

namespace bacillus
{
	constexpr double NEARBY = 0.3;
}

class Bacillus :
	public Bacteria
{
public:
	Bacillus(const double x, const double y)
		: Bacteria(x, y, bacillus::NEARBY)
	{
	}

	std::string toString() const override;
	void markForNextCycle(std::vector<std::shared_ptr<Bacteria>> dishContent) override;
};
