#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

/*

  Hopefully, you know who I am. I don't feel like labeling every file with my name so we'll just keep things mysterious and nonchalant.
  This is the item.cpp file, which primarily deals with setting items, returning their descriptions, etc..

 */


//default constructor for the item class
item::item(){

}


//initalizes the item with a description
item::item(char* newdescription){
  description=newdescription;
}

//to retrieve the description of the item
char* item::getItemDescription(){
  return description;
}
