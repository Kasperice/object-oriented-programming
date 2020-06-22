#include "item.hpp"

#include <iostream>

enum class Rarity { common = 1, rare = 3, epic = 7, legendary = 15 };

Item::Item(uint32_t amount, const std::string& name, uint32_t basePrice, Rarity rarity)
    : Cargo(amount, name, basePrice), rarity_(rarity) {}

std::string Item::getName() const {
    return name_;
}

uint32_t Item::getAmount() const {
    return amount_;
}

uint32_t Item::getBasePrice() const {
    return basePrice_;
}

double Item::getPrice() const {
    return basePrice_ * static_cast<int>(rarity_);
}

Rarity Item::getRarity() const {
    return rarity_;
}

Item& Item::operator+=(uint32_t amount) {
    amount_ += amount;
    return *this;
}

Item& Item::operator-=(uint32_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
        return *this;
    }
    std::cout << "There is no so many items!";
    return *this;
}
