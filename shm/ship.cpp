#include "ship.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

Ship::Ship() : id_(-1) {}

Ship::Ship(uint32_t capacity, uint32_t maxCrew, uint32_t speed, const std::string& name, uint32_t id, Time* time)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id), time_(time) {
    time_->registerObserver(this);
}

Ship::~Ship() {
    time_->unregisterObserver(this);
}

void Ship::setName(const std::string& name) {
    name_ = name;
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
        return cargo_[index];
    }
    return nullptr;
}

std::vector<Cargo*> Ship::getVectorCargo() const {
    return cargo_;
}

void Ship::load(Cargo* cargo) {
    for (auto& element : getVectorCargo()) {
        if (cargo->getName() == element->getName()) {
            *element += cargo->getAmount();
            return;
        }
        cargo_.emplace_back(cargo);
        time_->registerObserver(cargo_.back());
    }
}

void Ship::unload(Cargo* cargo, uint32_t amount) {
    auto it = std::find_if(cargo_.begin(), cargo_.end(),
                           [cargo](const auto& ptr) { return ptr->getName() == cargo->getName(); });
    if (it != cargo_.end()) {
        // Tego nie mogłem ogarnąć, jak z wskazywanego cargo pobrać Amount
        // if (amount == it->getAmount()) {
        if (amount == 5) {
            cargo_.erase(it);
        } else {
            *cargo -= amount;
        }
    };
}

void Ship::printCargo() const {
    std::cout << "CARGO ON SHIP : "
              << "\n";
    std::for_each(cargo_.begin(), cargo_.end(), [](const auto& cargo) {
        std::cout << cargo->getName() << "  " << cargo->getAmount() << "  " << cargo->getBasePrice() << "\n";
    });
}

void Ship::nextDay() {
    std::cout << "Next day in: " << getName() << " \n";
}
