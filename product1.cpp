/*
 * File Name:    product1.cpp
 *
 * Author:        Your Name
 * Creation Date: Monday, September 16 2019, 16:22 
 * Last Modified: Tuesday, September 24 2019, 16:37
 * 
 * File Description:
 *
 */
#include "product1.h"

Product_1::Product_1(int screenSize, double price)
  :screenSize(screenSize),price(price)
{}

std::ostream& operator << ( std::ostream& os, const Product_1& p )
{
	os << "Product_1 is a " << p.type << std::endl;
	os << "screen size: " << p.screenSize << " price: " << p.price << std::endl;
	return os;
}

std::ofstream& operator << ( std::ofstream& fout, const Product_1& p )
{
	fout << "P1" << std::endl;
	fout << p.screenSize << std::endl;
	fout << p.price << std::endl;
	return fout;
}

std::istream& operator >> ( std::istream& is, Product_1& p )
{
	std::cout << "Enter screen size >> ";
	is >> p.screenSize;
	std::cout << "Enter price >> ";
	is >> p.price;
	
	return is;
}

std::ifstream& operator >> ( std::ifstream& fin, Product_1& p )
{
	fin >> p.screenSize;
	fin >> p.price;
	fin.ignore(10000, '\n');
	
	return fin;
}
