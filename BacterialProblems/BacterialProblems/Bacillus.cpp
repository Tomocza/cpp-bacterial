#include "Bacillus.h"

#include "Coccus.h"

std::string Bacillus::toString() const
{
	return std::string("Bacillus: ") + std::to_string(x) + ", " + std::to_string(y);
}

void Bacillus::markForNextCycle(std::vector<std::shared_ptr<Bacteria>> dishContent)
{
	for (const auto& bacteria : dishContent)
	{
		if (this->isNearby(bacteria) && typeid(bacteria) == typeid(Coccus))
		{
			status = SURVIVING;
			break;
		}
	}
	status = DYING;
}
