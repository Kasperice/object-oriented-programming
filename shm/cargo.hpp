#pragma once

#include <string>

class Cargo {
public:
    Cargo(uint32_t amount, std::string name, uint32_t basePrice);
    virtual ~Cargo() = default;

    virtual uint32_t getAmount() const = 0;
    virtual uint32_t getBasePrice() const = 0;
    virtual std::string getName() const = 0;
    virtual double getPrice() const = 0;
    // virtual int32_t getExpiryDate() const = 0;
    // virtual int32_t getPower() const = 0;
    // virtual Rarity getRarity() const = 0;

    virtual Cargo& operator+=(uint32_t amount) = 0;
    virtual Cargo& operator-=(uint32_t amount) = 0;
    bool operator==(Cargo& cargo);

protected:
    std::string name_;
    uint32_t amount_;
    uint32_t basePrice_;
};
