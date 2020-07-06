#pragma once

#include <string>

#include "cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(uint32_t amount, const std::string& name, uint32_t basePrice, int32_t expiryDate);
    ~Fruit() override;

    // override from Cargo
    std::string getName() const override;
    uint32_t getAmount() const override;
    uint32_t getBasePrice() const override;
    int32_t getExpiryDate() const;
    double getPrice() const override;
    Fruit& operator--();
    Cargo& operator+=(uint32_t amount) override;
    Cargo& operator-=(uint32_t amount) override;
    bool operator==(const Cargo& cargo) const override;
    void nextDay() override;
    virtual std::shared_ptr<Cargo> clone() const override;

private:
    const int32_t expiryDate_{10};
    int32_t currentExpiryDate_;
};
