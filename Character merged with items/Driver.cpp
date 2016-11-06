#include "Character.h"
#include "PseudoView.h"
#include "Item.h"
#include "Enhancement.h"
#include "ItemContainer.h"
#include <iostream>
#include <cmath>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */



//! further to this, the main is in this cpp file. There are two mains and one is always commented out. One is to show that a character is created blah blah blah
//! the other is for testing. if you want to switch from character display to testing just comment out one main and run the program with the other.


using namespace std;


int main(void) 
{

	srand(time(0)); //! this is used for randomizing our inputs
	cout << "HI HOPE U ARE DOING SWELL TODAY GOOD SIR, WELCOME TO CHARACTER CREATION OF DUNGEONS AND DRAGONS COMP345 VERSION, GET READY TO HAVE FUN FUN FUN! " << endl;
	//Fighter fight;
	cout << "We will now generate a character of class fighter with random ability score inputs" << endl;
	int values[6]; //! put random values in here than put values in constructor of fighter.

	for (int i = 0; i < 6; i++) {
		int max = 10;
		int min = 3;
		int randNum = rand() % (max - min + 1) + min;
		values[i] = randNum;

	}
	srand(time(0));

	Fighter * fight = new Fighter(values[0], values[1], values[2], values[3], values[4], values[5]);


	//Fighter fight = Fighter(10, 10, 10, 10, 10, 10);
	cout << "the hit points is " << fight->getHitPoints() << endl;
	cout << "the respective ability scores are " << endl;
	fight->showAbilityScores();

	
	

	PseudoView *Pseudoview = new PseudoView(fight);
	Pseudoview->display();
	cout << " Ok the fighter will now take a hit damage 2 and the pseudo view will be notified and thus display the current hp value upon hp change. " << endl ;
	fight->hit(2);
	cout << " OK and now 3 damage; die you blasted warlock warlock!" << endl;

	fight->hit(3);


	Enhancement enc = Enhancement("con", 3);
	
	//system("pause");
	Item i =  Item("belt",enc,"protobelt");
	
	system("pause");
	cout << "equiping item that adds 3 to consitution" << endl;
	fight->equipItem(i);

	system("pause");
	cout << "removing item that had added 3 to consituion" << endl;
	fight->deEquipItem("belt");
	system("pause");
	return 0;

}


/*

int main(int argc, char* argv[])
{
// Get the top level suite from the registry
CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

// Adds the test to the list of test to run
CppUnit::TextUi::TestRunner runner;
runner.addTest(suite);

// Change the default outputter to a compiler error format outputter
runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(),
std::cerr));
// Run the tests.
bool wasSucessful = runner.run();

getchar();

// Return error code 1 if the one of test failed.
return wasSucessful ? 0 : 1;
}
*/