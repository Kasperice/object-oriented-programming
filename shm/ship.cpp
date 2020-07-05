#include "ship.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

Ship::Ship() : id_(-1) {}

Ship::Ship(uint32_t capacity, uint32_t maxCrew, uint32_t speed, const std::string& name, uint32_t id, Time* time)
    : capacity_(capacity), maxCrew_(maxCrew), crew_(10), speed_(speed), name_(name), id_(id), time_(time) {
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

std::shared_ptr<Cargo> Ship::getCargo(size_t index) const {
    if (cargo_.size() > index) {
        return cargo_[index];
    }
    return nullptr;
}

std::vector<std::shared_ptr<Cargo>> Ship::getVectorCargo() const {
    return cargo_;
}

void Ship::load(std::shared_ptr<Cargo> cargo) {
    for (auto& element : getVectorCargo()) {
        if (cargo.get()->getName() == element->getName()) {
            *element += cargo.get()->getAmount();
            return;
        }
    }
    cargo_.emplace_back(cargo);
    time_->registerObserver(cargo_.back().get());
}

void Ship::unload(std::shared_ptr<Cargo> cargo, uint32_t amount) {
    auto it = std::find_if(cargo_.begin(), cargo_.end(),
                           [cargo](const auto& ptr) { return ptr->getName() == cargo->getName(); });
    if (it != cargo_.end()) {
        if (amount == it->get()->getAmount()) {
            cargo_.erase(it);
        } else {
            *cargo -= amount;
        }
    };
}

void Ship::printCargo() const {
    std::cout << "CARGO ON SHIP : "
              << "\n";
    std::for_each(cargo_.begin(), cargo_.end(), [i{0}](const auto& cargo) mutable {
        std::cout << ++i << " - " << cargo->getName() << "  " << cargo->getAmount() << "  " << cargo->getBasePrice()
                  << "\n";
    });
}

void Ship::setDelegate(Delegate* const playerDelegate) {
    playerDelegate_ = playerDelegate;
}

void Ship::nextDay() {
    if (playerDelegate_) {
        playerDelegate_->payCrew(crew_);
    }
}
