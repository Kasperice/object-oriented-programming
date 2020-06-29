#include "fruit.hpp"

#include <iostream>

Fruit::Fruit(uint32_t amount, const std::string& name, uint32_t basePrice, int32_t expiryDate)
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

int32_t Fruit::getExpiryDate() const {
	return currentExpiryDate_;
}

double getPrice() const {
	return basePrice_ * currentExpiryDate_ / expiryDate_;
}

Fruit& Fruit::operator-- () {
	if (currentExpiryDate_ > 0) {
		--currentExpiryDate_;
	}
	return *this;
}

Cargo& Fruit::operator += (uint32_t amount) {
	amount_ += amount;
	return *this;
}

Cargo& Fruit::operator -= (uint32_t amount) {
	if (amount <= amount_) {
		amount_ -= amount;
		return *this;
	}
	std::cout << "There is no so many fruits!";
	return *this;
}

bool Fruit::operator == (Cargo& cargo) const {
	auto fruit = static_cast<const Fruit&>(cargo);
	if (typeid(*this) != typeid(cargo)) {
		return false;
	}
	return fruit.getBasePrice() == basePrice_ && fruit.getName() == name_ && fruit.getExpiryDate() == expiryDate_;
}
