/*
 * File Name:    city.cpp
 *
 * Author:        Your Name
 * Creation Date: Tuesday, September 03 2019, 13:14 
 * Last Modified: Tuesday, September 24 2019, 16:36
 * 
 * File Description:
 *
 */
#include "city.h"


int main( )
{
   CITY city;

   init( city );

   run( city );

   std::cout << "That's all folks" << std::endl;
   return 0;
}

/*
 * This function is called to load the contents of the text
 * file into the vector.
 *
 * This function first asks the user for the name of an input
 * text file. If the file exists, it will not be empty and the
 * format of the file is guaranteed to be correct.
 *
 * If you are having trouble with this function, do choice 1,
 * add building (from the keyboard)
 *
 * If the input file requested by the user does not exist
 * or can't be opened, then the program does not exist,
 * it continues with nothing loaded into the vector
 *
 */
void init( CITY & city )
{
	std::string fileName {};
	std::cout << "Please enter input file name >> ";
	getline(std::cin, fileName);
	
	std::ifstream fin;
	fin.open(fileName);
	
	bool fileOpen { true };
	
	if(fin.fail())
	{
		std::cout << "\nUnable to open input file" << std::endl;
		fileOpen = false;
	}
	
	char type { 'z' };
	std::string product {};
	
	Building * bPtr;
	
	while(fileOpen && fin >> type)
	{
		fin.ignore(10000, '\n');
		if(type == 'W')
		{
			fin >> product;
			if(product == "P1")
			{
				bPtr = new Warehouse<Product_1>;
			} else if(product == "P2")
			{
				bPtr = new Warehouse<Product_2>;
			} else if(product == "P3")
			{
				bPtr = new Warehouse<Product_3>;
			}			
		} else if(type == 'R')
		{
			bPtr = new Residential;
			
		} else if(type == 'C')
		{
			bPtr = new Commercial;
			
		}
		bPtr->readFromFile(fin);
		city.push_back(bPtr);
	}
	
	fin.close();
	
}

/*
 * This function is fully implemented
 *
 */
void run( CITY & city )
{
   int choice { -1 };
   while( choice != static_cast< int > ( MAIN::EXIT ) )
   {
         displayMainMenu( );
         std::cout << "\tEnter choice >> ";
         std::cin >> choice;
         std::cin.ignore( 100000, '\n' );
         processMain( city, choice );
   }

}

/*
 * This function is fully implemented
 *
 */
void processMain( CITY & city, int choice )
{
    switch( static_cast< MAIN >( choice ) )
    {
         case MAIN::ADD_NEW :
              addBuilding( city );
            break;

         case MAIN::ADD_TO_BUILDING :
              addToBuilding( city );
            break;

         case MAIN::SAVE :
              save( city );
            break;

         case MAIN::DISPLAY :
            display_All( city );
            break;

         case MAIN::EXIT :
           // just trap this choice
           break;

        default:
              std::cout << "That is not a valid menu choice "
                        << std::endl;
    }
}

/*
 * This function is fully implemented
 *
 */
void displayMainMenu( )
{
    std::cout << std::endl << "\tCity Menu" << std::endl;
    std::cout << static_cast<int>(MAIN::ADD_NEW) 
              << ". Add Building" << std::endl;
    std::cout << static_cast<int>(MAIN::DISPLAY) 
              << ". Display" << std::endl;
    std::cout << static_cast<int>(MAIN::ADD_TO_BUILDING) 
              << ". Add to an existing Building" << std::endl;
    std::cout << static_cast<int>(MAIN::SAVE) 
              << ". Save the city to a file" << std::endl;
    std::cout << static_cast<int>(MAIN::EXIT) 
              << ". Close the program" << std::endl;
}

/*
 * This function is fully implemented
 *
 */
void addBuilding( CITY & city )
{
   int choice { -1 };
   while( choice != static_cast< int >( ADD_CHOICES::EXIT ) )
   {
      displayAddChoices( );
      std::cout << "Enter choice >> " ;
      std::cin >> choice;
      std::cin.ignore( 10000, '\n' );
      processAddBuilding( city, choice );
   }
}

/*
 * This is a case for using iterators, so that we can use this in
 * other searches.
 *
 * There are other ways of finding the address of a Building.
 *
 * We could have a function that just returns true or false
 * whether or not an address exists in the vector.
 *
 */
