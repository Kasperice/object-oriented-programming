#pragma once

#include <string>

#include "cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(uint32_t amount, const std::string& name, uint32_t basePrice, int32_t expiryDate);
    ~Fruit() override;

    std::string getName() const override;
    uint32_t getAmount() const override;
    uint32_t getBasePrice() const override;
    double getPrice() const override;
    int32_t getExpiryDate() const override;

    Fruit& operator--();
    Fruit& operator+=(uint32_t amount) override;
    Fruit& operator-=(uint32_t amount) override;

private:
    const int32_t expiryDate_{10};
    int32_t currentExpiryDate_;
};
