/*
 * File Name:    building.cpp
 *
 * Author:        Your Name
 * Creation Date: Wednesday, September 11 2019, 13:38 
 * Last Modified: Tuesday, September 24 2019, 16:36
 * 
 * File Description:
 *
 */
#include "building.h"

Building::Building( const Address& a, const std::string& type )
	:address(a), type(type)
{
}

void Building::display() const
{
	std::cout << *this;
}

void Building::saveToFile( std::ofstream& fout) const
{
	fout << *this;
}

void Building::readFromFile( std::ifstream& fin ) 
{
	fin >> *this;
}



std::ostream& operator << ( std::ostream& os, const Building& b)
{
	os << "Building" << std::endl;
	os << "\t" << "Type : " << b.type << std::endl;
	os << "\t" << "Address : " << b.address;
	os << "\t" << "Rates : " << b.rate;
	return os;
}

std::ofstream& operator << ( std::ofstream& fout, const Building& b)
{	
	fout << b.type << std::endl;
	fout << b.address;
	return fout;
}

std::istream& operator >> ( std::istream& is, Building& b )
{	
	return is;
}

std::ifstream& operator >> ( std::ifstream& fin, Building& b )
{
	fin >> b.type;
	fin >> b.address;
	fin >> b.rate;
	return fin;
}
