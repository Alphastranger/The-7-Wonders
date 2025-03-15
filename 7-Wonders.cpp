#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <random>
using namespace std;
// Clock
int clockDown = 1456;
// Resources:
map<string, int> resources;
int gold;
int stone;
int wood;
int energy;
bool resourceFail;
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
bool statFail;
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

char answerVar;


///////////////
// Count Down
///////////////

void clockTicker(){
        if (statFail == false && resourceFail == false){
            clockDown -= 7;
        }
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
        Hadrian.Quest = "Erect a frontier wall to relieve the troops, costing 50 stone and granting 20 energy?";
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
        "The Pyramids",
        "The Colossus",
        "Stonehenge",
        "The Oracle",
        "The Great Lighthouse",
        "The Hanging Gardens",
        "The Great Wall of China"
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
    // cout <<"selection 1"<< wonSelect<< "\n";

    ///////////////// See if this line needs changing to fix wonders
    cin.ignore();
    /////////////
    getline(std::cin, wonSelect);
    // cout <<"selection 2" << wonSelect<< "\n";
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
    // cout << False;

    if (False >= wonArrTotal) {
        cout << "\n""Sorry, that is not a valid input! Please try to be exact!""\n";
        wonderSelect();
    } else {
        Wonder = wonSelect;
    };
    for (int i=0; i<wonArrTotal; i++){
        wonTrueArray.pop_back();
    };
    wonArrTotal--;
    
    startScreen();
}

///////////////
// Start Screen
///////////////

void startScreen(){
  leaderMod = (statistics["leadership"]/10);
  intelMod = (statistics["intelligence"]/1);
  cunningMod = (statistics["cunning"]/100);
  enduranceMod = (statistics["endurance"]/100);
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
        cout << leaderMod<< "\n";
        cout << intelMod<< "\n";
        cout << cunningMod<< "\n";
        cout << enduranceMod<< "\n""\n";
        questionsFunc();
    };
///////////////
//Questions
///////////////

