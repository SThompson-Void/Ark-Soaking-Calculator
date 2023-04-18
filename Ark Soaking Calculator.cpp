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
double getTotalNormalDmgMult(double saddle, double dmgMult, bool imprint, bool mateBoost, bool yutyBuff);
double getTotalTekDmgMult(double saddle, double tekDmgMult, bool imprint, bool mateBoost, bool yutyBuff);
double timeToHealDino(double hp, Healing object);
double getPerSoakData(double hp, double totalAutoDmg, double totalHeavyDmg, double totalTekDmg, Healing heal1, Healing heal2, Healing heal3, Healing heal4, Healing heal5);

//void printTimeToHealDinoList();

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
    double totalDmgMult{};
    double totalHeavyDmg{};
    double totalAutoDmg{};
    double totalTekDmg{};
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
    if ((hp * .005)*60 > 24000) {
        healthPerMinCheck = 24000;
    }
    else {
        healthPerMinCheck = (hp * .005) * 60;
    }
    Healing Daedon("Daedon", healthPerMinCheck);

    healthPerMinCheck = 0;
    if ((hp * .0033)*60 > 4800) {
        healthPerMinCheck = 4800;
    }
    else {
        healthPerMinCheck = (hp * .0033) * 60;
    }
  
    Healing PlantZ("PlantZ", healthPerMinCheck);



   //print test
    /*
    std::cout << name << hp << saddle << dmgMult << tekDmgMult << imprint << mateBoost << yutyBuff;
    std::cout << "the damage multiplier from a saddle of " << Soaker.getSaddle() << " = " << getSaddleMult(Soaker.getSaddle());
    */
    
    //creating the healers
    std::cout << "\nMinutes to heal with Veggie Cakes: " << timeToHealDino(hp, VeggieCake) << "\n";
    std::cout << "Minutes to heal with Snow Owl: " << timeToHealDino(hp, SnowOwl) << "\n";
    std::cout << "Minutes to heal with FeedMeat(If a carnivore): " << timeToHealDino(hp, FeedMeat) << "\n";
    std::cout << "Minutes to heal with Daedon: " << timeToHealDino(hp, Daedon) << "\n";
    std::cout << "Minutes to heal with Plant Z: " << timeToHealDino(hp, PlantZ) << "\n";

    //getting final turret damage values
    
    totalAutoDmg = getTotalNormalDmgMult(saddle, dmgMult, imprint, mateBoost, yutyBuff) * AutoTurret.getDmg();
    totalHeavyDmg = getTotalNormalDmgMult(saddle, dmgMult, imprint, mateBoost, yutyBuff) * HeavyTurret.getDmg();
    totalTekDmg = getTotalTekDmgMult(saddle, dmgMult, imprint, mateBoost, yutyBuff) * HeavyTurret.getDmg();


    //printing the soaking data

    getPerSoakData(hp, totalAutoDmg, totalHeavyDmg, totalTekDmg, VeggieCake, SnowOwl, FeedMeat, Daedon, PlantZ);


    std::cout << "\n\n";

    for (int i = 0; i < 60; i++) {
        std::cout << "=";
    }
    std::cout << "\n";
    std::cout << " E N D of V O I D 's  |Ark Soaking Calculator| Have fun!\n";

    for (int i = 0; i < 60; i++) {
        std::cout << "=";
    }
    std::cout << "\n";

    return 0;
}

