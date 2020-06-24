#include "ship.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

Ship::Ship() : id_(-1){};

Ship::Ship(uint32_t capacity, uint32_t maxCrew, uint32_t speed, const std::string& name, uint32_t id)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id){};

Ship::Ship(uint32_t maxCrew, uint32_t speed, uint32_t id) : Ship(0, maxCrew, speed, "", id){};

void Ship::setName(const std::string& name) {
    name_ = name;
}

void Ship::addToCargo(Cargo* cargo) {
    cargo_.emplace_back(cargo);
}

Ship& Ship::operator-=(uint32_t crew) {
    if (crew < crew_) {
        crew_ -= crew;
        return *this;
    }
    std::cerr << "Too few sailors!";
    return *this;
}

Ship& Ship::operator+=(uint32_t crew) {
    if (crew_ + crew <= maxCrew_) {
        crew_ += crew;
        return *this;
    }
    std::cerr << "Too many sailors!";
    return *this;
}

uint32_t Ship::getId() const {
    return id_;
}

std::string Ship::getName() const {
    return name_;
}

uint32_t Ship::getSpeed() const {
    return speed_;
}

uint32_t Ship::getCrew() const {
    return crew_;
}

uint32_t Ship::getMaxCrew() const {
    return maxCrew_;
}

uint32_t Ship::getCapacity() const {
    return capacity_;
}

Cargo* Ship::getCargo(size_t index) const {
    if (cargo_.size() > index) {
        return cargo_[index].get();
    }
    return nullptr;
}

std::vector<std::shared_ptr<Cargo>> Ship::getVectorCargo() const {
    return cargo_;
}

Cargo* Ship::findMatchCargo(Cargo* cargo) {
    for (auto el : cargo_) {
        if (el->getName() == "Fruit") {
            if (el->getName() == cargo->getName() && el->getBasePrice() == cargo->getBasePrice() /*&&
                el->getExpiryDate() == cargo->getExpiryDate()*/) {
                return el.get();
            }
        } else if (el->getName() == "Alcohol") {
            if (el->getName() == cargo->getName() && el->getBasePrice() == cargo->getBasePrice() /*&&
                el->getPower() == cargo->getPower()*/) {
                return el.get();
            }
        } else {
            if (el->getName() == cargo->getName() && el->getBasePrice() == cargo->getBasePrice() /*&&
                el->getRarity() == cargo->getRarity()*/) {
                return el.get();
            }
        }
    }
}

void Ship::removeFromStorage(Cargo* cargo) {
    cargo_.erase(std::find_if(cargo_.begin(), cargo_.end(), [cargo](const auto& el) { return *el == *cargo; }));
}

void Ship::load(std::shared_ptr<Cargo> cargo) {
    if (auto match_cargo = findMatchCargo(cargo.get())) {
        *match_cargo += cargo->getAmount();
        return;
    }
    cargo_.push_back(std::move(cargo));
}

// void Ship::load(std::shared_ptr<Cargo> cargo) {
//     cargo_.emplace_back(cargo);
// }

void Ship::unload(Cargo* cargo) {
    removeFromStorage(cargo);
}
