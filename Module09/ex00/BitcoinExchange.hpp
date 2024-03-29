#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <exception>
# include <sstream>
# include <cstdlib>
#include <iomanip>
class BitcoinExchange {
	private:
		std::string _fileName;
		std::map<std::string,double> _data;
	public:
		BitcoinExchange(std::string infile);
		~BitcoinExchange();

		bool checkFile();
		void fillData();
		void execute();
		void printResult(std::string date, std::string value);

		bool checkData(std::string date);
		bool checkValue(std::string value);
        bool isLeapYear(int year);
        int daysInMonth(int month, int year);

		class badCsvFile : public std::exception{
		public:
			virtual const char* what() const throw() { return "Error bad data.csv file"; };
		};
		class badInputFile: public std::exception{
		public:
			virtual const char* what() const throw() { return "Error bad input file"; };
		};
        class invalidDateException : public std::exception{
        public:
            virtual const char* what() const throw() { return "Error bad date"; };
        };
};
#endif