
#include <iostream>
#include <string>
#include "Dinos.h"

	Dinos::Dinos(std::string b_name, double b_health, double b_saddle, double b_dmgReduction, double b_tekDmgReduction, bool b_hasImprint, bool b_hasMateBoost, bool b_hasYutyBuff)
	{
		name = b_name;
		health = b_health;
		saddle = b_saddle;
		dmgReduction = b_dmgReduction;
		tekDmgReduction = b_tekDmgReduction;
		hasImprint = b_hasImprint;
		hasMateBoost = b_hasMateBoost;
		hasYutyBuff = b_hasYutyBuff;

	}



	 std::string Dinos::getName() {
		return name;
	}

	double Dinos::getHealth() {
		return health;
	}

	double Dinos::getSaddle() {
		return saddle;
	}

	double Dinos::getdmgReduction() {
		return dmgReduction;
	}
	
	bool Dinos::getHasImprint() {
		return hasImprint;
	}
	bool Dinos::getHasMateBoost() {
		return hasMateBoost;
	}
	bool Dinos::getHasYutyBuff() {
		return hasYutyBuff;
	}

	void Dinos::setName( std::string s_name) {
		name = s_name;
	}

	void Dinos::setHealth(double s_health) {
		health = s_health;
	}

	void Dinos::setSaddle(double s_saddle) {
		saddle = s_saddle;
	}

	void Dinos::setdmgReduction(double s_dmgReduction) {
		dmgReduction = s_dmgReduction;
	}

	void Dinos::setHasImprint(bool s_hasImprint) {
		hasImprint = s_hasImprint;
	}

	void Dinos::setHasMateBoost(bool s_hasMateBoost) {
		hasMateBoost = s_hasMateBoost;
	}
	void Dinos::setHasYutyBuff(bool s_hasYutyBuff) {
		hasYutyBuff = s_hasYutyBuff;
	}
