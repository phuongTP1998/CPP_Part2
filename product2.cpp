/*
 * File Name:    product2.cpp
 *
 * Author:        Your Name
 * Creation Date: Monday, September 16 2019, 16:23 
 * Last Modified: Tuesday, September 24 2019, 16:37
 * 
 * File Description:
 *
 */

#include "product2.h"

Product_2::Product_2( const std::string& colour, int racks )
	:colour(colour), racks(racks)
{}

std::ostream& operator << ( std::ostream& os, const Product_2 & p )
{
	os << "Product_2 is a " << p.type << std::endl;
	os << "Colour: " << p.colour << std::endl;
	os << "Number of racks: " << p.racks << std::endl;
	return os;
}

std::ofstream& operator << ( std::ofstream& fout, const Product_2 & p )
{
	fout << "P2" << std::endl;
	fout << p.colour << std::endl;
	fout << p.racks << std::endl;
	return fout;
}

std::istream& operator >> ( std::istream& is, Product_2 & p )
{
	std::cout << "Enter colour >> ";
	getline(is, p.colour);
	std::cout << "Enter number of racks >> ";
	is >> p.racks;
	
	
	
	return is;
}

std::ifstream& operator >> ( std::ifstream& fin, Product_2 & p )
{
	fin.ignore(10000, '\n');
	getline(fin , p.colour);
	fin >> p.racks;
	
	return fin;
}