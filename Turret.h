#pragma once
#include <string>

class Turret {

private:
	std::string name{};
	double dmg{};
	double fireRate{};
	int ammoPerShot{};
	int ammoConsumptionPerMin{};


public:
	Turret(std::string b_name, double b_dmg, double b_fireRate, int b_ammoPerShot, int b_ammoConsumptionPerMin);

	std::string getName();
	double getDmg();
	double getFireRate();
	int getAmmoPerShot();
	int getAmmoConsumptionPerMin();

	void setName(std::string s_name);
	void setDmg(double s_dmg);
	void setFireRate(double s_fireRate);
	void setAmmoPerShot(int s_ammoPerShot);
	void setAmmoConsumptionPerMin(int s_ammoConsumptionPerMin);


};
