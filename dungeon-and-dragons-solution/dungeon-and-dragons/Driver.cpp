#include <string>
#include "Character/CharacterGenerator.h"
#include "Map/Map.h"
#include "Global.h"
#include "Character/AggressorStrategy.h"
#include "Character/FriendlyStrategy.h"
#include "Character/HumanPlayerStrategy.h"

#include <iostream>
using namespace std;

int main() {

	//CharacterGenerator selectHero;
	////prompt player config
	//cout << endl << "Enter type of fighter (Bully, Tank, or Nimble) you wish you use: " << endl;
	//string fighterType1;
	//cin >> fighterType1;
	//cout << endl << "Enter the level of the character: " << endl;
	//int level1;
	//cin >> level1;
	//CharacterBuilder* playerBuilder = new PlayerCharacterBuilder(fighterType1, level1);
	////prompt enermy config
	//cout << endl << "Enter type of fighter (Bully, Tank, or Nimble) you wish your enermy to be: " << endl;
	//string fighterType2;
	//cin >> fighterType2;
	//cout << endl << "Enter the level of the character: " << endl;
	//int level2;
	//cin >> level2;
	//CharacterBuilder* enermyBuilder = new EnermyCharacterBuilder(fighterType2, level2);
	////config generator
	//selectHero.setCharacterBuilder(playerBuilder);
	//selectHero.createCharacter();
	//Character *player = selectHero.getCharacter();
	//selectHero.setCharacterBuilder(enermyBuilder);
	//selectHero.createCharacter();
	//Character *enermy = selectHero.getCharacter();
	////let's print!
	//srand(time(0));
	//cout << "Ok, here is what you have:" << endl;
	//cout << "Your character is a " << fighterType1 << endl;
	//cout << "with following stats: " << endl;
	//cout << "int " << player->getCharacterAttr()->getIntelligence() << " - "
		//<< "wis " << player->getCharacterAttr()->getWisdom() << " - "
		//<< "str " << player->getCharacterAttr()->getStrength() << " - "
		//<< "con " << player->getCharacterAttr()->getConstitution() << " - "
		//<< "dex " << player->getCharacterAttr()->getDexterity() << " - "
		//<< "cha " << player->getCharacterAttr()->getCharisma() << " - "
		//<< endl << "Hit Point at +" << player->getHitPoint() << endl;
	//cout << "Bonus attack at: " << endl;
	//for (int j = 0; j < 4; j++) {
		//cout << "round " << j << ": attack bonus + " << player->getAttackBonus()[j] << endl;
	//}
	//player->levelUp();
	//cout << "Now let's level up. After level up you have " << player->getHitPoint() << " hit points." << endl;
	//cout << "Bonus attack at: " << endl;
	//for (int k = 0; k < 4; k++) {
		//cout << "round " << k << ": attack bonus + " << player->getAttackBonus()[k] << endl;
	//}
	//cout << "Your enermy character is a " << fighterType2 << endl;
	//cout << "with following stats: " << endl;
	//cout << "int " << enermy->getCharacterAttr()->getIntelligence() << " - "
		//<< "wis " << enermy->getCharacterAttr()->getWisdom() << " - "
		//<< "str " << enermy->getCharacterAttr()->getStrength() << " - "
		//<< "con " << enermy->getCharacterAttr()->getConstitution() << " - "
		//<< "dex " << enermy->getCharacterAttr()->getDexterity() << " - "
		//<< "cha " << enermy->getCharacterAttr()->getCharisma() << " - "
		//<< endl << "Hit Point at +" << enermy->getHitPoint() << endl;
	//cout << "Bonus attack at: " << endl;
	//for (int j = 0; j < 4; j++) {
		//cout << "round " << j << ": attack bonus + " << enermy->getAttackBonus()[j] << endl;
	//}
	//enermy->levelUp();
	//cout << "Now let's level up. After level up you have " << enermy->getHitPoint() << " hit points." << endl;
	//cout << "Bonus attack at: " << endl;
	//for (int k = 0; k < 4; k++) {
		//cout << "round " << k << ": attack bonus + " << enermy->getAttackBonus()[k] << endl;
	//}
	////attack
	//cout << "you have hitpoint " << player->getHitPoint() << endl;
	//cout << "enermy has hitpoint " << enermy->getHitPoint() << endl;
	//cout << "you attack!" << endl;
	//player->attack(enermy);
	//cout << "you have hitpoint " << player->getHitPoint() << endl;
	//cout << "enermy has hitpoint " << enermy->getHitPoint() << endl;
	////prompt close console
	//int i = 1;
	//while (i == 1) {
		//cout << endl << "Enter 0 to quit the program." << endl;
		//cin >> i;
	//}
        //
        //




  cout << "You are an adventurer 'S' on the map along with a friendly character 'C'." << endl;
  cout << "Watch out, if you attack other characters, they might get angry and become aggresive ('O')..." << endl;

  // Hardcoding a basic map
  CharacterGenerator selectHero;
  Map m(5,5,"S                C     O");
  m.display();

  // Initializing all characters on the map
  vector<tuple<char,int,int>> characterPositions = m.getAllCharacterPositions();

  for (int i = 0; i < (int)characterPositions.size(); i++) {
    // Create a new one with appropriate position and type
    char type; int posX; int posY;
    tie(type, posX, posY) = characterPositions[i];
    if (type == 'S') {
      cout << "There is a human character at position ("<< posX << ","<< posY <<")" << endl;
      CharacterBuilder* playerBuilder = new PlayerCharacterBuilder("Bully", 2);
      selectHero.setCharacterBuilder(playerBuilder);
      selectHero.createCharacter();
      Character *player = selectHero.getCharacter();
      vector<int> currentPosition = {posX,posY};
      player->setCurrentPosition(currentPosition);
      Global::gameCharacters.push_back(player);
    }
    if (type == 'C') {
      cout << "There is a friendly character at position ("<< posX << ","<< posY <<")" << endl;
      CharacterBuilder* friendlyBuilder = new FriendlyCharacterBuilder("Tank", 4);
      selectHero.setCharacterBuilder(friendlyBuilder);
      selectHero.createCharacter();
      Character *friendly = selectHero.getCharacter();
      vector<int> currentPosition = {posX,posY};
      friendly->setCurrentPosition(currentPosition);
      Global::gameCharacters.push_back(friendly);
    }
    if (type == 'O') {
      cout << "There is an aggressor character at position ("<< posX << ","<< posY <<")" << endl;
      CharacterBuilder* enermyBuilder = new EnermyCharacterBuilder("Nimble", 3);
      selectHero.setCharacterBuilder(enermyBuilder);
      selectHero.createCharacter();
      Character *enermy = selectHero.getCharacter();
      vector<int> currentPosition = {posX,posY};
      enermy->setCurrentPosition(currentPosition);
      Global::gameCharacters.push_back(enermy);
    }
  }
  cout << endl;

  while (true) {
    for (int i = 0; i < (int)Global::gameCharacters.size(); i++) {
      Global::gameCharacters[i]->executeStrategy(m);
    }
  }


  return 0;
}
