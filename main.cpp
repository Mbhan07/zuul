#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;

/* This is the main class for Zuul, a text-based adventure game. The goal is to tavel through rooms and pick up items, eventually picking up a key and making our way out. My game is inspired on fast food locations as I am really hungry right now.

   By: Mahika Bhan
   11 / 14 / 2024

   ( ͡👁️ ͜ʖ ͡👁️)
   ( ͡👁️ ͜ʖ ͡👁️)
   ¯\_( ͡❛ ͜ʖ ͡❛)_/¯ ¯\_( ͡❛ ͜ʖ ͡❛)_/¯ ¯\_( ͡❛ ͜ʖ ͡❛)_/¯ ¯\_( ͡❛ ͜ʖ ͡❛)_/¯ ¯\_( ͡❛ ͜ʖ ͡❛)_/¯
   ツ유유유유유유유유유유유유유유유유유유유유유유유유유유유유유유유유유유유유유
   💰💣✈ ☮✞✞🚑
*/

int main(){
  // i will need three vectors: one for the room, one for the items, and one for the user's inventory

  // it shoulook something like this, warranted that i create rooms.cpp, rooms.h, items.cpp, item.h, inventory.cpp, and inentory.h files 
  vector <room*> rooms;
  vector <item*> items;
  vector <inventory*> currentInventory;
  map <char*, room*> exits;
  room* currentRoom;
  char go[3] = "GO";
  char player_direction[100];

  //declearing the items

  item* springRoll = new item((char*)"Spring Roll");

  item* chickenWing = new item((char*)"Chicken Wing ");

  item* macAndCheese = new item((char*)"Macaroni and Cheese");

  item* potStickers = new item((char*)"Potstickers ");

  item* garlicParm = new item((char*)"Garlic Parmesean Twists ");

  item* cheeseCake = new item((char*)"Cheesecake");

  //declaring the rooms

  room* ChickFilA = new room((char*) "You are in the Chick Fil-A");

  room* PandaExpress = new room((char*) "You are in the Panda Express");

  room* Wingstop = new room((char*) "You are in the Wingstop");

  room* Denny = new room((char*) "You are in the Denny's");

  room* Doughzone = new room((char*) "You are in the Dough Zone");

  room* Domino = new room((char*) "You are in the Domino's");

  room* Baskin = new room((char*) "You are in the Baskin Robbins");

  room* PF = new room((char*) "You are in the PF Chang's");

  room* Crumbl = new room((char*) "You are in the Crumbl Cookie");

  room* Burger = new room((char*) "You are in the Burger King");

  room* Cheesecake = new room((char*) "You are in the Cheesecake Factory");

  room* Grassa = new room((char*) "You are in the Grassa");

  room* Peleton = new room((char*) "You are in the Peleton.");

  room* KBBQ = new room((char*) "You are in the KBBQ");

  room* HotPot = new room((char*) "You are in the Hot Pot Spot");

  room* front=new room((char*)"You are the main entrance of Washington Square Mall");


  //setting the exits for the rooms

  front->setExit((char*)"north", Burger);
  front->setExit((char*)"west", ChickFilA);

  Burger->setExit((char*)"south", front);
  Burger->setExit((char*)"north", Peleton);

  ChickFilA->setExit((char*)"east", front);

  Peleton->setExit((char*)"south", Burger);
  Peleton->setExit((char*)"east", Crumbl);
  Peleton->setExit((char*)"west", Wingstop);
  Peleton->setExit((char*)"north", Doughzone);

  Crumbl->setExit((char*)"west", Peleton);
  Crumbl->setExit((char*)"north", Baskin);

  Wingstop->setExit((char*)"east", Peleton);
  Wingstop->setExit((char*)"south", Domino);

  Doughzone->setExit((char*)"south", Peleton);
  Doughzone->setExit((char*)"west", Denny);

  Denny->setExit((char*)"east", Doughzone);
  Denny->setExit((char*)"north", Grassa);

  Grassa->setExit((char*)"south", Denny);

  Domino->setExit((char*)"north", Wingstop);
  Domino->setExit((char*)"west", PF);
  Domino->setExit((char*)"south", PandaExpress);

  PF->setExit((char*)"east", Domino);

  PandaExpress->setExit((char*)"north", Domino);

  Baskin->setExit((char*)"south", Crumbl);
  Baskin->setExit((char*)"north", Cheesecake);

  Cheesecake->setExit((char*)"south", Baskin);
  Cheesecake->setExit((char*)"north", HotPot);
  Cheesecake->setExit((char*)"west", KBBQ);

  KBBQ->setExit((char*)"east", Cheesecake);
  HotPot->setExit((char*)"south", Cheesecake);


  //placing the items in the room:
  ChickFilA->setItem(macAndCheese);
  Wingstop->setItem(chickenWing);
  Domino->setItem(garlicParm);
  Doughzone->setItem(potStickers);
  Cheesecake->setItem(cheeseCake);
  PandaExpress->setItem(springRoll);
  
  //we want our default to be the front of washington square
  currentRoom = front;

  //win condition: inventory contains all six items
  while(true){
    if(currentInventory.size()==6){
      cout << "You win!";
      exit(0);
    }

    char out[200];
    strcpy(out,currentRoom->getShortDescription());
    cout << out << endl;
    currentRoom->printItem();
    cout << "What would you like to do: GO,GET,DROP,INVENTORY,QUIT, or HELP?" << endl;

    cin >> player_direction;
    cin.ignore();
    if(strcmp(player_direction, "GO") == 0){
      goToPlace(rooms, exits, currentRoom);
    }else if(strcmp(player_direction, "GET") == 0){
      getItem(items, currentInventory, currentRoom);
    }else if(strcmp(player_direction, "QUIT") == 0){
      cout << "Goodbye!" << endl;
      exit(0);
    }else if(strcmp(player_direction, "INVENTORY") == 0){
      printInventory(currentItems, currentRoom);
    }else if(strcmp(player_direction, "HELP") == 0){
      cout << endl;
      cout << "GO allows you to move to a different room." << endl;
      cout << "GET allows you to pick up items" << endl;
      cout << "DROP allows you to drop an item" << endl;
      cout << "QUIT allows you to stop the game" << endl;
      cout << "INVENTORY allows you to see all the items you currently have" << endl;
      cout << "HELP allows you to see all the possible commands" << endl;
      cout << "PLEASE MAKE SURE TO TYPE THE COMMANDS IN ALL CAPS!" << endl;
      cout << endl;
    }else if(strcmp(player_direction, "DROP") == 0){
      dropItem(items, currentInventory, currentRoom);
    }else {

      ; // loops back if something funky is entered
    }

    


}
  
  
  cout << "Welcome to Zuul!" <<endl;
  cout << endl;
  cout << "Currently, you are in the middle of Washington Square Mall." << endl;\
  cout << endl;
  cout << "Your objective is to pick up your dinner and make a quick exit to go eat it while it is still warm." << endl;
  cout << endl;
  cout << "Good luck!" << endl;
  cout << endl;
  return 0;

}


