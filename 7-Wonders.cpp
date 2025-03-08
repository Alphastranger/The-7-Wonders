#include <iostream>
#include <string>
#include <map>
using namespace std;
// Clock
int clockDown = 154;
// Resources:
map<string, int> resources;
int gold;
int stone;
int wood;
int energy;
// Stats:
string charName;
map<string, int> statistics;
int leadership;
int leaderMod;
int intelligence;
int intelMod;
int cunning;
int cunningMod;
int endurance;
int enduranceMod;
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
    string Quest;
};
// Character Unique Questions
string uniqueQuest;
bool hadrianBool;
bool nefertitiBool;
// Function Declarations
void hadrianStart();
void nefertitiStart();
void startScreen();
void questionsFunc();

// Count Down
void clockTicker(){
        clockDown -= 7;
        if (clockDown > 0) {
            startScreen();
        } else {
            cout << "Game Over" << "\n";
        };
};

void characterSelect(){
    string charNameInput;
    cout << "-----7 WONDERS-----"<<"\n""\n";
    cout << "Select your character" << "\n";
    cout << "1. Hadrian" << "\n";
    cout << " A wise and steady emperor of Rome. Gifted in Leadership and stoneworking." << "\n";
    cout << "2. Nefertiti" << "\n";
    cout << " The wife of Akhenaten who famously pushed Egypt towards monotheism. Gifted in Cunning and tithes." << "\n";
    cout << "\n""\n";
    cin >> charNameInput;
    if (charNameInput == "Hadrian" || charNameInput == "hadrian"){
        hadrianStart();
    } else if (charNameInput == "Nefertiti" || charNameInput == "nefertiti") {
        nefertitiStart();
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
        Hadrian.startWood = 200;
        Hadrian.startEnergy = 10;
        Hadrian.Quest = "Erect a border wall, costing 50 stone and granting 20 energy?";
    charName = Hadrian.name;
    statistics["leadership"] = Hadrian.startLead;
    statistics["intelligence"] = Hadrian.startInt;
    statistics["cunning"] = Hadrian.startCun;
    statistics["endurance"] = Hadrian.startEnd;
    resources["gold"]= Hadrian.startGold;
    resources["stone"] = Hadrian.startStone;
    resources["wood"] = Hadrian.startWood;
    resources["energy"] = Hadrian.startEnergy;
    uniqueQuest = Hadrian.Quest;
    hadrianBool = true;
    //Later we want energy to be calculated off the endurance stat
    cout << "\n""Ave imperator Emperor Hadrian! Welcome to 7 Wonders!"<<"\n""\n";
    cout << "In this game, you must race to complete all seven world wonders before the time runs out!""\n";
    startScreen();
};

void nefertitiStart(){
    Characters Nefertiti;
        Nefertiti.name = "Nefertiti";
        Nefertiti.startLead = 5;
        Nefertiti.startInt = 15;
        Nefertiti.startCun = 25;
        Nefertiti.startEnd = 10;
        Nefertiti.startGold = 500;
        Nefertiti.startStone = 200;
        Nefertiti.startWood = 100;
        Nefertiti.startEnergy = 15;
        Nefertiti.Quest = "Celebrate Atun with merriment and excess, costing 10 energy and granting 200 gold?";
    charName = Nefertiti.name;
    statistics["leadership"] = Nefertiti.startLead;
    statistics["intelligence"] = Nefertiti.startInt;
    statistics["cunning"] = Nefertiti.startCun;
    statistics["endurance"] = Nefertiti.startEnd;
    resources["gold"]= Nefertiti.startGold;
    resources["stone"] = Nefertiti.startStone;
    resources["wood"] = Nefertiti.startWood;
    resources["energy"] = Nefertiti.startEnergy;
    uniqueQuest = Nefertiti.Quest;
    nefertitiBool = true;
    cout << "Blessings upon you great Queen of the Nile! Welcome to 7 Wonders!"<<"\n";
    cout << "In this game, you must race to complete all seven world wonders before the time runs out!";
    startScreen();
}
void startScreen(){
  leaderMod = (statistics["leadership"]/1.5)*10;
  intelMod = (statistics["intelligence"]/3)*10;
  cunningMod = (statistics["cunning"]/2)*10;
  enduranceMod = (statistics["endurance"]/4);
        cout << "\n" << charName << "    " << "Days Left: " << clockDown << "\n" << "\n";
        cout << "Resources:   " << "Stats:" << "\n";
        cout << "Gold:" << resources["gold"] << " Leadership:" << statistics["leadership"] << "\n";
        cout << "Stone:" << resources["stone"] << " Intelligence:" << statistics["intelligence"] << "\n";
        cout << "Wood:" << resources["wood"] << " Cunning:" << statistics["cunning"] << "\n";
        cout << "Energy:" << resources["energy"] << " Endurance:" << statistics["endurance"] << "\n";

        // cout << "leadMod" << leaderMod << "\n";
        // cout << "intelMod" << intelMod << "\n";
        // cout << "cunMod " << cunningMod << "\n";
        // cout << "endMod" << enduranceMod << "\n";
        questionsFunc();
    };
    
//Questions

void questionsFunc(){ 
    // Wonders
    Wonders pyramids;
            pyramids.name = "Pyramids";
            pyramids.stoneCost = 800;
            pyramids.woodCost = 800;

    // Questions
    class Questions {
    public:
    string questionText;
    void resourceUp(string source, int Inc, int Mod){
        int x = resources[source];
        int y = Inc;
        int z = Mod;
        // cout << "X Test" << x << "\n";
        // cout << "Y Test " << y << "\n";
        // cout << "Z test " << z << "\n";
        int sum = x + y + z;
        resources[source]=sum;
        // cout << "Test" << resources[source] << "\n";
    };
    void resourceDown(string source, int Dec){
        int x = resources[source];
        int y = Dec;
        int sum = x - y;
        if (sum<0) {
            cout << "\n""INVALID RESOURCES"<<"\n";
            clockTicker();
        } else {
        resources[source]=sum;
        }
    }
    void statUp(string source, int Inc){
        int x = statistics[source];
        int y = Inc;
        int sum = x + y;
        statistics[source]=sum;
    }
    void statDown(string source, int Dec){
        int x = statistics[source];
        int y = Dec;
        int sum = x - y;
        if (sum<0) {
            cout << "\n""INVALID STATS"<<"\n";
            clockTicker();
        }else {
        statistics [source]=sum;
        }
    }
};
    char answerVar;
        Questions questZero;
            questZero.questionText = "Spend 20 stone to get 50 gold?";
            // questZero.resourceUp("gold", 50, cunningMod);
            // questZero.resourceDown(stone, 20);
            // questZero.statUp(0, 0);
            // questZero.statDown(0, 0);
        Questions questOne;
            questOne.questionText = "Spend 10 energy to mine 100 stone?";
            // questOne.resourceUp("stone", 100, leaderMod);
            // questOne.resourceDown(energy, 10);
            // // questOne.statUp(0, 0);
            // // questOne.statDown(0, 0);
        Questions questTwo;
            questTwo.questionText = "Spend 10 energy to harvest 100 wood?";
            // questTwo.resourceUp("wood", 100, intelMod);
            // questTwo.resourceDown(energy, 10);
            // // questTwo.statUp(0, 0);
            // // questTwo.statDown(0, 0);
        Questions questThree;
            questThree.questionText = "Spend 120 gold to get 200 wood?";
            // questThree.resourceUp("wood", 200, intelMod);
            // questThree.resourceDown(gold, 120);
            // // questThree.statUp(0, 0);
            // // questThree.statDown(0, 0);
        Questions questFour;
            questFour.questionText = "Sacrifice 10 leadership for 300 gold?";
            // questFour.resourceUp("gold", 300, cunningMod);
            // // questFour.resourceDown(0,0);
            // // questFour.statUp(0,0);
            // questFour.statDown(leadership, 10);
        Questions questFive;
            questFive.questionText ="Spend 100 gold for 5 energy?";
            // questFive.resourceUp("energy", 5, enduranceMod);
            // questFive.resourceDown(gold, 100);
            // // questFive.statUp(0, 0);
            // // questFive.statDown(0, 0);
        Questions questSix;
            questSix.questionText ="Would you like to buy a 15 cunning boost for 500 gold?";
            // // questSix.resourceUp(0,0,0);
            // questSix.resourceDown(gold, 500);
            // questSix.statUp(cunning,15);
            // // questSix.statDown(0,0);


    Questions qArray[7] = {
        questZero,
        questOne,
        questTwo,
        questThree,
        questFour,
        questFive,
        questSix
    };

// Character Questions
    Questions questCharacter;
        questCharacter.questionText = uniqueQuest;

        

//Randomizer
    srand(time(0));
    int randomNum1 = rand()%7;
    int randomNum2 = rand()%7;
    int randomNum3 = rand()%7;
    if ((randomNum2 == randomNum1) || (randomNum2 == randomNum3) && randomNum2 >0) {
        randomNum2-1;
    } else if ((randomNum2 == randomNum1) || (randomNum2 == randomNum3) && randomNum2 <6) {
        randomNum2+1;
    }  
    if ((randomNum3 == randomNum1) || (randomNum3 == randomNum2) && randomNum3<0){
        randomNum3-1;
    } else if ((randomNum3 == randomNum1) || (randomNum3 == randomNum2) && randomNum3>6){
        randomNum3+1;
    }

// Outputs
    cout << "----------------------------------------------"<< "\n";
    cout << "A. " << qArray[randomNum1].questionText << "\n";
    cout << "----------------------------------------------"<< "\n";
    cout << "B. " << qArray[randomNum2].questionText << "\n";
    cout << "----------------------------------------------"<< "\n";
    cout << "C. " << qArray[randomNum3].questionText << "\n";
    cout << "----------------------------------------------"<< "\n";
    cout << "D. " << pyramids.name << " Stone:" << pyramids.stoneCost << " Wood:" << pyramids.woodCost << "\n";
    cout << "----------------------------------------------"<< "\n";
    cout << "E. " << uniqueQuest << "\n";
    cout << "----------------------------------------------"<< "\n";
    cout <<"Please input the associated letter with your answer."<<"\n";

    cin >> answerVar;

        if (answerVar == 'A' || answerVar == 'a') {
            if (randomNum1 == 0){
                questZero.resourceDown("stone", 20);
                questZero.resourceUp("gold", 50, cunningMod);
            } else if ( randomNum1 == 1) {
                questOne.resourceDown("energy", 10);
                questOne.resourceUp("stone", 100, leaderMod);
            } else if ( randomNum1 == 2) {
                questTwo.resourceDown("energy", 10);
                questTwo.resourceUp("wood", 100, intelMod);
            } else if ( randomNum1 == 3) {
                questThree.resourceDown("gold", 120);
                questThree.resourceUp("wood", 200, intelMod);
            } else if ( randomNum1 == 4) {
                questFour.statDown("leadership", 10);
                questFour.resourceUp("gold", 300, cunningMod);
            } else if ( randomNum1 == 5) {
                questFive.resourceDown("gold", 100);
                questFive.resourceUp("energy", 5, enduranceMod);
            } else if ( randomNum1 == 6) {
                questSix.resourceDown("gold", 500);
                questSix.statUp("cunning",15);
            }
        } else if ( answerVar == 'B' || answerVar == 'b') {
            if (randomNum2 == 0){
                questZero.resourceDown("stone", 20);
                questZero.resourceUp("gold", 50, cunningMod);
            } else if ( randomNum2 == 1) {
                questOne.resourceDown("energy", 10);
                questOne.resourceUp("stone", 100, leaderMod);
            } else if ( randomNum2 == 2) {
                questTwo.resourceDown("energy", 10);
                questTwo.resourceUp("wood", 100, intelMod);
            } else if ( randomNum2 == 3) {
                questThree.resourceDown("gold", 120);
                questThree.resourceUp("wood", 200, intelMod);
            } else if ( randomNum2 == 4) {
                questFour.statDown("leadership", 10);
                questFour.resourceUp("gold", 300, cunningMod);
            } else if ( randomNum2 == 5) {
                questFive.resourceDown("gold", 100);
                questFive.resourceUp("energy", 5, enduranceMod);
            } else if ( randomNum2 == 6) {
                questSix.resourceDown("gold", 500);
                questSix.statUp("cunning",15);
            }
        } else if ( answerVar == 'C' || answerVar == 'c') {
            if (randomNum3 == 0){
                questZero.resourceDown("stone", 20);
                questZero.resourceUp("gold", 50, cunningMod);
            } else if ( randomNum3 == 1) {
                questOne.resourceDown("energy", 10);
                questOne.resourceUp("stone", 100, leaderMod);
            } else if ( randomNum3 == 2) {
                questTwo.resourceDown("energy", 10);
                questTwo.resourceUp("wood", 100, intelMod);
            } else if ( randomNum3 == 3) {
                questThree.resourceDown("gold", 120);
                questThree.resourceUp("wood", 200, intelMod);
            } else if ( randomNum3 == 4) {
                questFour.statDown("leadership", 10);
                questFour.resourceUp("gold", 300, cunningMod);
            } else if ( randomNum3 == 5) {
                questFive.resourceDown("gold", 100);
                questFive.resourceUp("energy", 5, enduranceMod);
            } else if ( randomNum3 == 6) {
                questSix.resourceDown("gold", 500);
                questSix.statUp("cunning",15);
            }
        } else if ( answerVar == 'D' || answerVar == 'd'){
            if (resources["stone"]>=pyramids.stoneCost && resources["wood"]>=pyramids.woodCost){
                int x = resources["stone"];
                int y = pyramids.stoneCost;
                int stoneSum = x-y;
                resources["stone"]=stoneSum;
                int g = resources["wood"];
                int h = pyramids.woodCost;
                int woodSum = g-h;
                resources["wood"]=woodSum;

                cout << "\n"<< "You have constructed the mighty Pyramids! Look upon your works with pride, for you are a lion amongst sheep!" << "\n"<<"\n"<<"\n";
                cout << "Type 'end' to end game"<< "\n";
                string endVar;
                cin >> endVar;
                exit(0);
            } else {
                cout << "You lack the necessary resources. Pick a different choice."<< "\n";
                cin.clear();
            }
        } else if ( answerVar == 'E' || answerVar == 'e' && hadrianBool==true){
                questCharacter.resourceDown("stone", 50);
                questCharacter.resourceUp("energy", 20, enduranceMod);
                
        } else if ( answerVar == 'E' || answerVar == 'e' && nefertitiBool==true){ 
                questCharacter.resourceDown("energy", 10);
                questCharacter.resourceUp("gold", 200, cunningMod);                
            } else {
            cout << "\n""Invalid input. Please enter a valid answer."<< "\n";
            cin.clear();
        }
        
        resources["energy"] += enduranceMod;
        clockTicker();
};

int main(){
    characterSelect();
    return 0;
};