#ifndef CPP09_BTC_HPP
#define CPP09_BTC_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>

void	btc (char *input);
std::map<std::string ,double>::iterator findLoc(std::map<std::string, double> BTC, std::string Line);
bool validateInput(const std::string& Line);

#endif //CPP09_BTC_HPP
