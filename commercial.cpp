/*
 * File Name:    commercial.cpp
 *
 * Author:        Your Name
 * Creation Date: Monday, September 16 2019, 17:27 
 * Last Modified: Tuesday, September 24 2019, 16:37
 * 
 * File Description:
 *
 */
#include "commercial.h"

constexpr double RATE = 4.50;

Commercial::Commercial( const Address& address, int openHour, int closeHour )
	:Building(address, { "Commercial" }), openHour(openHour), closeHour(closeHour)
{
	setRate();
}

void Commercial::display( ) const
{
	std::cout << *this;
}

void Commercial::setRate( )
{
	rate = RATE * (closeHour - openHour);
}

void Commercial::add()
{
	std::cout << "Enter new opening hour >> ";
	std::cin >> openHour;
	std::cout << "Enter new closing hour >> ";
	std::cin >> closeHour;
	setRate();
}

void Commercial::saveToFile( std::ofstream& fout) const
{
	fout << *this;
}

void Commercial::readFromFile( std::ifstream& fin )
{
	fin >> *this;
}

std::ostream& operator << ( std::ostream& os, const Commercial & com )
{
	os << dynamic_cast <const Building& > (com) << std::endl;
	os << "Open from " << com.openHour << " to " << com.closeHour << std::endl;
	return os;
}

std::ofstream& operator << ( std::ofstream& fout, const Commercial & com )
{
	fout << "C" << std::endl;
	fout << dynamic_cast <const Building&> (com);
	fout << com.rate << std::endl;
	fout << com.openHour << std::endl;
	fout << com.closeHour << std::endl;
	return fout;
}

std::istream& operator >> ( std::istream& is, Commercial & com )
{
	
	return is;
}

std::ifstream& operator >> ( std::ifstream& fin, Commercial & com )
{
	fin >> dynamic_cast < Building&> (com);
	fin >> com.openHour;
	fin >> com.closeHour;
	return fin;
}
