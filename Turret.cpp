#include <string>
#include "Turret.h"


Turret::Turret(std::string b_name, double b_dmg, double b_fireRate, int b_ammoPerShot, int b_ammoConsumptionPerMin) {
	name = b_name;
	dmg = b_dmg;
	fireRate = b_fireRate;
	ammoPerShot = b_ammoPerShot;
	ammoConsumptionPerMin = b_ammoConsumptionPerMin;

}

std::string Turret::getName() {
	return name;
}
double Turret::getDmg() {
	return dmg;
}
double Turret::getFireRate() {
	return fireRate;
}
int Turret::getAmmoPerShot() {
	return ammoPerShot;
}
int Turret::getAmmoConsumptionPerMin() {
	return ammoConsumptionPerMin;
}

void Turret::setName(std::string s_name) {
	name = s_name;
}
void Turret::setDmg(double s_dmg) {
	dmg = s_dmg;
}

void Turret::setFireRate(double s_fireRate) {
	fireRate = s_fireRate;
}
void Turret::setAmmoPerShot(int s_ammoPerShot) {
	ammoPerShot = s_ammoPerShot;
}
void Turret::setAmmoConsumptionPerMin(int s_ammoConsumptionPerMin) {
	ammoConsumptionPerMin = s_ammoConsumptionPerMin;
}
