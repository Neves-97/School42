#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void process(const std::string& filename);

private:
    std::map<std::string, double> _db;

    void loadDatabase();
    double getRate(const std::string& date) const;
    bool isValidDate(const std::string& date) const;
    bool isValidNumber(const std::string& str) const;
    bool leapYear(int year) const;
};

#endif

