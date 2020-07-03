#include "ship.hpp"

#include <iostream>
#include <string>

Ship::Ship() : id_(-1){};

Ship::Ship(int capacity, int maxCrew, int speed, const std::string& name, size_t id)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(0), speed_(speed), name_(name), id_(id){};

Ship::Ship(int maxCrew, int speed, size_t id) : Ship(0, maxCrew, speed, "", id){};

void Ship::setName(const std::string& name) {
    name_ = name;
}

Ship& Ship::operator-=(size_t crew) {
    if (crew < crew_) {
        crew_ -= crew;
        return *this;
    }
    std::cerr << "Too few sailors!";
    return *this;
}

Ship& Ship::operator+=(size_t crew) {
    if (crew_ + crew <= maxCrew_) {
        crew_ += crew;
        return *this;
    }
    std::cerr << "Too many sailors!";
    return *this;
}

size_t Ship::getId() const {
    return id_;
}

std::string Ship::getName() const {
    return name_;
}

size_t Ship::getSpeed() const {
    return speed_;
}

size_t Ship::getCrew() const {
    return crew_;
}

size_t Ship::getMaxCrew() const {
    return maxCrew_;
}

size_t Ship::getCapacity() const {
    return capacity_;
}

Cargo* Ship::getCargo(size_t index) {
    return &cargo_[index];
}

std::vector<Cargo> Ship::getVectorCargo() const {
    return cargo_;
}
