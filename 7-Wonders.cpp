#include <iostream>
#include <string>
using namespace std;
// Clock
int clockDown = 154;
// Resources:
int gold;
int stone;
int wood;
int energy;
// Stats:
string charName;
int leadership;
int leaderMod = (leadership/1.5)*10;
int intelligence;
int intelMod = (intelligence/3)*10;
int cunning;
int cunningMod = (cunning/2)*10;
int endurance;
int enduranceMod = (endurance/4)*10;
// Wonders:
class Wonders {
    public:
    string name;
    int stoneCost;
    int woodCost;
};
// Characters:
class Characters {
    public:
    string name;
    int startLead;
    int startInt;
    int startCun;
    int startEnd;
    int startGold;
    int startStone;
    int startWood;
    int startEnergy;
};

void characterSelect(){
    string charNameInput;
    cout << "Select your character" << "\n";
    cin >> charNameInput;
    if (charNameInput == "Hadrian" || charNameInput == "hadrian"){
        hadrianStart();
    } else {
        cout << "Please put in the correct name"<< "\n";
        characterSelect();
    };
};

void hadrianStart(){
    Characters Hadrian;
        Hadrian.name = "Hadrian";
        Hadrian.startLead = 20;
        Hadrian.startInt = 10;
        Hadrian.startCun = 5;
        Hadrian.startEnd = 10;
        Hadrian.startGold = 300;
        Hadrian.startStone = 300;
        Hadrian.startWood = 100;
        Hadrian.startEnergy = 10;
    charName = Hadrian.name;
    leadership = Hadrian.startLead;
    intelligence = Hadrian.startInt;
    cunning = Hadrian.startCun;
    endurance = Hadrian.startEnd;
    gold = Hadrian.startGold;
    stone = Hadrian.startStone;
    wood = Hadrian.startWood;
    energy = Hadrian.startEnergy;
    //Later we want energy to be calculated off the endurance stat
    cout << "Ave imperator Emperor Hadrian! Welcome to 7 Wonders!"<<"\n";
    startScreen();
};
void startScreen(){
  
       
        cout << charName << "\n" << "\n";
        cout << "Resources:   " << "Stats:" << "\n";
        cout << "Gold:" << gold << " Leadership:" << leadership << "\n";
        cout << "Stone:" << stone << " Intelligence:" << intelligence << "\n";
        cout << "Wood:" << wood << " Cunning:" << cunning << "\n";
        cout << "Energy:" << energy << " Endurance:" << endurance << "\n";
        questionsFunc();
    };
