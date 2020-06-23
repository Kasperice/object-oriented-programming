#include "fruit.hpp"

#include <iostream>

Fruit::Fruit(uint32_t amount, std::string name, uint32_t basePrice, uint32_t expiryDate)
    : Cargo(amount, name, basePrice), expiryDate_(expiryDate), currentExpiryDate_(expiryDate) {}
Fruit::~Fruit() {}

std::string Fruit::getName() const {
    return "Fruit " + name_;
}

uint32_t Fruit::getAmount() const {
    return amount_;
}

uint32_t Fruit::getBasePrice() const {
    return basePrice_;
}

uint32_t Fruit::getExpiryDate() const {
    return currentExpiryDate_;
}

double Fruit::getPrice() const {
    return basePrice_ * currentExpiryDate_ / expiryDate_;
}

Fruit& Fruit::operator--() {
    if (currentExpiryDate_ > 0) {
        --currentExpiryDate_;
    }
    return *this;
}

Fruit& Fruit::operator+=(uint32_t amount) {
    amount_ += amount;
    return *this;
}

Fruit& Fruit::operator-=(uint32_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
        return *this;
    }
    std::cout << "There is no so many fruits!";
    return *this;
}

// bool Fruit::operator==(Fruit& fruit) {
//     return (name_ == fruit.getName()) && (amount_ == fruit.getAmount()) && (basePrice_ == fruit.getBasePrice()) &&
//            (expiryDate_ == fruit.getExpiryDate());
// }
