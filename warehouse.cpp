/*
 * File Name:    warehouse.cpp
 *
 * Author:        Your Name
 * Creation Date: Monday, September 16 2019, 16:23 
 * Last Modified: Tuesday, September 24 2019, 16:37
 * 
 * File Description:
 *
 */
// #include "warehouse.h" not required as we are including the
//                        warehouse.cpp file inside the warehouse.h
//                        file

constexpr double RATE = 79.22;

template <typename T>
Warehouse<T>::Warehouse( const Address& a, const T& product, int quantity )
	:Building(a, {"Warehouse"}), product(product), quantity(quantity)
{
	setRate();
}

template <typename T>
void Warehouse<T>::setRate( ) 
{
	rate = RATE * quantity;
}

template <typename T>
void Warehouse<T>::display( ) const 
{
	std::cout << *this;
}

template <typename T>
void Warehouse<T>::saveToFile( std::ofstream& fout ) const 
{
	fout << *this;
}

template <typename T>
void Warehouse<T>::readFromFile( std::ifstream& fin )
{
	fin >> *this;
}

template <typename T>
void Warehouse<T>::add( )  
{
	std::cout << "Enter quantity >> ";
	std::cin >> quantity;
	setRate();
}

template <typename T>
std::ostream& operator << ( std::ostream& os, const Warehouse < T > & w )
{
	os << dynamic_cast <const Building&> (w) << std::endl;
	os << w.product;
	os << "Quantity currently in store " << w.quantity << std::endl;
	return os;								 
}

template <typename T>
std::ofstream& operator << ( std::ofstream& fout, const Warehouse < T > & w )
{
	fout << "W" << std::endl;
	fout << w.product;
	fout << dynamic_cast <const Building&> (w);
	fout << w.rate << std::endl;
	fout << w.quantity << std::endl;
	return fout;
}

template <typename T>
std::istream& operator >> ( std::istream& is, Warehouse < T > & w )
{
	return is;
}

template <typename T>
std::ifstream& operator >> ( std::ifstream& fin, Warehouse < T > & w )
{
	fin >> w.product;
	fin >> dynamic_cast <Building&> (w);
	fin >> w.quantity;
	fin.ignore(10000, '\n');
	
	return fin;
}