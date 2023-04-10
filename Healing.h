#pragma once
#include <iostream>
#include <string>

class Healing {
private:
    std::string name{};
    double healPerMin{};

public:
    Healing() {}
    Healing(const std::string& name, double healPerMin) : name(name), healPerMin(healPerMin) {}

    std::string getName() const { return name; }
    double getHealPerMin() const { return healPerMin; }

    void setName(const std::string& name) { this->name = name; }
    void setHealPerMin(double healPerMin) { this->healPerMin = healPerMin; }
};