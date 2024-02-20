#pragma once
#include "Bacteria.h"

namespace coccus
{
	constexpr double NEARBY = 0.1;
}

class Coccus :
	public Bacteria
{
public:
	Coccus(const double x, const double y)
		: Bacteria(x, y, coccus::NEARBY)
	{
	}

	std::string toString() const override;
	void markForNextCycle(std::vector<std::shared_ptr<Bacteria>> dishContent) override;
};