void questionsFunc(){
    resourceFail = false;
    statFail = false;
    // Wonders
    Wonders wonderSlot;
            wonderSlot.name = Wonder;

    if (wonderSlot.name == "The Pyramids"){
            // wonderSlot.stoneCost = 1200;
            // wonderSlot.woodCost = 1200;
            wonderSlot.stoneCost = 1;
            wonderSlot.woodCost = 1;
    } else if (wonderSlot.name == "The Colossus"){
            // wonderSlot.stoneCost = 1600;
            // wonderSlot.woodCost = 800;
            wonderSlot.stoneCost = 1;
            wonderSlot.woodCost = 1;
    } else if (wonderSlot.name == "Stonehenge"){
            // wonderSlot.stoneCost = 2000;
            // wonderSlot.woodCost = 400;
            wonderSlot.stoneCost = 1;
            wonderSlot.woodCost = 1;
    } else if (wonderSlot.name == "The Oracle") {
            // wonderSlot.stoneCost = 700;
            // wonderSlot.woodCost = 1700;
            wonderSlot.stoneCost = 1;
            wonderSlot.woodCost = 1;
    } else if (wonderSlot.name == "The Great Lighthouse"){
            // wonderSlot.stoneCost = 2000;
            // wonderSlot.woodCost = 2400;
            wonderSlot.stoneCost = 1;
            wonderSlot.woodCost = 1;
    } else if (wonderSlot.name == "The Hanging Gardens"){
            // wonderSlot.stoneCost = 2000;
            // wonderSlot.woodCost = 2000;
            wonderSlot.stoneCost = 1;
            wonderSlot.woodCost = 1;
    } else if (wonderSlot.name == "The Great Wall of China"){
            // wonderSlot.stoneCost = 3000;
            // wonderSlot.woodCost = 1000;
             wonderSlot.stoneCost = 1;
            wonderSlot.woodCost = 1;
    };

///////////
// Questions Class
///////////
    class Questions {
    public:
    // ID
    int ID;
    // Booleans
    bool resUp;
    bool resUp2;
    bool resDown;
    bool resDown2;
    bool statUpBool;
    bool statUp2Bool;
    bool statDownBool;
    bool statDown2Bool;
    // Resource Up
    string resUpStr;
    string resUpStr2;
    int resUpInt;
    int resUpInt2;
    float resUpMod;
    float resUpMod2;
   
    // Resource Down
    string resDownStr;
    string resDownStr2;
    int resDownInt;
    int resDownInt2;
    
    // Stat Up
    string statUpStr;
    string statUpStr2;
    int statUpInt;
    int statUpInt2;
   
    // Stat Down
    string statDownStr;
    string statDownStr2;
    int statDownInt;
    int statDownInt2;

    // Modifiers
    void statDown(string source, int Dec){
        int x = statistics[source];
        cout << x << "X""\n";
        int y = Dec;
        cout << y << "Y""\n";
        int sum = x - y;
        cout << sum << "SUM""\n";
        if (sum<0) {
            cout << "\n""INVALID STATS"<<"\n";
            statFail=true;
            clockTicker();
        }else {
        statistics[source]=sum;
        };
    };
    void resourceDown(string source, int Dec){
        int x = resources[source];
        int y = Dec;
        int sum = x - y;
        if (sum<0) {
            cout << "\n""INVALID RESOURCES"<<"\n";
            resourceFail = true;
            clockTicker();
        } else {
        resources[source]=sum;
        }
    };
    void resourceUp(string source, int Inc, float Mod){
        int x = resources[source];
        int y = Inc;
        float z = Mod;
        cout << "ModMod: " << Mod<<"\n";
        cout << "Mod Value: "<<z<<"\n";
        int sum = x + y + (y * z);
        float sum2 = x + y + (y*z);
        float sum3 = (y*z) + y + x;
        cout << "Sum: "<< sum<<"\n";
        cout << "Sum2: "<< sum2<<"\n";
        cout << "Sum3: "<< sum3<<"\n";
        float inAction = (y*z);
        float buttKiss = 3.13;
        cout << "The modifier in action: "<<inAction<< "+" << buttKiss <<"\n";
        resources[source]=sum;
    };
    void statUp(string source, int Inc){
        int x = statistics[source];
        int y = Inc;
        int sum = x + y;
        statistics[source]=sum;
    }
    // Question Text
    string questionText;
};

    

// Question List
    Questions questZero;
        questZero.questionText = "We have an overabundance of stone this week! Spend 20 stone to get 50 gold?";
        questZero.ID = 0;
        questZero.resUp = true;
        questZero.resDown = true;
        questZero.resUpStr = "gold";
        questZero.resUpInt = 50;
        questZero.resUpMod = cunningMod;
        questZero.resDownStr = "stone";
        questZero.resDownInt = 20;
    Questions questOne;
        questOne.questionText = "Our miners are well rested after their day off! Spend 10 energy to mine 100 stone?";
        questOne.ID = 1;
        questOne.resUp = true;
        questOne.resDown = true;
        questOne.resUpStr = "stone";
        questOne.resUpInt = 100;
        questOne.resUpMod = leaderMod;
        questOne.resDownStr = "energy";
        questOne.resDownInt = 10;
    Questions questTwo;
        questTwo.questionText = "One of your forests has grown enough to be cut! Spend 10 energy to harvest 100 wood?";
        questTwo.ID = 2;
        questTwo.resUp = true;
        questTwo.resDown = true;
        questTwo.resUpStr = "wood";
        questTwo.resUpInt = 100;
        questTwo.resUpMod = intelMod;
        questTwo.resDownStr = "energy";
        questTwo.resDownInt = 10;
    Questions questThree;
        questThree.questionText = "A neighboring kingdom has offered a trade deal! Spend 120 gold to get 200 wood?";
        questThree.ID = 3;
        questThree.resUp = true;
        questThree.resDown = true;
        questThree.resUpStr = "wood";
        questThree.resUpInt = 200;
        questThree.resUpMod = intelMod;
        questThree.resDownStr = "gold";
        questThree.resDownInt = 120;
    Questions questFour;
        questFour.questionText = "Integrity is worth its weight in gold it seems. Sacrifice 3 leadership for 300 gold?";
        questFour.ID = 4;
        questFour.resUp = true;
        questFour.statDownBool = true;
        questFour.resUpStr = "gold";
        questFour.resUpInt = 300;
        questFour.resUpMod = cunningMod;
        questFour.statDownStr = "leadership";
        questFour.statDownInt = 3;
    Questions questFive;
        questFive.questionText ="Your workers promise they will be working harder than ever if you treat them to drinks. Spend 100 gold for 15 energy?";
        questFive.ID = 5;
        questFive.resUp = true;
        questFive.resDown = true;
        questFive.resUpStr = "energy";
        questFive.resUpInt = 15;
        questFive.resUpMod = enduranceMod;
        questFive.resDownStr = "gold";
        questFive.resDownInt = 100;
    Questions questSix;
        questSix.questionText ="Your skill in trade is only as good as how much coin you have. Would you like to buy 5 cunning for 500 gold?";
        questSix.ID = 6;
        questSix.resDown = true;
        questSix.statUpBool = true;
        questSix.resDownStr = "gold";
        questSix.resDownInt = 500;
        questSix.statUpStr = "cunning";
        questSix.statUpInt = 5;
    Questions questSeven;
        questSeven.questionText ="A neighboring kingdom has offered a trade deal! Spend 150 gold to get 220 stone?";
        questSeven.ID = 7;
        questSeven.resUp = true;
        questSeven.resDown = true;
        questSeven.resUpStr = "stone";
        questSeven.resUpInt = 220;
        questSeven.resUpMod = leaderMod;
        questSeven.resDownStr = "gold";
        questSeven.resDownInt = 150;
    Questions questEight;
        questEight.questionText = "A local astronomer has made an appearance in court, asking for patronage. Spend 400 gold for 4 intelligence?";
        questEight.ID = 8;
        questEight.statUpBool = true;
        questEight.resDown = true;
        questEight.resDownStr = "gold";
        questEight.resDownInt = 400;
        questEight.statUpStr = "intelligence";
        questEight.statUpInt = 4;
    Questions questNine;
        questNine.questionText = "After a drought in a neighboring kingdom killed off their vegetation, wood is in high demand. Sell 50 wood for 100 gold?";
        questNine.ID = 9;
        questNine.resUp = true;
        questNine.resDown = true;
        questNine.resUpStr = "gold";
        questNine.resUpInt = 100;
        questNine.resUpMod = cunningMod;
        questNine.resDownStr = "wood";
        questNine.resDownInt = 50;
    Questions questTen;
        questTen.questionText = "Your advisors think a statue in your likeness will set you apart as a ruler. Donate 200 stone for 2 leadership?";
        questTen.ID = 10;
        questTen.statUpBool = true;
        questTen.resDown = true;
        questTen.statUpStr = "leadership";
        questTen.statUpInt = 2;
        questTen.resDownStr = "stone";
        questTen.resDownInt = 200;
    Questions questEleven;
        questEleven.questionText = "There is always more room for money in the bank, and your resources are taking up space. Sell off 50 wood and 50 stone for 200 gold?";
        questEleven.ID = 11;
        questEleven.resUp = true;
        questEleven.resDown = true;
        questEleven.resDown2 = true;
        questEleven.resUpStr = "gold";
        questEleven.resUpInt = 200;
        questEleven.resUpMod = cunningMod;
        questEleven.resDownStr = "wood";
        questEleven.resDownInt = 50;
        questEleven.resDownStr2 = "stone";
        questEleven.resDownInt2 = 50;
    Questions questTwelve;
        questTwelve.questionText = "A bountiful harvest will ensure more coin passes through your fingers, and encouragement will help. Spend 15 energy for 150 gold?";
        questTwelve.ID = 12;
        questTwelve.resUp = true;
        questTwelve.resDown = true;
        questTwelve.resUpStr = "gold";
        questTwelve.resUpInt = 150;
        questTwelve.resUpMod = cunningMod;
        questTwelve.resDownStr = "energy";
        questTwelve.resDownInt = 15;
    Questions questThirteen;
        questThirteen.questionText = "If you work your people extra hard this week, it won't be so difficult the next time. Spend 20 energy to increase endurance by 2?";
        questThirteen.ID = 13;
        questThirteen.resDown = true;
        questThirteen.statUpBool = true;
        questThirteen.resDownStr = "energy";
        questThirteen.resDownInt = 20;
        questThirteen.statUpStr = "endurance";
        questThirteen.statUpInt = 2;
    Questions questFourteen;
        questFourteen.questionText = "The old library near the city square is becoming an eyesore amongst the elite. Tear it down for 400 stone at the cost of losing 4 intelligence?";
        questFourteen.ID = 14;
        questFourteen.resUp = true;
        questFourteen.statDownBool = true;
        questFourteen.resUpStr = "stone";
        questFourteen.resUpInt = 400;
        questFourteen.resUpMod = leaderMod;
        questFourteen.statDownStr = "intelligence";
        questFourteen.statDownInt = 4;

    
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
        questNine,
        questTen,
        questEleven,
        questTwelve,
        questThirteen,
        questFourteen,
    };

    int qArrayLength = sizeof(qArray)/sizeof(qArray[0]);

