#include "Spirillum.h"

#include <algorithm>

#include "Bacillus.h"

std::string Spirillum::toString() const
{
	return std::string("Spirillum: ") + std::to_string(x) + ", " + std::to_string(y);
}

void Spirillum::markForNextCycle(std::vector<std::shared_ptr<Bacteria>> dishContent)
{
	if (std::any_of(dishContent.begin(), dishContent.end(),
	                [&](const std::shared_ptr<Bacteria>& b)
	                {
		                return isNearby(b) && typeid(b) == typeid(Bacillus);
	                }))
		status = DYING;
	else
		status = SURVIVING;
}
