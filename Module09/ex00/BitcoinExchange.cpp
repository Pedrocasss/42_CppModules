#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string infile) : _fileName(infile)
{
	std::cout << "BitcoinExchange object created" << std::endl;
	if (!checkFile())
		throw badInputFile();
	fillData();
	execute();
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange object destroyed" << std::endl;
}

bool BitcoinExchange::checkFile()
{
	std::ifstream fileName(_fileName.c_str());
	if (!fileName.good())
		return (false);
	return (true);
}

void BitcoinExchange::fillData()
{
	std::ifstream dataFile("data.csv");
	if (!dataFile.good())
		throw badCsvFile();
	std::string line, date, value;
	while (std::getline(dataFile, line)) {
		std::istringstream temp(line);
		if (line != "date,exchange_rate" && \
			std::getline(temp, date, ',') && \
			std::getline(temp, value))
		_data[date] = std::atof(value.c_str());
	}
}

bool BitcoinExchange::checkData(std::string date)
{
    std::istringstream dateStream(date);
    std::string yearString, monthString, dayString;
    int year, month, day;
	if (date.empty())
		return true;
    if (std::getline(dateStream, yearString, '-') && std::getline(dateStream, monthString, '-') && std::getline(dateStream, dayString))
	{
        if (yearString.find_first_not_of("0123456789") == std::string::npos && \
            monthString.find_first_not_of("0123456789") == std::string::npos && \
            dayString.find_first_not_of("0123456789") == std::string::npos)
			{

                year = std::atoi(yearString.c_str());
                month = std::atoi(monthString.c_str());
                day = std::atoi(dayString.c_str());

                if ((year >= 2009 && year < 2025) && (month > 0 && month < 13) && (day > 0 && day <= daysInMonth(month, year)))
                    return true;
            }
    }
    std::cout << "Error: bad date => " << date << std::endl;
    return false;
}

bool BitcoinExchange::checkValue(std::string value)
{
	double vDouble;
	if (value.find_first_not_of("0123456789.") == std::string::npos) {

		if (value.find_first_of('.') == value.find_last_of('.') && \
		value.find_first_of('.') != 0 && value.find_first_of('.') != value.size() - 1) {

			vDouble = std::atof(value.c_str());
			if (vDouble > 0 && vDouble < 1000)
				return (true);
		}
	}
	std::cout << "Error: bad value => " << value << std::endl;
	return (false);
}

void BitcoinExchange::execute()
{
	std::string line, date, value;
	std::ifstream inputFile(_fileName.c_str());
	while (std::getline(inputFile, line))
	{
		std::istringstream temp(line);
		if (line.empty())
			break;
		if (line != "date | value")
		{
			if (std::getline(temp, date, '|') && std::getline(temp, value))
			{
				date.erase(date.size() - 1, 1);
				value.erase(0, 1);

				if (checkData(date) && checkValue(value))
					printResult(date, value);
			}
			else
				std::cout << "Error: bad input => " << line << std::endl;
		}
	}
}

bool BitcoinExchange::isLeapYear(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int BitcoinExchange::daysInMonth(int month, int year)
{
    if (month == 2)
        return isLeapYear(year) ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
	else
        return 31;
}

void BitcoinExchange::printResult(std::string date, std::string value)
{
	double vDouble = std::atof(value.c_str());
	std::map<std::string,double>::iterator it = _data.find(date);

	if (it == _data.end()) {
		it = _data.lower_bound(date);
		if (it != _data.begin())
			it--;
	}
	std::cout << std::fixed << std::setprecision(3) << date << " => " << value << " = " << it->second * vDouble << std::endl;
}