#pragma once
#include <cmath>
#include <random>

class Util
{
public:
	static double getDistance(const double x1, const double y1, const double x2, const double y2)
	{
		return sqrt(std::pow(x2 - x1, 2) + pow(y2 - y1, 2));
	}

	template <typename Numeric, typename Generator = std::mt19937>
	static Numeric random(Numeric from, Numeric to)
	{
		thread_local static Generator gen(std::random_device{}());

		using DistType = typename std::conditional
		<
			std::is_integral<Numeric>::value
			, std::uniform_int_distribution<Numeric>
			, std::uniform_real_distribution<Numeric>
		>::type;

		thread_local static DistType dist;

		return dist(gen, typename DistType::param_type{from, to});
	}
};
