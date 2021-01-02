#include "Combination.h"

Combination::Combination(int lorry, int van, int totalCost, int trips)
	:m_lorry{ lorry }, m_van{ van }, m_totalCost{ totalCost }, m_trips{ trips }
{
}

int Combination::getCost() const {
	return m_totalCost;
}

int Combination::getTrips() const {
	return m_trips;
}