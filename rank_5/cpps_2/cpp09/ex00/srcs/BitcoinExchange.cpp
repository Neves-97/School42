#include "../incs/BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {
    loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::leapYear(int year) const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int y, m, d;
    char sep1, sep2;
    std::istringstream iss(date);
    if (!(iss >> y >> sep1 >> m >> sep2 >> d) || sep1 != '-' || sep2 != '-')
        return false;

    if (y < 0 || m < 1 || m > 12 || d < 1)
        return false;

    const int daysInMonth[] = { 31, (leapYear(y) ? 29 : 28), 31, 30, 31, 30,
                                31, 31, 30, 31, 30, 31 };
    if (d > daysInMonth[m - 1])
        return false;

    return true;
}

bool BitcoinExchange::isValidNumber(const std::string& str) const {
    std::istringstream iss(str);
    double val;
    iss >> val;
    return !iss.fail() && iss.eof();
}

void BitcoinExchange::loadDatabase() {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: could not open data.csv" << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, value;
        if (std::getline(iss, date, ',') && std::getline(iss, value)) {
            double rate = std::atof(value.c_str());
            _db[date] = rate;
        }
    }
    file.close();
}

double BitcoinExchange::getRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = _db.lower_bound(date);
    if (it != _db.end() && it->first == date)
        return it->second;
    if (it == _db.begin())
        return 0;
    --it;
    return it->second;
}

void BitcoinExchange::process(const std::string& filename) {
    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    if (!std::getline(infile, line)) {
        std::cerr << "Error: input file is empty." << std::endl;
        return;
    }

    bool hasData = false;
    while (std::getline(infile, line)) {
        hasData = true;

        size_t pipe = line.find('|');
        if (pipe == std::string::npos) {
            std::cerr << "bad input " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipe);
        std::string value = line.substr(pipe + 1);

        // Trim
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);

        if (!isValidDate(date)) {
            std::cerr << "bad input " << line << std::endl;
            continue;
        }

        if (!isValidNumber(value)) {
            std::cerr << "Not a valid number " << std::endl;
            continue;
        }

        double amount = std::atof(value.c_str());
        if (amount < 0) {
            std::cerr << "number entered was not a positive number" << std::endl;
            continue;
        }
        if (amount > 1000) {
            std::cerr << "number entered was to large" << std::endl;
            continue;
        }

        double rate = getRate(date);
        double result = rate * amount;

        std::cout << date << " : " << value << " = " << result << std::endl;
    }

    if (!hasData)
        std::cerr << "input file empty or with only header" << std::endl;
}