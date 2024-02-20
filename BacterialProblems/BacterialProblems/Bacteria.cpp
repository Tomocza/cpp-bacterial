#include "Bacteria.h"

#include "Util.hpp"

bool Bacteria::isNearby(const std::shared_ptr<Bacteria>& b) const
{
	return Util::getDistance(x, y, b->getX(), b->getY()) <= nearby;
}

double Bacteria::getX() const
{
	return x;
}

double Bacteria::getY() const
{
	return y;
}

Bacteria::Status Bacteria::getStatus() const
{
	return status;
}
