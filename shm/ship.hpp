#pragma once
#include <string>
#include <vector>

#include "cargo.hpp"

class Ship {
public:
    Ship();
    Ship(uint32_t capacity, uint32_t maxCrew, uint32_t speed, const std::string& name, uint32_t id);
    Ship(uint32_t maxCrew, uint32_t speed, uint32_t id);

    void setName(const std::string& name);
    void addToCargo(Cargo cargo);

    Ship& operator-=(uint32_t crew);
    Ship& operator+=(uint32_t crew);

    uint32_t getId() const;
    std::string getName() const;
    uint32_t getSpeed() const;
    uint32_t getCrew() const;
    uint32_t getMaxCrew() const;
    uint32_t getCapacity() const;
    Cargo* getCargo(size_t index);
    std::vector<Cargo> getVectorCargo() const;

    void load(const std::shared_ptr<Cargo>& cargo);
    void unload(Cargo* cargo);

private:
    uint32_t id_;
    std::string name_;
    uint32_t speed_;
    uint32_t maxCrew_;
    uint32_t capacity_;
    uint32_t crew_;
    std::vector<Cargo> cargo_;
};
