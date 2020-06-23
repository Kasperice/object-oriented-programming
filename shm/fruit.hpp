#pragma once

#include <string>

#include "cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(uint32_t amount, std::string name, uint32_t basePrice, uint32_t expiryDate);
    ~Fruit() override;

    std::string getName() const override;
    uint32_t getAmount() const override;
    uint32_t getBasePrice() const override;
    double getPrice() const override;
    uint32_t getExpiryDate() const;

    Fruit& operator--();
    Fruit& operator+=(uint32_t amount) override;
    Fruit& operator-=(uint32_t amount) override;
    // bool operator==(Cargo& fruit) override;

private:
    uint32_t expiryDate_;
    uint32_t currentExpiryDate_;
};
