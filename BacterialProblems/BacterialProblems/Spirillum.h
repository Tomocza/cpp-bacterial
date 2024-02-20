#pragma once
#include "Bacteria.h"

namespace spirillum
{
	constexpr double NEARBY = 0.2;
}

class Spirillum :
	public Bacteria
{
public:
	Spirillum(const double x, const double y)
		: Bacteria(x, y, spirillum::NEARBY)
	{
	}

	std::string toString() const override;
	void markForNextCycle(std::vector<std::shared_ptr<Bacteria>> dishContent) override;
};
