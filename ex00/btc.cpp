#include "btc.hpp"
#include <sstream>

void btc (char *input) {
	std::ifstream file(input);
	std::ifstream btcdb("data.csv");
	double dbmult(0);
	std::string dbDate;
	std::string Line;
	std::map<std::string,double> BTC;
	std::map<std::string,double>::iterator it = BTC.begin();

	//open Files//
	if (!btcdb.is_open()) {
		std::cout << "Error: Database cant be opened" << std::endl;
	}
	if (!file.is_open()) {
		std::cout << "Error: File cant be opened" << std::endl;
	}
	//Read reference DB//
	while(std::getline(btcdb,Line)) {
		dbDate = Line.substr(0, Line.find(','));
		dbmult = std::strtod((Line.substr(Line.find(',') + 1, Line.size()).c_str()),NULL);
		BTC.insert(std::make_pair(dbDate, dbmult));
	}
	float value(0);
	std::getline(file, Line);
	while (std::getline(file, Line)) {
		if (!validateInput(Line)) {
			std::cout << "Error: Bad input! => " << Line << std::endl;
		}
		else {
			value = std::strtod((Line.substr(Line.find_first_of('|') + 1, Line.size()).c_str()),NULL);
			it = BTC.find(Line.substr(0, Line.find_first_of('|') - 1));
			if (it == BTC.end()) {
				it = --(BTC.lower_bound(Line.substr(0, Line.find_first_of('|') - 1)));
			}
			std::cout << it->first << " => " << it->second << " * " << value << " = " << value * it->second << std::endl;
		}
	}
// ----------------------------------
//==========input db printer==========
// ----------------------------------
//	while (it != BTC.end()) {
//		std::cout << it->first << ", " << it->second << std::endl;
//		++it;
//	}
}

bool validateInput(const std::string& Line) {
	int Year(0), Month(0), Day(0);
	char d1, d2, sep;
	float val(0);
	std::istringstream Lineval(Line);
	if (Lineval >> Year >> d1 >> Month >> d2 >> Day >> sep >> val) {
		if (d1 == '-' && d2 == '-' && Month >= 1 && Month <= 12 && Day >= 1 && Day <= 31 && sep == '|' && val >= 0 && val <= 1000) {
			//std::cout << Year << d1 << Month << d2 << Day << " => ";
			return (true);
		}
	}
	return (false);
}
