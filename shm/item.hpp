#pragma once

#include <string>

#include "cargo.hpp"

class Item : public Cargo {
public:
    Item(uint32_t amount, const std::string& name, uint32_t basePrice, Rarity rarity);
    ~Item() override = default;

    std::string getName() const override;
    uint32_t getAmount() const override;
    uint32_t getBasePrice() const override;
    double getPrice() const override;
    Rarity getRarity() const;

    Item& operator+=(uint32_t amount) override;
    Item& operator-=(uint32_t amount) override;

private:
    const Rarity rarity_;
};
