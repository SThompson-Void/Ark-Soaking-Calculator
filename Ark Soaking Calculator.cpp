// Ark Soaking Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Dinos.h"
#include "Turret.h"
#include "Healing.h"

double getSaddleMult(double saddleArmor);
int chooseSoaker(std::string& name, double& damageMult, double& tekDamageMult);
int setBuffs(bool& imprint, bool& mateBoost, bool& yutyBuff);
int setHp(double& hp);
int setSaddle(double& saddle);

int main()
{
    //vars
    std::string name{};
    double hp{};
    double saddle{};
    double dmgMult{};
    double tekDmgMult{};
    bool imprint{};
    bool mateBoost{};
    bool yutyBuff{};

    //welcome screen
    for (int i = 0; i < 60; i++) {
        std::cout << "=";
    }
    std::cout << "\n";
    std::cout << " W E L C O M E  to  V O I D 's  |Ark Soaking Calculator|\n";

        for(int i = 0; i < 60; i++) {
            std::cout<< "=";
    }
        std::cout << "\n";
    //creating the dino object
    chooseSoaker(name, dmgMult, tekDmgMult);
    setBuffs(imprint, mateBoost, yutyBuff);
    setHp(hp);
    setSaddle(saddle);

    Dinos Soaker(name, hp, saddle, dmgMult, tekDmgMult, imprint, mateBoost, yutyBuff);
    
    //creating the turrets
    Turret HeavyTurret("Heavy Turret", 531, 2.5, 4, 600);
    Turret AutoTurret("Auto Turret", 118, 2.5, 1, 150);
    Turret TekTurret("Tek Turret", 450, 2.5, 2, 300);


    //creating the healers
    int healthPerMinCheck{};
    if (hp > 21000) {
        healthPerMinCheck = 5200;
    }
    else {
        healthPerMinCheck = 2 * (hp * .1 + 500);
        if (healthPerMinCheck > 5200) {
            healthPerMinCheck = 5200;
        }
    }
    Healing VeggieCake("Veggie Cake", healthPerMinCheck);
    Healing SnowOwl("Snow Owl Freeze", 2400);
    Healing FeedMeat("Force Feed Meat(Carnivores/Omnivores)", 1450);
    healthPerMinCheck = 0;
    if (hp * .005 > 24000) {
        healthPerMinCheck = 24000;
    }
    else {
        healthPerMinCheck = hp * .005;
    }
    Healing Daedon("Daedon", healthPerMinCheck);
    healthPerMinCheck = 0;
    if (hp * .0033 > 4800) {
        healthPerMinCheck = 4800;
    }
    else {
        healthPerMinCheck = hp * .0033;
    }
  
    Healing PlantZ("PlantZ", healthPerMinCheck);


   //print test
    /*
    std::cout << name << hp << saddle << dmgMult << tekDmgMult << imprint << mateBoost << yutyBuff;
    std::cout << "the damage multiplier from a saddle of " << Soaker.getSaddle() << " = " << getSaddleMult(Soaker.getSaddle());
    */
    


    return 0;
}

int chooseSoaker(std::string& name, double& damageMult, double& tekDamageMult) {
    int choice{};
    std::cout << "\n";
    std::cout << "Choose which dino you will be using as a soaker: \n\n";
    std::cout << "1 = Trike \n 2 = Carbo\n 3 = Stego \n 4 = Gasbag \n 5 = Rock Golem \n 6 = Diplo \n 7 = Reaper \n 8 = Paracer \n 9 = Snow Owl :";
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "\nYou have chosen a Trike, Damage Multiplier = .14, Tek Damage Multiplier = .14(Only when shot in the head)\n";
        name = "Trike";
        damageMult = .14;
        tekDamageMult = .14;
    }
    else if (choice == 2) {
        std::cout << "\nYou have chosen a Carbo, Damage Multiplier = .2, Tek Damage Multiplier = .2(When shot in the body)\n";
        name = "Carbo";
        damageMult = .2;
        tekDamageMult = .2;
    }
    else if (choice == 3) {
        std::cout << "\nYou have chosen a Stego, Damage Multiplier = .34, Tek Damage Multiplier = .5(When shot in the body)\n";
        name = "Stego";
        damageMult = .34;
        tekDamageMult = .5;
    }
    else if (choice == 4) {
        std::cout << "\nYou have chosen a Gasbag, Damage Multiplier = .2, Tek Damage Multiplier = .2(When shot with 80%+ Air Filled)\n";
        name = "Gasbag";
        damageMult = .2;
        tekDamageMult = .2;
    }
    else if (choice == 5) {
        std::cout << "\nYou have chosen a Rock Golem, Damage Multiplier = .086, Tek Damage Multiplier = 1.667 \n";
        name = "Rock Golem";
        damageMult = .086;
        tekDamageMult = 1.667;
    }
    else if (choice == 6) {
        std::cout << "\nYou have chosen a Diplo, Damage Multiplier = 1, Tek Damage Multiplier = 1\n";
        name = "Diplo";
        damageMult = 1;
        tekDamageMult = 1;
    }
    else if (choice == 7) {
        std::cout << "\nYou have chosen a Reaper, Damage Multiplier = .2, Tek Damage Multiplier = .333\n";
        name = "Reaper";
        damageMult = .2;
        tekDamageMult = .333;
    }
    else if (choice == 8) {
        std::cout << "\nYou have chosen a Paracer, Damage Multiplier = 1, Tek Damage Multiplier = 1\n";
        name = "Paracer";
        damageMult = 1;
        tekDamageMult = 1;
    }
    else if (choice == 9) {
        std::cout << "\nYou have chosen a Snow Owl, Damage Multiplier = 1, Tek Damage Multiplier = 1.667\n";
        name = "Snow Owl";
        damageMult = 1;
        tekDamageMult = 1;
    }

    return 0;
}

int setBuffs(bool& imprint, bool& mateBoost, bool& yutyBuff) {
    char choice{};
    std::cout << "\nEnter Y for Yes, N for No\n\n";
    std::cout << "Are you imprinted on the dino?: ";
    std::cin >> choice;
    if (choice == 'N' || choice == 'n') {
        imprint = true;
    }
    else {
        imprint = false;
    }

    std::cout << "\nWill the dino be mate boosted while soaking?: ";
    std::cin >> choice;

    if (choice == 'N' || choice == 'n') {
        mateBoost = true;
    }
    else {
        mateBoost = false;
    }

    std::cout << "\nWill the dino be yuty buffed while soaking?: ";
    std::cin >> choice;
    if (choice == 'N' || choice == 'n') {
        yutyBuff = true;
    }
    else {
        yutyBuff = false;
    }
    return 0;
}

double getSaddleMult(double saddleArmor) {
    double saddleMult{};
    saddleMult = 100 / (100 + (4 * saddleArmor));
    return saddleMult;
}

int setHp(double& hp) {
    double temphp{};
    std::cout << "\nWhat is the max hp of your dino?: ";
    std::cin >> temphp;
    hp = temphp;
    return 0;
}

int setSaddle(double& saddle) {
    double tempsaddle;
    std::cout << "\nEnter the saddle armor on your dino: ";
    std::cin >> tempsaddle;
    saddle = tempsaddle;
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