int chooseSoaker(std::string& name, double& damageMult, double& tekDamageMult) {
    int choice{};
    std::cout << "\n";
    std::cout << "Choose which dino you will be using as a soaker: \n\n";
    std::cout << " 1 = Trike \n 2 = Carbo\n 3 = Stego \n 4 = Gasbag \n 5 = Rock Golem \n 6 = Diplo \n 7 = Reaper \n 8 = Paracer \n 9 = Snow Owl: ";
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


double getTotalNormalDmgMult(double saddle, double dmgMult, bool imprint, bool mateBoost, bool yutyBuff) {
    double tempMult = getSaddleMult(saddle) * dmgMult;
    if (mateBoost == true) {
        tempMult *= .67;
    }
    if (imprint == true) {
        tempMult *= .7;
    }
    if (yutyBuff == true) {
        tempMult *= .75;
    }
    return tempMult;
}

double getTotalTekDmgMult(double saddle, double tekDmgMult, bool imprint, bool mateBoost, bool yutyBuff) {
    double tempMult = getSaddleMult(saddle) * tekDmgMult;
    if (mateBoost == true) {
        tempMult *= .67;
    }
    if (imprint == true) {
        tempMult *= .7;
    }
    if (yutyBuff == true) {
        tempMult *= .75;
    }
    return tempMult;
}


double timeToHealDino(double hp, Healing object) {
    return hp / object.getHealPerMin();
}


double getPerSoakData(double hp, double totalAutoDmg, double totalHeavyDmg, double totalTekDmg, Healing VeggieCake, Healing SnowOwl, Healing FeedMeat, Healing Daedon, Healing PlantZ) {
    double originalHp = hp;
    int numAutos{};
    int numHeavies{};
    int numTeks{};
    double pulloutHp{};

    double multiAutoDamage{};
    double multiHeavyDamage{};
    double multiTekDamage{};
    double combinedTurretDamage{};

    double autoSoakTimeS{};
    double heavySoakTimeS{};
    double tekSoakTimeS{};

    int autoBullets{};
    int heavyBullets{};
    int tekBullets{};
    int shots{};
    double seconds{};


    std::cout << "\nWhat is the hp that you will be stopping the soak at? ";
    std::cin >> pulloutHp;
    std::cout << "\n";
    double soakHp = hp - pulloutHp;

    double timeShots{};
    timeShots = (soakHp / totalAutoDmg) / 2.5;
    std::cout << "You can soak an auto for " << soakHp / totalAutoDmg << " shots or " << timeShots << " seconds" << " or " << timeShots /60 << " minutes before pulling out at " << pulloutHp << " hp\n";
    timeShots = (soakHp / totalHeavyDmg) / 2.5;
    std::cout << "You can soak a heavy for " << soakHp / totalHeavyDmg << " shots or " << timeShots << " seconds" << " or " << timeShots / 60 << " minutes before pulling out at " << pulloutHp << " hp\n";
    timeShots = (soakHp / totalTekDmg) / 2.5;
    std::cout << "You can soak a tek for for " << soakHp / totalTekDmg << " shots or " << timeShots << " seconds" << " or " << timeShots / 60 << " minutes before pulling out at " << pulloutHp << " hp\n";

    //extend the function to provide data for the soaking times on more than one turret, maybe allow them to enter the amount of turrets
    std::cout << "\nEnter the number of Autos you will be soaking at once: ";
    std::cin >> numAutos;
    std::cout << "Enter the number of Heavies you will be soaking at once: ";
    std::cin >> numHeavies;
    std::cout << "Enter the number of Teks you will be soaking at once: ";
    std::cin >> numTeks;

    multiAutoDamage = numAutos * totalAutoDmg;
    multiHeavyDamage = numHeavies * totalHeavyDmg;
    multiTekDamage = numTeks * totalTekDmg;

    combinedTurretDamage = multiAutoDamage + multiHeavyDamage + multiTekDamage;
    timeShots = (soakHp / combinedTurretDamage) / 2.5;
    std::cout << "\nYou can soak the specified turret count from " << (numAutos+numHeavies+numTeks) << " turrets for: \n --"  << (soakHp / combinedTurretDamage) << " shots "  "\n -- " << timeShots << " seconds" << " \n -- " << timeShots / 60 << " minutes before pulling out at " << pulloutHp << " hp\n";
    //it takes about 9.67 minutes or 580 seconds to soak a capped auto/heavy  and 16.667 minutes to soak a capped tek or 1000 seconds
    //it takes 3.33 minutes per 1000 shards in a tek
    //it takes 6.67 minutes per 1000 arb in an auto
    //it takes 1.667 minutes per 1000 arb in a heavy
    std::cout << " \n";
    if (numAutos > 0) {
        std::cout << "Enter the number of bullets you think are in each Auto turret: ";
        std::cin >> autoBullets;
    }
    if (numHeavies > 0) {
        std::cout << "Enter the number of bullets you think are in each Heavy turret: ";
        std::cin >> heavyBullets;
    }
    if (numTeks > 0) {
        std::cout << "Enter the number of bullets you think are in each Tek turret: ";
        std::cin >> tekBullets;
    }

    shots = autoBullets + (heavyBullets/4) + (tekBullets/2);

    int soakerChoice;

    std::cout << "\nSimulating a soaking session...\n";
    std::cout << "\nChoose what you will be healing with\n 1 = Veggie Cakes \n 2 = Snow Owl\n 3 = Feeding Meat\n 4 = Deadon\n 5 = Plant Z: ";
    std::cin >> soakerChoice;

    while (shots >= 0) { 
        shots -= 1;
        hp -= combinedTurretDamage;
        seconds += .4; //a turret shoots 1 shot every .4 seconds approximately
        if (hp <= pulloutHp) {
            std::cout << "\nPulling Out to Heal...\n";
            if (soakerChoice == 1) {
                seconds += originalHp / (VeggieCake.getHealPerMin() / 60);
            }
            else if (soakerChoice == 2) {
                seconds += originalHp / (SnowOwl.getHealPerMin() / 60);
            }
            else if (soakerChoice == 3) {
                seconds += originalHp / (FeedMeat.getHealPerMin() / 60);
            }
            else if (soakerChoice == 4) {
                seconds += originalHp / (Daedon.getHealPerMin() / 60);
            }
            else if (soakerChoice == 5) {
                seconds += originalHp / (PlantZ.getHealPerMin() / 60);
            }

            hp = originalHp;
        }
        
    }
    
    std::cout << "\nIt will take you " << seconds << " seconds (" << seconds /60 << "minutes) to soak\n";

   /* autoSoakTimeS = 580;
    heavySoakTimeS = 580;
    tekSoakTimeS = 1000;
    
    std::cout << "Going with the current damage from the specified amount of turrets: " << (numAutos + numHeavies + numTeks) << ", you it would take you about: \n";
    std::cout << autoSoakTimeS / timeShots << " soaking sessions to soak a capped auto/heavy <<\n";
    std::cout << tekSoakTimeS / timeShots << " soaking sessions to soak a capped tek \n";
     */
    return 0;
   
}

/*void printTimeToHealDino() {
    std::cout << "Minutes to heal with Veggie Cakes:" << VeggieCake;
}*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
