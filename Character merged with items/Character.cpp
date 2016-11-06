
#include "Character.h"
#include <cmath>
#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>



using namespace std;


//! ok so in this file you have the method defintions for character and fighter which inherits from character
 



Fighter::Fighter() {  //! default construtor
}

Character::Character() { //! default constutor
}


//! Constructor: passes values to each ability score and set hit points to 10
Character::Character(int str, int dex, int con, int intel, int wis, int cha)
{

	this->equipment = new ItemContainer(); //! this stores equipped items
	this->backpack = new ItemContainer();  //! this is your backpack 
	
	modifers[0] = modifier(str);
	modifers[1] = modifier(dex);
	modifers[2] = modifier(con);
	modifers[3] = modifier(intel);
	modifers[4] = modifier(wis);
	modifers[5] = modifier(cha);


	abilityScores[0] = str ,abilityScoresFromChar[0] = str; 
	abilityScores[1] =dex ,abilityScoresFromChar[1] = dex;
	abilityScores[2] = con ,abilityScoresFromChar[2] = con;
	abilityScores[3] = intel,abilityScoresFromChar[3] = intel;
	abilityScores[4] = wis ,abilityScoresFromChar[4] = wis;
	abilityScores[5] =cha ,abilityScoresFromChar[5] = cha;

	//! and set hit points to 10 and multyping it by consitution level, as consitution level influnces hitpoints and by lvl

	currentHitPoints = 10 + abilityScores[2];
	armorclass, ArmorfromChar = 10+ modifers[1];
	attackbonus, attackbonusFromChar = (modifers[0] + modifers[1])*lvl;
	damagebonus = modifers[0];


}


//! this method is when you wish to level up the character and it scales the abilties appropiatly. 
void Character::levelUp() {  
	this->lvl++;
	for (int i = 0; i < 5; i++) {
		abilityScores[i] = abilityScores[i] * lvl;

	}
	this->currentHitPoints *=lvl;

}

//!according to rules modifier is (ability score -10) /2
int Character::modifier(int abilityscore) { 
	int modi = floor((abilityscore - 10) / 2);
	if (modi <= 0) {
		return 0;
	}
	return modi;
}


//! Implementation of the verification of a newly created Character
//! @return bool value, true of the character is valid (stats should be in the 3-18 range for a new character), false if invalid. 
bool Character::validateNewCharacter()
{
	for (int i = 0; i <= 5; i++)
		if (abilityScores[i]<3 || abilityScores[i]>18)
			return false;
	return true;
}

//! Implementation of fill cell, set any cell to anything it might eventually contain
//! @param damage: damage sustained by the character
void Character::hit(int damage)
{
	currentHitPoints = currentHitPoints - damage;  // this forumla will probaly change in next assigment due to adding mitigation from amor class
	Notify();
}

//! Implementation of a getter method for currentHitPoints
//! @return int: value of currentHitPoints
int Character::getHitPoints()
{
	return currentHitPoints;
}
//! ok this is how you will create a fighter class and a figher , for now its the same as character but in the project when its integrated more with games there will be some special perks to being a fighter
Fighter::Fighter(int str, int dex, int con, int intel, int wis, int cha) : Character(str, dex ,con, intel, wis, cha)

{ 

}

//! this displays the ability scores
void Character::showAbilityScores() {
	for (int i = 0; i < 6; i++) {
		cout << abilityScores[i] << endl;

	}
}
//! this returns the strengh , used for testing mostly
int Character::getStrength() {
	return abilityScores[0];
}

int Character::getDexterity() {
	return abilityScores[1];
}

int Character::getConstitution() {
	return abilityScores[2];
}

int Character::getIntelegence() {
	return abilityScores[3];

}

int Character::getWisdom() {
	return abilityScores[4];
}

int Character::getCharisma() {
	return abilityScores[5];
}


void Character::addItemBackpack(Item i){
	vector<Item> test = vector<Item>();
	test = backpack->getItems();

	if (test.size() < 20) {
		backpack->addItem(i);
	}
	else {
		cout << "your bag is full" << endl;
	}

}

void Character::removeItemfromBackpack(string name) { //! you receive name of item and remove it

	backpack->deleteItem(name);


}

void Character::equipItem(Item i) {
	vector<Item> test = vector<Item>();
	test = equipment->getItems();
	
	bool has = false;
	

	for (int z = 0; z < test.size(); z++) {
	
		//if (test.at(z).getType() == i.getType()) {
		if(test[z].getType()==i.getType()) {
		cout << "You arleady have an item of that type equipped, de-equip item type of interest first" << endl;
			has = true;
	  }
	}

	if (!has) {
		equipment->addItem(i); 
	}
	
	updatestats();
}


void Character::deEquipItem(string typeofItem) {  //! to dequip an item off a character you will pass its type; since you are holding only one of a "shield" for example.


	equipment->deleteItemByType(typeofItem);

	
	updatestats();

}






void Character::updatestats() {
	vector<Item> test = vector<Item>();
	test = equipment->getItems();
	currentHitPoints -= abilityScoresFromItems[2];
	for (int i = 0; i < 6; i++) {   // reseting bounuses
		abilityScoresFromItems[i] = 0;
	}

	for (int i = 0; i < test.size(); i++) {  //! adding bounuses from items
		vector<Enhancement> influence = vector<Enhancement>();
		
		
		influence = test[i].getInfluences();
		for (int z = 0;  z < influence.size(); z++) {
			
			if(influence[i].getType()=="str"){  
			
				abilityScoresFromItems[0] += influence[i].getBonus();
			}
		
			if (influence[i].getType() == "str") {

				abilityScoresFromItems[0] += influence[i].getBonus();
			}
			if (influence[i].getType() == "dex") {

				abilityScoresFromItems[1] += influence[i].getBonus();
			}
			if (influence[i].getType() == "con") {

				abilityScoresFromItems[2] += influence[i].getBonus();
			}
			if (influence[i].getType() == "intel") {

				abilityScoresFromItems[3] += influence[i].getBonus();
			}
			if (influence[i].getType() == "wis") {

				abilityScoresFromItems[4] += influence[i].getBonus();
			}

			if (influence[i].getType() == "cha") {

				abilityScoresFromItems[5] += influence[i].getBonus();
			}

			if (influence[i].getType() == "armor") {

				ArmorFromItems += influence[i].getBonus();
			}
			if (influence[i].getType() == "attackbonus") {

				attackbounusFromItems += influence[i].getBonus();
				}
			}
	
		}

	for (int i = 0; i < 6; i++) {   // tallying up bonus
		abilityScores[i] = abilityScoresFromChar[i] + abilityScoresFromItems[i];
	}
		armorclass = ArmorfromChar + ArmorFromItems+ modifers[1];
		attackbonus = attackbonusFromChar + attackbounusFromItems+ (modifers[0] + modifers[1])*lvl;
		currentHitPoints += abilityScoresFromItems[2];
		
		
		Notify();


}