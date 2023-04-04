
#include <iostream>
#include <string>
#include "Dinos.h"

	Dinos::Dinos( std::string b_name, double b_health, double b_saddle, double b_dmgReduction)
	{
		name = b_name;
		health = b_health;
		saddle = b_saddle;
		dmgReduction = b_dmgReduction;

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

