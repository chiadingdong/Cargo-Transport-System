#pragma once
#include "Vehicles.h"
#include <iostream>

class Combination
{
private:
	int m_lorry{};
	int m_van{};
	int m_totalCost{};
	int m_trips{};
public:
	Combination(int lorry, int van, int totalCost, int trips);

	int getCost() const;
	int getTrips() const;

	friend std::ostream& operator<<(std::ostream& os, const Combination& obj) {
		os << obj.m_totalCost << ' ' << obj.m_van << ' ' << obj.m_lorry << ' ' << obj.m_trips;
		return os;
	}
};



