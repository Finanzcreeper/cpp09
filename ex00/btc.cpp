#include "btc.hpp"

void btc (char *input) {
	std::ifstream file(input);
	std::ifstream btcdb("data.csv");
	int dbmult(0);
	std::string dbDate;
	std::string dbLine;
	std::map<std::string,double>BTC;

	if (!btcdb.is_open()) {
		std::cout << "Error: Database cant be opened" << std::endl;
	}
	if (!file.is_open()) {
		std::cout << "Error: File cant be opened" << std::endl;
	}

	while(std::getline(btcdb,dbLine)) {
		dbDate = dbLine.substr(0, dbLine.find(','));
		dbmult = std::atoi(dbLine.substr(dbLine.find(','), dbLine.size()).c_str());
		BTC.insert(std::make_pair(dbDate, dbmult));
	}
	std::map<std::string,double>::iterator it = BTC.begin();
	while (it != BTC.end()) {
		std::cout << it->first << ", " << it->second << std::endl;
		++it;
	}
}
