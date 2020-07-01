#pragma once

#include "cargo.hpp"
#include "player.hpp"

class Store {
public:
    Store();
    ~Store();

    enum class Response { done, lack_of_money, lack_of_cargo, lack_of_space };

    Response buy(Cargo* cargo, uint32_t amount, Player* player);
    Response sell(Cargo* cargo, uint32_t amount, Player* player);

    Cargo* getCargo(uint32_t index) const;
    void generateCargo(Time* time);
    void printCargo() const;
    void loadToStore(Cargo* cargo);

private:
    std::vector<Cargo*> cargo_;
    friend std::ostream& operator<<(std::ostream& output, const Store& store);
};
