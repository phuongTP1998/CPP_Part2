/*
 * File Name:    product3.cpp
 *
 * Author:        Your Name
 * Creation Date: Monday, September 16 2019, 16:23 
 * Last Modified: Tuesday, September 24 2019, 16:37
 * 
 * File Description:
 *
 */
#include "product3.h"

Product_3::Product_3( double range, const std::string& model, int numOfP )
	:range(range), model(model), numberOfPassengers(numOfP)
{}

std::ostream& operator << ( std::ostream& os, const Product_3 & p )
{
	os << "Product_3 is an " << p.type << std::endl;
	os << "Range: " << p.range << std::endl;
	os << "Model: " << p.model << std::endl;
	os << "Number of passengers: " << p.numberOfPassengers << std::endl;
	
	return os;
}

std::ofstream& operator << ( std::ofstream& fout, const Product_3 & p )
{
	fout << "P3" << std::endl;
	fout << p.range << std::endl;
	fout << p.model << std::endl;
	fout << p.numberOfPassengers << std::endl;
	
	return fout;
}	
			
std::istream& operator >> ( std::istream& is, Product_3 & p )
{
	std::cout << "Enter range >> ";
	is >> p.range;
	is.ignore(10000, '\n');
	std::cout << "Enter model >> ";
	getline(is, p.model);
	std::cout << "Enter number of passengers >> ";
	is >> p.numberOfPassengers;
	
	is.ignore(10000, '\n');
	
	return is;
}

std::ifstream& operator >> ( std::ifstream& fin, Product_3 & p )
{
	fin >> p.range;
	fin.ignore(10000, '\n');
	getline(fin, p.model);
	fin >> p.numberOfPassengers;
	
	return fin;
}