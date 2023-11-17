#include <iomanip>
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
	while (std::getline(file, Line)) {
		if (!validateInput(Line)) {
			std::cout << "Error: Bad input! => " << Line << std::endl;
		}
		else {
			value = std::strtod((Line.substr(Line.find_first_of('|') + 1, Line.size()).c_str()),NULL);
			it = BTC.find(Line.substr(0, Line.find_first_of('|') - 1));
			if (it == BTC.end()) {
				it = (BTC.lower_bound(Line.substr(0, Line.find_first_of('|') - 1)));
				if (it != BTC.begin()) {
					--it;
				}
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
	std::string Year, Month, Day, d1, d2, sep, val;
	int IMonth(0), IDay(0);
	float IVal(0);
	if (Line.length() < 9) {
		return (false);
	}

	if (Line.size() < 14 || Line.size() > 16)
		return (false);
	Year = Line.substr(0,4);
	d1 = Line.substr(4,1);
	Month = Line.substr(5,2);
	d2 = Line.substr(7,1);
	Day = Line.substr(8,2);
	sep = Line.substr(10,3);
	val = Line.substr(13,4);

	if (d1 != "-" || d2 != "-") {
		return (false);
	}

	for (int i = 0; i < 4; ++i) {
		if (isdigit(Year[i]) == false)
			return (false);
	}

	for (int i = 0; i < 2; ++i) {
		if (isdigit(Month[i]) == false) {
			return (false);
		}
	}
	IMonth = std::strtod(Month.c_str(),NULL);
	if (IMonth <= 0 || IMonth > 12) {
		return (false);
	}

	for (int i = 0; i < 2; ++i) {
		if (isdigit(Day[i]) == false)
			return (false);
	}
	IDay = std::strtod(Day.c_str(),NULL);
	if (IDay <= 0 || IDay > 31){
		return (false);
	}

		if (sep != " | "){
			return (false);
		}

	for (long unsigned int i = 0; i < val.size(); ++i) {
		if (isdigit(val[i]) == false && val[i] != '.'){
			return (false);
		}
	}
	IVal = std::strtod(val.c_str(),NULL);
	if (IVal < 0 || IVal > 1000) {
		return (false);
	}
	return (true);

}
