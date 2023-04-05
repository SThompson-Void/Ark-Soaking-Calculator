#pragma once
#include <string>

class Dinos
{

private:

	double health{};
	double saddle{};
	double dmgReduction{};
	double tekDmgReduction{};
	bool hasImprint{};
	bool hasMateBoost{};
	bool hasYutyBuff{};
	std::string name{};


public:
	Dinos( std::string b_name, double b_health, double b_saddle, double b_dmgReduction, double b_tekDmgReduction, bool b_hasImprint, bool b_hasMateBoost, bool b_hasYutyBuff);


	std::string getName();
	double getHealth();
	double getSaddle();
	double getdmgReduction();
	bool getHasImprint();
	bool getHasMateBoost();
	bool getHasYutyBuff();
	void setName(std::string s_name);
	void setHealth(double s_health);
	void setSaddle(double s_saddle);
	void setdmgReduction(double s_dmgReduction);
	void setHasImprint(bool s_hasImprint);
	void setHasMateBoost(bool s_hasMateBoost);
	void setHasYutyBuff(bool s_hasYutyBuff);

};

