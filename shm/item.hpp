#pragma once

#include <string>

#include "cargo.hpp"

enum class Rarity { common = 1, rare = 3, epic = 7, legendary = 15 };
class Item : public Cargo {
public:
    Item(uint32_t amount, std::string name, uint32_t basePrice, Rarity rarity);
    ~Item() override;

    std::string getName() const override;
    uint32_t getAmount() const override;
    uint32_t getBasePrice() const override;
    double getPrice() const override;
    Rarity getRarity() const;

    Item& operator+=(uint32_t amount) override;
    Item& operator-=(uint32_t amount) override;
    // bool operator==(Item& item);

private:
    const Rarity rarity_;
};
