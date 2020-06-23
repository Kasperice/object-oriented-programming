#include "alcohol.hpp"

#include <iostream>

Alcohol::Alcohol(uint32_t amount, const std::string& name, uint32_t basePrice, int32_t power)
    : Cargo(amount, name, basePrice), power_(power) {}

std::string Alcohol::getName() const {
    return "Alcohol " + name_;
}

uint32_t Alcohol::getAmount() const {
    return amount_;
}

uint32_t Alcohol::getBasePrice() const {
    return basePrice_;
}

double Alcohol::getPrice() const {
    return basePrice_ * power_ / maxAlcohol_;
}

int32_t Alcohol::getPower() const {
    return power_;
}

Alcohol& Alcohol::operator+=(uint32_t amount) {
    amount_ += amount;
    return *this;
}

Alcohol& Alcohol::operator-=(uint32_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
        return *this;
    }
    std::cout << "There is no so many alcohol!";
    return *this;
}
