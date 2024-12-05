//header guard

#ifndef ITEM
#define ITEM

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

/*

  guess who! this is the header file for the item class, which declares all of the functions used in item.cpp

*/


//declaring the item class

class item{
  
 public:

  //default constructor
  item();

  //to store description of item as a "string"
  char* description;

  //to initialize the description
  item(char*description);

  //to retrieve item description
  char* getItemDescription();

};

//end of header guard
#endif