CITY::const_iterator findAddress( const CITY & city, const Address& a )
{
    // change this when you code this function
    // the return type is written this way just to get the program to
    // compile
	for (auto i = city.begin(); i != city.end(); i++)
	{
		if((**i).getAddress() == a)
		{
			return i;
		}
	}
	
    return city.end();

}

/*
 * This function is fully implemented
 *
 */
void displayAddChoices( )
{
   std::cout << "\nBuilding type add menu" << std::endl;
   std::cout << "   " << static_cast< int >( ADD_CHOICES::WAREHOUSE ) <<
   ". Add Warehouse " << std::endl;
   std::cout << "   " << static_cast< int >( ADD_CHOICES::COMMERCIAL ) <<
      ". Add Commercial " << std::endl;
   std::cout << "   " << static_cast< int >( ADD_CHOICES::RESIDENTIAL ) << 
      ". Add Residential" << std::endl;
   std::cout << "   " << static_cast< int >( ADD_CHOICES::EXIT ) <<
      ". Return to main menu" << std::endl;
}

/*
 * Since we are going to stay in the add Building menu until we
 * decide to return to the main menu, we must check the address
 * of every new Building, otherwise we could enter any number of 
 * Buildings all at the same address.
 *
 * One of the alternatives is not have a while loop in the process,
 * just show the menu once and regardless of whether the user 
 * enters an Address that is new or an Address that is already in use,
 * the menu returns to the main menu. That way the user has to call the
 * main menu choice to add a Building, which prompts for a new Address,
 * which is in turn checked before gathering the rest of the required
 * information.
 *
 */
/*
 * All three types of buildings depend on finding out if the
 * user entered Address is valid, that is, unique.
 *
 * For that reason we have chosen to put it in the top of this 
 * function. If the address is not unique, there is no point in
 * asking for any more information. If this Address is unique, then
 * we already have that piece of information, so pass it in to
 * the appropriate add function
 *
 */
void processAddBuilding( CITY & city, int choice )
{
   if( choice == static_cast< int > ( ADD_CHOICES::EXIT ))
   {
         return;
   }
    
    /*
     * Uncomment these lines of code when you have finished
     * the Address class
     *
     */
     std::cout << "Add new address " << std::endl;
     Address a;
     std::cin >> a;
    
    // We should use an Address object as all the attributes
    // of the Address object are involved in the search
    auto findIter = findAddress( city, a );
    
    if( findIter != city.end( ) )
    {
         std::cout << "\nThere is already a building at that address"
                  << std::endl;
         return;
    }


    /*
      After you have implemented the Address class then uncomment
      these lines of code
	*/
   switch( static_cast< ADD_CHOICES > ( choice )) 
   {
      case ADD_CHOICES::WAREHOUSE :
              addWarehouse( city, a );
         break;

      case ADD_CHOICES::COMMERCIAL : 
              addCommercial( city, a );
         break;

      case ADD_CHOICES::RESIDENTIAL :
              addResidential( city, a );
            break;

         case ADD_CHOICES::EXIT :
              // just trap this choice so that it doesn't show as
              // an invalid choice
              // This case should never be activated
            break;

         default :
              std::cout << "\nThat is not a valid add menu choice"
                        << std::endl;
            break;
           
    }
    
}

/*
 * This function gets the additional information required
 * to fully instantiate a Residential object.
 * We already have the address, for the Residential class
 * the only additional thing we need is the number of residents
 *
 * Once we have this, then we add the object to the vector
 *
 */
void addResidential( CITY & city, const Address & address )
{
	int numberOfPeople {0};
	std::cout << "Enter number of people in this building >> ";
	std::cin >> numberOfPeople;
	Residential *r = new Residential(address, numberOfPeople);
	city.push_back(r);
}

/*
 * This function gets the additional information needed for a
 * Commercial object, which is just the opening hour and the
 * closing hour. Then we add the object to the vector
 *
 */
void addCommercial( CITY & city, const Address & address )
{
	int openHour, closeHour;
	std::cout << "Enter open hour >> ";
	std::cin >> openHour;
	std::cout << "Enter close hour >> ";
	std::cin >> closeHour;
	Commercial *c = new Commercial(address, openHour, closeHour);
	city.push_back(c);
}

