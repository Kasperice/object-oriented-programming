#pragma once
#include <iostream>
#include <memory>

#include "cargo.hpp"
#include "ship.hpp"

class Player {
public:
    Player(std::unique_ptr<Ship> ship, uint32_t money, uint32_t availableSpace);

    std::unique_ptr<Ship> getShip();
    uint32_t getMoney() const;
    uint32_t getAvailableSpace() const;

    uint32_t getSpeed() const;
    std::shared_ptr<Cargo> getCargo(uint32_t index) const;

private:
    std::unique_ptr<Ship> ship_;
    uint32_t availableSpace_;
    uint32_t money_;

    uint32_t countAvailableSpace() const;
};