// Character Questions
    Questions questCharacter;
        questCharacter.questionText = uniqueQuest;

//Randomizer

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, qArrayLength-1);

    int randomNum1 = dis(gen);
    int randomNum2 = dis(gen);
    int randomNum3 = dis(gen);

    while (randomNum2 == randomNum1 || randomNum2 == randomNum3) {
        randomNum2 = rand()%qArrayLength;
    };
    while (randomNum3 == randomNum1 || randomNum3 == randomNum2) {
        randomNum3 = rand()%qArrayLength;
    };

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

if (answerVar == 'A' || answerVar == 'a'){
    for (int i=0; i<qArrayLength; i++){     
        if (randomNum1 == qArray[i].ID) {
           if (qArray[i].resUp){
        qArray[i].resourceUp(qArray[i].resUpStr, qArray[i].resUpInt, qArray[i].resUpMod);
           };
            if (qArray[i].resUp2){
        qArray[i].resourceUp(qArray[i].resUpStr2, qArray[i].resUpInt2, qArray[i].resUpMod2);
            };
            if (qArray[i].resDown) {
        qArray[i].resourceDown(qArray[i].resDownStr, qArray[i].resDownInt);
            };
            if (qArray[i].resDown2){
        qArray[i].resourceDown(qArray[i].resDownStr2, qArray[i].resDownInt2);
        };
            if (qArray[i].statUpBool) {
        qArray[i].statUp(qArray[i].statUpStr, qArray[i].statUpInt);
            };
            if (qArray[i].statUp2Bool){
        qArray[i].statUp(qArray[i].statUpStr2, qArray[i].statUpInt2);
        };
            if (qArray[i].statDownBool) {
        qArray[i].statDown(qArray[i].statDownStr, qArray[i].statDownInt);
            };
            if (qArray[i].statDown2Bool){
        qArray[i].statDown(qArray[i].statDownStr2, qArray[i].statDownInt2);
            };
        }; 
    };
} else if (answerVar == 'B' || answerVar == 'b'){
    for (int i=0; i<qArrayLength; i++){     
        if (randomNum2 == qArray[i].ID) {
           if (qArray[i].resUp){
        qArray[i].resourceUp(qArray[i].resUpStr, qArray[i].resUpInt, qArray[i].resUpMod);
           };
            if (qArray[i].resUp2){
        qArray[i].resourceUp(qArray[i].resUpStr2, qArray[i].resUpInt2, qArray[i].resUpMod2);
            };
            if (qArray[i].resDown) {
        qArray[i].resourceDown(qArray[i].resDownStr, qArray[i].resDownInt);
            };
            if (qArray[i].resDown2){
        qArray[i].resourceDown(qArray[i].resDownStr2, qArray[i].resDownInt2);
        };
            if (qArray[i].statUpBool) {
        qArray[i].statUp(qArray[i].statUpStr, qArray[i].statUpInt);
            };
            if (qArray[i].statUp2Bool){
        qArray[i].statUp(qArray[i].statUpStr2, qArray[i].statUpInt2);
        };
            if (qArray[i].statDownBool) {
        qArray[i].statDown(qArray[i].statDownStr, qArray[i].statDownInt);
            };
            if (qArray[i].statDown2Bool){
        qArray[i].statDown(qArray[i].statDownStr2, qArray[i].statDownInt2);
            };
        }; 
    };
} else if (answerVar == 'C' || answerVar == 'c'){
    for (int i=0; i<qArrayLength; i++){     
        if (randomNum3 == qArray[i].ID) {
           if (qArray[i].resUp){
        qArray[i].resourceUp(qArray[i].resUpStr, qArray[i].resUpInt, qArray[i].resUpMod);
           };
            if (qArray[i].resUp2){
        qArray[i].resourceUp(qArray[i].resUpStr2, qArray[i].resUpInt2, qArray[i].resUpMod2);
            };
            if (qArray[i].resDown) {
        qArray[i].resourceDown(qArray[i].resDownStr, qArray[i].resDownInt);
            };
            if (qArray[i].resDown2){
        qArray[i].resourceDown(qArray[i].resDownStr2, qArray[i].resDownInt2);
        };
            if (qArray[i].statUpBool) {
        qArray[i].statUp(qArray[i].statUpStr, qArray[i].statUpInt);
            };
            if (qArray[i].statUp2Bool){
        qArray[i].statUp(qArray[i].statUpStr2, qArray[i].statUpInt2);
        };
            if (qArray[i].statDownBool) {
        qArray[i].statDown(qArray[i].statDownStr, qArray[i].statDownInt);
            };
            if (qArray[i].statDown2Bool){
        qArray[i].statDown(qArray[i].statDownStr2, qArray[i].statDownInt2);
            };
        }; 
    };
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

                cout << "\n"<< "You have constructed " + wonderSlot.name + "! Look upon your works with pride, for you are a lion amongst sheep!" << "\n"<<"\n"<<"\n";
                "Time Restored";
                clockDown += 100;
                wonderSelect();

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