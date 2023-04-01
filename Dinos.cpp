#include "Dinos.h"
#include <iostream>
#include <string>
class Dinos {

private:
	double health{};
	double saddle{};
	double dmgReduction{};
	std::string name{};

public:
	Dinos(std::string b_name, double b_health, double b_saddle, double b_dmgReduction)
	{
		b_name = name;
		b_health = health;
		b_saddle = saddle;
		b_dmgReduction = dmgReduction;

	}


	
	std::string getName() {
		return name;
	}

	double getHealth() {
		return health;
	}

	double getSaddle() {
		return saddle;
	}

	double getdmgReduction() {
		return dmgReduction;
	}

	void setName(std::string s_name) {
		name = s_name;
	}

	void setHealth(double s_health) {
		health = s_health;
	}

	void setSaddle(double s_saddle) {
		saddle = s_saddle;
	}

	void setdmgReduction(double s_dmgReduction){
		dmgReduction = s_dmgReduction;
	}


};
