//header guard

#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstring>
#include <map>
#include "item.h"
#include <vector>

using namespace std;

/* woohoo! you've made it. i am still the same person. this file intializes all the needed functions for room.cpp to work

   functions of interest: moving between rooms, adding items to rooms, dropping items in different rooms
*/



class room{
public:
  room();
  room(char*description)
    void setExit(char* direction, room* neighbor)
    char* getShortDescription();

  map<char*,room*> getExit();
  int index;
  char* direction;
  room* neighbor;
  char* itemName;

  void removeItem(char* itemName);
  item* newItem;
  void setItem(item* newitem);
  void printItem();
  vector<item*> items;
  map<char*, room*> exits;
  char* description;
  void getExitString();
  int noItems();
  char* itemDescription;
  item* matchItem(char*itemDescription;
};


#endif




