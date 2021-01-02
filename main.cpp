#include "Combination.h"

#include <iostream>
#include <vector>
#include <algorithm>

void calculateCombinations(int cargo2transport, std::vector<Combination> &vec);

int main()
{
	int cargo2Transport = 100;	
	std::vector<Combination> vec;

	calculateCombinations(cargo2Transport,vec);

	//sort in ascending for totalCost
	std::sort(vec.begin(), vec.end(),
		[](const auto &lhs, const auto &rhs) {
			return lhs.getCost() < rhs.getCost();
		});

	//display 3 lowest
	for (int i = 0; i < 3; ++i) {
		std::cout << "Lowest#"<< i << ": $"<< vec[i] << '\n';
	}

	//sort in ascending for trips
	std::sort(vec.begin(), vec.end(),
		[](const auto& lhs, const auto& rhs) {
			return lhs.getTrips() < rhs.getTrips();
		});

		for (const auto& elm : vec) {
			std::cout << elm << '\n';
		}

	
}

void calculateCombinations(int cargo2Transport, std::vector<Combination> &vec) {
	int lorry{}, van{}, totalCost{}, trips{};
	int lorryCapacity = vechicle::miniLorry.first;
	int vanCapacity = vechicle::van.first;

	int remainder = cargo2Transport % lorryCapacity;
	int maxLorry = (cargo2Transport - remainder) / lorryCapacity;

	for (int i = 0; i <= maxLorry; ++i) {
		lorry = i;
		van = (cargo2Transport - lorry * lorryCapacity)/ vanCapacity ;
		totalCost = lorry * vechicle::miniLorry.second + van * vechicle::van.second;
		trips = std::max(lorry, van);
		vec.emplace_back(lorry, van, totalCost, trips);
	}
}
