#include "player.hpp"

#include <numeric>

Player::Player(std::shared_ptr<Ship> ship, uint32_t money, uint32_t availableSpace)
    : ship_(std::move(ship)), money_(money), availableSpace_(availableSpace) {}

std::shared_ptr<Ship> Player::getShip() {
    return std::move(ship_);
}
uint32_t Player::getAvailableSpace() const {
    return availableSpace_;
}
uint32_t Player::getMoney() const {
    return money_;
}

uint32_t Player::countAvailableSpace() const {
    uint32_t sumOfAmounts =
        std::accumulate(ship_->getVectorCargo().begin(), ship_->getVectorCargo().end(), 0,
                        [](size_t amounts, std::shared_ptr<Cargo> cargo) { return amounts += cargo->getAmount(); });

    return ship_->getCapacity() - sumOfAmounts;
}

uint32_t Player::getSpeed() const {
    return ship_->getSpeed();
}

// Cargo* Player::getCargo(uint32_t index) const {
//     // if (ship_) {
//     //     return ship_->getCargo(index);
//     // }
//     // return nullptr;
// }

void Player::purchaseCargo(std::shared_ptr<Cargo> cargo, uint32_t amount, uint32_t price) {
    availableSpace_ -= amount;
    money_ -= price;
    ship_->load(cargo);
}

void Player::printCargo() const {
    // ship_->printCargo();
}
