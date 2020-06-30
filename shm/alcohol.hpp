#pragma once

#include <string>

#include "cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol(uint32_t amount, const std::string& name, uint32_t basePrice, Time* time, int32_t power);
    ~Alcohol() override = default;

    std::string getName() const override;
    uint32_t getAmount() const override;
    uint32_t getBasePrice() const override;
    double getPrice() const override;
    int32_t getPower() const;

    Cargo& operator+=(uint32_t amount) override;
    Cargo& operator-=(uint32_t amount) override;
    bool operator==(const Cargo& cargo) const override;

private:
    const int32_t maxAlcohol_{96};
    int32_t power_;
};