/*
 * Assume that the user always enters a correct number of the
 * product to be stored in the Warehouse.
 *
 * We need to know which actual Product object we're 
 * adding to the Warehouse object before we add the Warehouse
 * object to the vector
 *
 */
void addWarehouse( CITY & city, const Address & address )
{
    std::cout << "Product Menu" << std::endl;
    std::cout << "1. Product 1" << std::endl;
    std::cout << "2. Product 2" << std::endl;
    std::cout << "3. Product 3" << std::endl;
    std::cout << "Enter Product choice >> ";
    int choice { 0 };
    std::cin >> choice;

    int quantity { 0 };
    std::cout << "Enter quantity >> " ;
    std::cin >> quantity;
    std::cin.ignore( 10000, '\n' );
    // A switch statement would work just as well here
    if( choice == 1 )
    {
         Product_1 p;
         addToWarehouse( city, address, quantity, p);        
    }
    else if( choice == 2 )
    {
         Product_2 p;
         addToWarehouse( city, address, quantity, p);        
    }
    else if( choice == 3 )
    {
         Product_3 p;
         addToWarehouse( city, address, quantity, p);        
    }
    else
    {
         std::cout << "\nThat is not a valid choice" << std::endl;
    }
}

/*
 * This function actually adds the Warehouse object to the vector.
 * First we need to enter the information for the Product from the
 * keyboard. We already know which object from the calling
 * function
 *
 * At every point that we are discussing an object to the 
 * vector, of course, we are talking about adding a pointer
 * to the object to the vector. So we instantiate objects 
 * using new and store their pointer addresses in the vector
 * as the vector is a vector of Building pointers
 *
 */

template <typename T>
void addToWarehouse( CITY & city, const Address & address, int quantity,
                     T product )
{
	std::cin >> product;
	Warehouse<T> *w = new Warehouse<T>(address, product, quantity);
	city.push_back(w);
}

/*
 * This function displays the contents of the vector to the screen
 *
 */
void display_All( const CITY& city )
{
   std::cout << "Display all" << std::endl;
   for(auto fPtr : city)
   {
	   fPtr->display();
	   std::cout << "" << std::endl;
   }
}

/*
 * This function saves the contents of the vector to an output
 * text file. Be very careful to write the contents, including the
 * identifiers, back to the file in the format as detailed on
 * pages 11 - 13 of the assignment
 *
 * This function first prompts( asks ) the user for the name of
 * an output text file.
 *
 */
void save( const CITY& city )
{
   std::ofstream output;
   std::string filename;
   std::cout << "Enter output file name: ";
   std::cin >> filename;
   output.open(filename.c_str());
   
   for(auto fPtr : city)
   {
	   fPtr->saveToFile(output);
   }
   output.close();
}

/*
 * This function first asks the user for an address
 * If the address entered exists in the vector
 * then the user is prompted (asked) to edit one or more
 * of the attributes of that particular object.
 *
 * If the object is a Residential object, then the edit will be
 * the number of residents
 *
 * If the object is a Commercial object, then the edit will be
 * the opening and closing hours.
 *
 * If the object is a Warehouse object, then the edit will be the
 * quantity.
 *
 * Do not forget to recalculate the rate paid by that object, as
 * one or more of the attributes that contribute to the rate
 * have changed.
 *
 * You might use the searchAddress function that you wrote above,
 * or you might want to look up how the modern find_if STL function
 * works. This needs the std::bind STL function, the modern
 * version.
 *
 * Once we have an iterator "pointing" to the correct element,
 * all we need to do is call the overloaded add function
 *
 */
void addToBuilding( CITY & city )
{
     std::cout << "Enter an address " << std::endl;
     Address a;
     std::cin >> a;
	 
	 auto findIter = findAddress( city, a );
	 
	 int index = findIter - city.begin();
	  city.at(index)->add();
}

/*
 * this function just returns true or false if an object
 * with that address exists
 *
 * The return type is just listed as true, to get the
 * program to compile.
 *
 * It would be very helpful to have completed the overloaded
 * operator == in the Address class first
 *
 */
bool AddressFinder( Building * bPtr, Address  & address )
{
    return true;
}

