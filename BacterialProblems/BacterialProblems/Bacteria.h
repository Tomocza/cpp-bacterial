#pragma once
#include <memory>
#include <string>
#include <vector>

class Bacteria
{
public:
	enum Status { STANDBY, DYING, SURVIVING };

	Bacteria(const double x, const double y, const double nearby) : x(x), y(y), nearby(nearby)
	{
	}

	bool isNearby(const std::shared_ptr<Bacteria>& b) const;
	double getX() const;
	double getY() const;
	Status getStatus() const;
	virtual std::string toString() const = 0;
	virtual void markForNextCycle(std::vector<std::shared_ptr<Bacteria>> dishContent) = 0;

protected:
	double x;
	double y;
	Status status{STANDBY};
	double nearby;
};
