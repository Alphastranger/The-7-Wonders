#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
// Clock
int clockDown = 728;
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
float leaderMod;
int intelligence;
float intelMod;
int cunning;
float cunningMod;
int endurance;
float enduranceMod;
// Wonders:
class Wonders {
    public:
    string name;
    int stoneCost;
    int woodCost;
};
string Wonder; 
int wonArrTotal=7;
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
void wonderSelect();

///////////////
// Count Down
///////////////

void clockTicker(){
        clockDown -= 7;
        if (clockDown > 0) {
            startScreen();
        } else {
            cout << "Game Over" << "\n";
        };
};

///////////////
//Character Select
///////////////
void characterSelect(){
    string charNameInput;
    cout << "-----7 WONDERS-----"<<"\n""\n";
    cout << "Type in their name to select your character" << "\n";
    cout << "1. Hadrian" << "\n";
    cout << " A wise and steady emperor of Rome. Gifted in Leadership and stoneworking." << "\n";
    cout << "2. Nefertiti" << "\n";
    cout << " The wife of Akhenaten who famously pushed Egypt towards monotheism. Gifted in Cunning and tithes." << "\n";
    cout << "\n""\n";
    // An ancient chinese and indian leader
    //Chandragupta Maurya
    //Not necessarily a ruler, but an influential woman
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

///////////////
//Hadrian Start
///////////////

void hadrianStart(){
    Characters Hadrian;
        Hadrian.name = "Hadrian";
        Hadrian.startLead = 4;
        Hadrian.startInt = 2;
        Hadrian.startCun = 1;
        Hadrian.startEnd = 4;
        Hadrian.startGold = 300;
        Hadrian.startStone = 300;
        Hadrian.startWood = 200;
        Hadrian.startEnergy = 20;
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
    wonderSelect();
};

///////////////
// Nefertiti Start
///////////////

void nefertitiStart(){
    Characters Nefertiti;
        Nefertiti.name = "Nefertiti";
        Nefertiti.startLead = 1;
        Nefertiti.startInt = 3;
        Nefertiti.startCun = 5;
        Nefertiti.startEnd = 2;
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
    cout << "\n""Blessings upon you great Queen of the Nile! Welcome to 7 Wonders!"<<"\n""\n";
    cout << "In this game, you must race to complete all seven world wonders before the time runs out!""\n";
    wonderSelect();
}

///////////////
// Wonder Select
///////////////

void wonderSelect(){
   
    vector<string> wonUsed;
    int wonUsedLength;
        if (wonArrTotal == 7) {
            wonUsedLength=0;
        } else {
        wonUsedLength = sizeof(wonUsed)/sizeof(wonUsed[0]);
    };
    string wonArray[] = {
        "The_Pyramids",
        "The_Colossus",
        "Stonehenge",
        "The_Oracle",
        "The_Great_Lighthouse",
        "The_Hanging_Gardens",
        "The_Great_Wall_of_China"
    };
    vector<string> wonTrueArray;

    for (int i=0; i<wonArrTotal; i++){
        if (wonUsedLength==0){
            wonTrueArray.push_back(wonArray[i]);
        } else {
        for (int j=0; i<wonUsedLength-1; j++){
        if (wonArray[i]!=wonUsed[j]){
        wonTrueArray.push_back(wonArray[i]);
        };
        };
        };
    };

    string wonSelect;
    cout << "Please type the name of a wonder to build""\n""\n";
    cout << "1. " << wonTrueArray[0] << "\n";
    cout << "2. " << wonTrueArray[1] << "\n";
    cout << "3. " << wonTrueArray[2] << "\n";
    cout << "4. " << wonTrueArray[3] << "\n";
    cout << "5. " << wonTrueArray[4] << "\n";
    cout << "6. " << wonTrueArray[5] << "\n";
    cout << "7. " << wonTrueArray[6] << "\n""\n";
    cin >> wonSelect;
    int False = 0;
    for (int i = 0; i<wonArrTotal; i++){
        // cout << wonTrueArray[i] << "\n";
        // cout << wonSelect << "\n";
        // if (wonSelect == wonTrueArray[i]){
        //     cout << "Comparison success""\n";
        // };
        if (wonSelect != wonTrueArray[i]){
            False++;
        };
    };
    cout << False;

    if (False >= wonArrTotal) {
        cout << "\n""Sorry, that is not a valid input! Please try to be exact!""\n";
        wonderSelect();
    } else {
        Wonder = wonSelect;
    };
    for (int i=0; i<wonArrTotal; i++){
        wonTrueArray.pop_back();
    };
    // if (wonSelect != wonTrueArray[0]){
        
    // }else {
    //         Wonder = wonSelect;
    // };
    
    // for (int i=0; i<wonArrTotal; i++){
    //     if ( wonArray[i]==wonSelect){
    //         wonArray[i]=wonArray[i+1];
    //         if (wonArray[i+1] > wonArrTotal) {

    //         };
    //     };
    // };
    // if (wonArr[i]==wonSelect){
    //     wonUsed.push_back(wonArr[i])
    // }
    wonArrTotal--;
    
    startScreen();
}

///////////////
// Start Screen
///////////////

void startScreen(){
  leaderMod = (statistics["leadership"]/10);
  intelMod = (statistics["intelligence"]/10);
  cunningMod = (statistics["cunning"]/10);
  enduranceMod = (statistics["endurance"]/10);
        cout << "\n" << charName << "  |  " << "Days Left: " << clockDown << "\n" << "\n";
        cout << "Resources:   " << "Stats:" << "\n";
        cout << "----------------------------------------------"<< "\n";
        cout << "| Gold:" << resources["gold"] << " | Leadership:" << statistics["leadership"] << " |""\n";
        cout << "----------------------------------------------"<< "\n";
        cout << "| Stone:" << resources["stone"] << " | Intelligence:" << statistics["intelligence"] << " |""\n";
        cout << "----------------------------------------------"<< "\n";
        cout << "| Wood:" << resources["wood"] << " | Cunning:" << statistics["cunning"] << " |""\n";
        cout << "----------------------------------------------"<< "\n";
        cout << "| Energy:" << resources["energy"] << " | Endurance:" << statistics["endurance"] << " |""\n";
        cout << "----------------------------------------------"<< "\n";

        questionsFunc();
    };
///////////////
//Questions
///////////////

void questionsFunc(){ 
    // Wonders
    Wonders wonderSlot;
            wonderSlot.name = Wonder;

    if (wonderSlot.name == "The_Pyramids"){
            wonderSlot.stoneCost = 1200;
            wonderSlot.woodCost = 1200;
    } else if (wonderSlot.name == "The_Colossus"){
            wonderSlot.stoneCost = 1600;
            wonderSlot.woodCost = 800;
    } else if (wonderSlot.name == "Stonehenge"){
            wonderSlot.stoneCost = 3000;
            wonderSlot.woodCost = 400;
    } else if (wonderSlot.name == "The_Oracle") {
            wonderSlot.stoneCost = 700;
            wonderSlot.woodCost = 1700;
    } else if (wonderSlot.name == "The_Great_Lighthouse"){
            wonderSlot.stoneCost = 2000;
            wonderSlot.woodCost = 2400;
    } else if (wonderSlot.name == "The_Hanging_Gardens"){
            wonderSlot.stoneCost = 3000;
            wonderSlot.woodCost = 3000;
    } else if (wonderSlot.name == "The_Great_Wall_of_China"){
            wonderSlot.stoneCost = 5000;
            wonderSlot.woodCost = 1000;
    };

// Questions
    class Questions {
    public:
    string questionText;
    void resourceUp(string source, int Inc, int Mod){
        int x = resources[source];
        int y = Inc;
        int z = Mod;
        int sum = x + y + (y * z);
        resources[source]=sum;
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
        cout << x << "X""\n";
        int y = Dec;
        cout << y << "Y""\n";
        int sum = x - y;
        cout << sum << "SUM""\n";
        if (sum<0) {
            cout << "\n""INVALID STATS"<<"\n";
            clockTicker();
        }else {
        statistics[source]=sum;
        };
    }
};
    char answerVar;

// Questions
    Questions questZero;
        questZero.questionText = "We have an overabundance of stone this week! Spend 20 stone to get 50 gold?";
    Questions questOne;
        questOne.questionText = "Our miners are well rested after their day off! Spend 10 energy to mine 100 stone?";
    Questions questTwo;
        questTwo.questionText = "One of your forests has grown enough to be cut! Spend 10 energy to harvest 100 wood?";
    Questions questThree;
        questThree.questionText = "A neighboring kingdom has offered a trade deal! Spend 120 gold to get 200 wood?";
    Questions questFour;
        questFour.questionText = "Integrity is worth its weight in gold it seems. Sacrifice 3 leadership for 300 gold?";
    Questions questFive;
        questFive.questionText ="Your workers promise they will be working harder than ever if you treat them to drinks. Spend 100 gold for 15 energy?";
    Questions questSix;
        questSix.questionText ="Your skill in trade is only as good as how much coin you have. Would you like to buy 5 cunning for 500 gold?";
    Questions questSeven;
        questSeven.questionText ="A neighboring kingdom has offered a trade deal! Spend 150 gold to get 220 stone?";
    Questions questEight;
        questEight.questionText = "A local astronomer has made an appearance in court, asking for patronage. Spend 400 gold for 4 intelligence?";

    Questions qArray[] = {
        questZero,
        questOne,
        questTwo,
        questThree,
        questFour,
        questFive,
        questSix,
        questSeven,
        questEight,
    };

// Character Questions
    Questions questCharacter;
        questCharacter.questionText = uniqueQuest;

// Resource & Stat Changer
    Questions questChanger;

//Randomizer
    srand(time(0));
    int randomNum1 = rand()%9;
    int randomNum2 = rand()%9;
    int randomNum3 = rand()%9;

    while (randomNum2 == randomNum1 || randomNum2 == randomNum3) {
        randomNum2 = rand()%9;
    };
    while (randomNum3 == randomNum1 || randomNum3 == randomNum2) {
        randomNum3 = rand()%9;
    };
    // if ((randomNum2 == randomNum1) || (randomNum2 == randomNum3) && randomNum2 >0) {
    //     randomNum2-1;
    // } else if ((randomNum2 == randomNum1) || (randomNum2 == randomNum3) && randomNum2 <6) {
    //     randomNum2+1;
    // }  
    // if ((randomNum3 == randomNum1) || (randomNum3 == randomNum2) && randomNum3<0){
    //     randomNum3-1;
    // } else if ((randomNum3 == randomNum1) || (randomNum3 == randomNum2) && randomNum3>6){
    //     randomNum3+1;
    // }

// Outputs
    cout << "\n""----------------------------------------------"<< "\n";
    cout << "A. " << qArray[randomNum1].questionText << "\n";
    cout << "----------------------------------------------"<< "\n";
    cout << "B. " << qArray[randomNum2].questionText << "\n";
    cout << "----------------------------------------------"<< "\n";
    cout << "C. " << qArray[randomNum3].questionText << "\n";
    cout << "----------------------------------------------"<< "\n";
    cout << "D. " << wonderSlot.name << " Stone:" << wonderSlot.stoneCost << " Wood:" << wonderSlot.woodCost << "\n";
    cout << "----------------------------------------------"<< "\n";
    cout << "E. " << uniqueQuest << "\n";
    cout << "----------------------------------------------"<< "\n";
    cout << "F. Skip Turn for 5 Energy""\n";
    cout << "----------------------------------------------"<< "\n";
    cout << "\n""Please input the letter associated with your answer."<<"\n";

    cin >> answerVar;

        if (answerVar == 'A' || answerVar == 'a') {
            if (randomNum1 == 0){
                questChanger.resourceDown("stone", 20);
                questChanger.resourceUp("gold", 50, cunningMod);
            } else if ( randomNum1 == 1) {
                questChanger.resourceDown("energy", 10);
                questChanger.resourceUp("stone", 100, leaderMod);
            } else if ( randomNum1 == 2) {
                questChanger.resourceDown("energy", 10);
                questChanger.resourceUp("wood", 100, intelMod);
            } else if ( randomNum1 == 3) {
                questChanger.resourceDown("gold", 120);
                questChanger.resourceUp("wood", 200, intelMod);
            } else if ( randomNum1 == 4) {
                questChanger.statDown("leadership", 3);
                questChanger.resourceUp("gold", 300, cunningMod);
            } else if ( randomNum1 == 5) {
                questChanger.resourceDown("gold", 100);
                questChanger.resourceUp("energy", 15, enduranceMod);
            } else if ( randomNum1 == 6) {
                questChanger.resourceDown("gold", 500);
                questChanger.statUp("cunning",5);
            } else if (randomNum1 == 7) {
                questChanger.resourceDown("gold", 150);
                questChanger.resourceUp("stone", 220, leaderMod);
            } else if (randomNum1 == 8) {
                questChanger.resourceDown("gold", 400);
                questChanger.statUp("intelligence", 4);
            }
        } else if ( answerVar == 'B' || answerVar == 'b') {
            if (randomNum2 == 0){
                questChanger.resourceDown("stone", 20);
                questChanger.resourceUp("gold", 50, cunningMod);
            } else if ( randomNum2 == 1) {
                questChanger.resourceDown("energy", 10);
                questChanger.resourceUp("stone", 100, leaderMod);
            } else if ( randomNum2 == 2) {
                questChanger.resourceDown("energy", 10);
                questChanger.resourceUp("wood", 100, intelMod);
            } else if ( randomNum2 == 3) {
                questChanger.resourceDown("gold", 120);
                questChanger.resourceUp("wood", 200, intelMod);
            } else if ( randomNum2 == 4) {
                questChanger.statDown("leadership", 3);
                questChanger.resourceUp("gold", 300, cunningMod);
            } else if ( randomNum2 == 5) {
                questChanger.resourceDown("gold", 100);
                questChanger.resourceUp("energy", 15, enduranceMod);
            } else if ( randomNum2 == 6) {
                questChanger.resourceDown("gold", 500);
                questChanger.statUp("cunning",5);
            } else if (randomNum2 == 7) {
                questChanger.resourceDown("gold", 150);
                questChanger.resourceUp("stone", 220, leaderMod);
            } else if (randomNum2 == 8) {
                questChanger.resourceDown("gold", 400);
                questChanger.statUp("intelligence", 4);
            }
        } else if ( answerVar == 'C' || answerVar == 'c') {
            if (randomNum3 == 0){
                questChanger.resourceDown("stone", 20);
                questChanger.resourceUp("gold", 50, cunningMod);
            } else if ( randomNum3 == 1) {
                questChanger.resourceDown("energy", 10);
                questChanger.resourceUp("stone", 100, leaderMod);
            } else if ( randomNum3 == 2) {
                questChanger.resourceDown("energy", 10);
                questChanger.resourceUp("wood", 100, intelMod);
            } else if ( randomNum3 == 3) {
                questChanger.resourceDown("gold", 120);
                questChanger.resourceUp("wood", 200, intelMod);
            } else if ( randomNum3 == 4) {
                questChanger.statDown("leadership", 3);
                questChanger.resourceUp("gold", 300, cunningMod);
            } else if ( randomNum3 == 5) {
                questChanger.resourceDown("gold", 100);
                questChanger.resourceUp("energy", 15, enduranceMod);
            } else if ( randomNum3 == 6) {
                questChanger.resourceDown("gold", 500);
                questChanger.statUp("cunning",5);
            } else if (randomNum3 == 7) {
                questChanger.resourceDown("gold", 150);
                questChanger.resourceUp("stone", 220, leaderMod);
            } else if (randomNum3 == 8) {
                questChanger.resourceDown("gold", 400);
                questChanger.statUp("intelligence", 4);
            }
        } else if ( answerVar == 'D' || answerVar == 'd'){
            if (resources["stone"]>=wonderSlot.stoneCost && resources["wood"]>=wonderSlot.woodCost){
                int x = resources["stone"];
                int y = wonderSlot.stoneCost;
                int stoneSum = x-y;
                resources["stone"]=stoneSum;
                int g = resources["wood"];
                int h = wonderSlot.woodCost;
                int woodSum = g-h;
                resources["wood"]=woodSum;

                cout << "\n"<< "You have constructed" + wonderSlot.name + "! Look upon your works with pride, for you are a lion amongst sheep!" << "\n"<<"\n"<<"\n";
                wonderSelect();
                // cout << "Type 'end' to end game"<< "\n";
                // string endVar;
                // cin >> endVar;
                if (wonArrTotal==1){
                cout<< "\n""Congratulations! You completed all seven wonders! You have made your people proud, and established a legacy that will last throughout the ages!";
                cout << "Type 'end' to end game"<< "\n";
                    string endVar;
                    cin >> endVar;
                if (endVar != "end"){
                    cout << "\n""Close enough!";
                    exit(0);
                } else {
                    cout << "\n""Bye!";
                    exit(0);
                };
            }
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
        } else if ( answerVar == 'F' || answerVar == 'f'){
                resources["energy"] += 5;
        } else {
            cout << "\n""Invalid input. Please enter a valid answer."<< "\n";
            cin.clear();
        }
        
        resources["energy"] += enduranceMod;
        clockTicker();
};

///////////////
//Main
///////////////

int main(){
    characterSelect();
    return 0;
};