#include "Coccus.h"

std::string Coccus::toString() const
{
	return std::string("Coccus: ") + std::to_string(x) + ", " + std::to_string(y);
}

void Coccus::markForNextCycle(std::vector<std::shared_ptr<Bacteria>> dishContent)
{
	int nearbyCount = 0;
	for (const auto& bacteria : dishContent)
	{
		if (isNearby(bacteria)) nearbyCount++;
	}
	if (nearbyCount > 1) status = SURVIVING;
	else status = DYING;
}
