#include <iostream>
#include <cstring>
#include "room.h"

/* defines all the functions needed to manipulate rooms, such as creating rooms, managing their exits, and handling items in the room

 */
using namespace std;

//constructor
room::room(){


}

//initializes a room with a description
room::room(char* newdescription){
  description = newdescription;
}

//set an exit for the room by associating a direction with a neighboring room
void room:: setExit(char* newdirection, room* newneighbor){
  exits.insert(pair<char*, room*>(newdirection, newneighbor));
}

//returns the short description of the room, whatever that is
char* room::getShortDescription(){
  return description;
}

//prints the availible exits for the room to the console
void room::getExitString(){
  cout << "Exits: ";
  map <char*, room*>::iterator i;
  for (i = exits.begin(); i != exits.end(); ++i){
    cout << i-> first << ", ";
  }
  cout << endl;
}

//returns the map of exits for the room
map <char*, room*> room::getExit(){
  return exits;
}

//prints the items in the room
void room::printItem(){
  cout << "Items: " << endl;
  for (int i = 0; i < items.size();i++){
    char out[1000];
    strcpy(out, items[i] -> getItemDescription());
    cout << out << endl;
  }
}

//returns the number of items in the room
int room::noItems(){
  int length = items.size();
  return length;
}

//lookfor an item in the room which matches the description
item* room::matchItem(char* newdescription){
  for(int i = 0; i < items.size(); i++){
     char out[1000];
     strcpy(out, items[i] -> getItemDescription());
     if(strcmp(newdescription, out) == 0){
       return items[i];
     }else {
       ;
     }

  }
}

//removes an item from the room's "items" vector by matching its description
void room::removeItem(char*it){
  vector <item*>::iterator i;
  for(int i = 0;i < items.size(); i++){
    if(strcmp(it, items[i] -> getItemDescription()) == 0){
      items.erase(items.begin() + i);
    }
  }
  
}



