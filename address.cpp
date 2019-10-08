/*
 * File Name:    address.cpp
 *
 * Author:        Your Name
 * Creation Date: Wednesday, September 11 2019, 14:02 
 * Last Modified: Tuesday, September 24 2019, 16:36
 * 
 * File Description:
 *
 */
#include "address.h"

Address::Address( int number, const std::string& street, int postCode )
	:number(number), street(street), postCode(postCode)
{
}

std::ostream& operator << ( std::ostream & os, const Address & a )
{
	os << "Number " << a.number << " " << a.street << " post code " << a.postCode << std::endl;
	return os;
}								   
									   
std::ofstream& operator << ( std::ofstream & fout, const Address & a )
{
	fout << a.number << std::endl;
	fout << a.street << std::endl;
	fout << a.postCode << std::endl;
	return fout;
}
									   
std::istream& operator >> ( std::istream & is, Address & a )
{
	std::cout << "Enter street number >> ";
	std::cin >> a.number;
	is.ignore(10000, '\n');
	
	std::cout << "Enter street name >> ";
	getline(std::cin, a.street);
	
	std::cout << "Enter post code >> ";
	std::cin >> a.postCode;
	
	return is;
}										 
std::ifstream& operator >> ( std::ifstream & fin, Address & a )
{
	fin >> a.number;
	fin.ignore(10000, '\n');
	getline(fin, a.street);
	fin >> a.postCode;
	
	return fin;
}

bool operator == ( const Address& a1, const Address& a2 )
{
	bool isEqual = false;
	if(a1.number == a2.number && a1.street == a2.street && a1.postCode == a2.postCode)
	{
		isEqual = true;
	} 
	return isEqual;
}