//Questions
class Questions {
    public:
    string questionText;
    void resourceUp(int source, int Inc, int Mod){
        source + Inc + Mod;
    };
    void resourceDown(int source, int Dec){
        source - Dec;
    }
    void statUp(int source, int Inc){
        source + Inc;
    }
    void statDown(int source, int Dec){
        source - Dec;
    }
};
void questionsFunc(){ 
    char answerVar;
        Questions questZero;
            questZero.questionText = "Spend 20 stone to get 50 gold?";
            questZero.resourceUp(gold, 50, cunningMod);
            questZero.resourceDown(stone, 20);
            // questZero.statUp(0, 0);
            // questZero.statDown(0, 0);
        Questions questOne;
            questOne.questionText = "Spend 10 energy to mine 100 stone?";
            questOne.resourceUp(stone, 100, leaderMod);
            questOne.resourceDown(energy, 10);
            // questOne.statUp(0, 0);
            // questOne.statDown(0, 0);
        Questions questTwo;
            questTwo.questionText = "Spend 10 energy to harvest 100 wood?";
            questTwo.resourceUp(wood, 100, intelMod);
            questTwo.resourceDown(energy, 10);
            // questTwo.statUp(0, 0);
            // questTwo.statDown(0, 0);
        Questions questThree;
            questThree.questionText = "Spend 120 gold to get 200 wood?";
            questThree.resourceUp(wood, 200, intelMod);
            questThree.resourceDown(gold, 120);
            // questThree.statUp(0, 0);
            // questThree.statDown(0, 0);
        Questions questFour;
            questFour.questionText = "Sacrifice 10 leadership for 300 gold?";
            questFour.resourceUp(gold, 300, cunningMod);
            // questFour.resourceDown(0,0);
            // questFour.statUp(0,0);
            questFour.statDown(leadership, 10);
        Questions questFive;
            questFive.questionText ="Spend 100 gold for 5 energy?";
            questFive.resourceUp(energy, 5, enduranceMod);
            questFive.resourceDown(gold, 100);
            // questFive.statUp(0, 0);
            // questFive.statDown(0, 0);
        Questions questSix;
            questSix.questionText ="Would you like to buy a 15 cunning boost for 500 gold?";
            // questSix.resourceUp(0,0,0);
            questSix.resourceDown(gold, 500);
            questSix.statUp(cunning,15);
            // questSix.statDown(0,0);


    Questions qArray[7] = {
        questZero,
        questOne,
        questTwo,
        questThree,
        questFour,
        questFive,
        questSix
    };

        Wonders pyramids;
            pyramids.name = "Pyramids";
            pyramids.stoneCost = 800;
            pyramids.woodCost = 800;

//Randomizer

    int randomNum1 = rand()%7-1;
    int randomNum2 = rand()%7-1;
    if (randomNum2 == randomNum1 && randomNum2 !=0) {
        randomNum2-1;
    } else if (randomNum2 == randomNum1 && randomNum2 !=6) {
        randomNum2+1;
    }
    int randomNum3 = rand()%7-1;
    if (randomNum3 == randomNum1 || randomNum3 == randomNum2 && randomNum3>=2){
        randomNum3-2;
    } else if (randomNum3 == randomNum1 || randomNum3 == randomNum2 && randomNum3<=4){
        randomNum3+2;
    }


    cout << "A. " << qArray[randomNum1].questionText << "\n";
    cout << "B. " << qArray[randomNum2].questionText << "\n";
    cout << "C. " << qArray[randomNum3].questionText << "\n";
    cout << "D. " << pyramids.name << " Stone:" << pyramids.stoneCost << " Wood:" << pyramids.woodCost << "\n";
    cout <<"Please input the associated letter with your answer."<<"\n";
        cin >> answerVar;
        if (answerVar == 'A' || answerVar == 'a') {
            if (randomNum1 == 0){
                questZero.resourceUp(gold, 50, cunningMod);
                questZero.resourceDown(stone, 20);
            } else if ( randomNum1 == 1) {
                questOne.resourceUp(stone, 100, leaderMod);
                questOne.resourceDown(energy, 10);
            } else if ( randomNum1 == 2) {
                questTwo.resourceUp(wood, 100, intelMod);
                questTwo.resourceDown(energy, 10);
            } else if ( randomNum1 == 3) {
                questThree.resourceUp(wood, 200, intelMod);
                questThree.resourceDown(gold, 120);
            } else if ( randomNum1 == 4) {
                questFour.resourceUp(gold, 300, cunningMod);
                questFour.statDown(leadership, 10);
            } else if ( randomNum1 == 5) {
                questFive.resourceUp(energy, 5, enduranceMod);
                questFive.resourceDown(gold, 100);
            } else if ( randomNum1 == 6) {
                questSix.resourceDown(gold, 500);
                questSix.statUp(cunning,15);
            }
        } else if ( answerVar == 'B' || answerVar == 'b') {
            if (randomNum2 == 0){
                questZero.resourceUp(gold, 50, cunningMod);
                questZero.resourceDown(stone, 20);
            } else if ( randomNum2 == 1) {
                questOne.resourceUp(stone, 100, leaderMod);
                questOne.resourceDown(energy, 10);
            } else if ( randomNum2 == 2) {
                questTwo.resourceUp(wood, 100, intelMod);
                questTwo.resourceDown(energy, 10);
            } else if ( randomNum2 == 3) {
                questThree.resourceUp(wood, 200, intelMod);
                questThree.resourceDown(gold, 120);
            } else if ( randomNum2 == 4) {
                questFour.resourceUp(gold, 300, cunningMod);
                questFour.statDown(leadership, 10);
            } else if ( randomNum2 == 5) {
                questFive.resourceUp(energy, 5, enduranceMod);
                questFive.resourceDown(gold, 100);
            } else if ( randomNum2 == 6) {
                questSix.resourceDown(gold, 500);
                questSix.statUp(cunning,15);
            }
        } else if ( answerVar == 'C' || answerVar == 'c') {
            if (randomNum3 == 0){
                questZero.resourceUp(gold, 50, cunningMod);
                questZero.resourceDown(stone, 20);
            } else if ( randomNum3 == 1) {
                questOne.resourceUp(stone, 100, leaderMod);
                questOne.resourceDown(energy, 10);
            } else if ( randomNum3 == 2) {
                questTwo.resourceUp(wood, 100, intelMod);
                questTwo.resourceDown(energy, 10);
            } else if ( randomNum3 == 3) {
                questThree.resourceUp(wood, 200, intelMod);
                questThree.resourceDown(gold, 120);
            } else if ( randomNum3 == 4) {
                questFour.resourceUp(gold, 300, cunningMod);
                questFour.statDown(leadership, 10);
            } else if ( randomNum3 == 5) {
                questFive.resourceUp(energy, 5, enduranceMod);
                questFive.resourceDown(gold, 100);
            } else if ( randomNum3 == 6) {
                questSix.resourceDown(gold, 500);
                questSix.statUp(cunning,15);
            }
        } else if ( answerVar == 'D' || answerVar == 'd'){
            if (stone>=pyramids.stoneCost && wood>=pyramids.woodCost){
                cout << "You have constructed the mighty Pyramids! Look upon your works with pride, for you are a lion amongst sheep!" << "\n";
                cout << "Press enter to end game"<< "\n";
                cin.ignore();
            } else {
                cout << "You lack the necessary resources. Pick a different choice."<< "\n";
                cin.clear();
            }
        } else {
            cout << "Invalid input. Please enter a valid answer."<< "\n";
            cin.clear();
        }
        
        energy + endurance;

        clockDown - 7;
        if (clockDown > 0) {
            startScreen();
        } else {
            cout << "Game Over" << "\n";
        }
        
};

int main(){
    characterSelect();
    return 0;
};