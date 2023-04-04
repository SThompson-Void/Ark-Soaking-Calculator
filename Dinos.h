#pragma once
#include <string>

class Dinos
{

private:

	double health{};
	double saddle{};
	double dmgReduction{};
	std::string name{};


public:
	Dinos( std::string b_name, double b_health, double b_saddle, double b_dmgReduction);


	std::string getName();
	double getHealth();
	double getSaddle();
	double getdmgReduction();
	void setName(std::string s_name);
	void setHealth(double s_health);
	void setSaddle(double s_saddle);
	void setdmgReduction(double s_dmgReduction);

};

