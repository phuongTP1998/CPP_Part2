/*
 * File Name:    residential.cpp
 *
 * Author:        Your Name
 * Creation Date: Monday, September 16 2019, 16:48 
 * Last Modified: Tuesday, September 24 2019, 16:37
 * 
 * File Description:
 *
 */
#include "residential.h"

constexpr double RATE = 4.78;

Residential:: Residential( const Address& address, int numPeople )
	:Building(address, {"Residential"}), numberOfPeople(numPeople)
{
	setRate();
}

void Residential::display( ) const
{
	std::cout << *this;
}

void Residential::setRate( ) 
{
	rate = RATE * numberOfPeople;
}

void Residential::add()
{
	std::cout << "Enter number of people in this building >> ";
	std::cin >> numberOfPeople;
	setRate();
}

void Residential::saveToFile( std::ofstream& fout ) const
{
	fout << *this;
}

void Residential::readFromFile( std::ifstream& fin )
{
	fin >> *this;
}
	
std::ostream& operator << (std::ostream& os, const Residential & res )
{
	os << dynamic_cast <const Building& > (res) << std::endl;
	os << "Number of people in this building " << res.numberOfPeople << std::endl;
	return os;
}

std::ofstream& operator << (std::ofstream& fout, const Residential & res )
{
	fout << "R" << std::endl;
	fout << dynamic_cast <const Building& > (res);
	fout << res.rate << std::endl;
	fout << res.numberOfPeople << std::endl;
	return fout;
}

std::istream& operator >> (std::istream& is, Residential & res )
{
	return is;
}

std::ifstream& operator >> (std::ifstream& fin, Residential & res )
{
	fin >> dynamic_cast <Building& > (res);
	fin >> res.numberOfPeople;
	fin.ignore(10000, '\n');
	
	return fin;
}