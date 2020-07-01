#include "store.hpp"

#include <algorithm>
#include <random>

#include "fruit.hpp"

Store::Store() {}
Store::~Store() {}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    out << "Available Cargo in Store: \n";
    std::for_each(store.cargo_.begin(), store.cargo_.end(), [&, i{0}](const auto& cargo) mutable {
        out << ++i << " - " << cargo->getName() << "  AMOUNT: " << cargo->getAmount()
            << "  PRICE: " << cargo->getBasePrice() << '\n';
    });
    return out;
}

Store::Response Store::buy(Cargo* cargo, uint32_t amount, Player* player) {
    const uint32_t price = amount * cargo->getBasePrice();
    // std::shared_ptr<Cargo> buyCargo = std::make_shared<Fruit>(*cargo);

    if (amount > player->getAvailableSpace()) {
        return Store::Response::lack_of_space;
    }
    if (amount > cargo->getAmount()) {
        return Store::Response::lack_of_cargo;
    }
    if (price > player->getMoney()) {
        return Store::Response::lack_of_money;
    }
    *cargo -= amount;
    // *buyCargo -= cargo->getAmount();
    player->purchaseCargo(cargo, amount, price);

    return Store::Response::done;
}

Store::Response Store::sell(Cargo* cargo, uint32_t amount, Player* player) {
    const uint32_t price = amount * cargo->getBasePrice();
    player->sellCargo(cargo, amount, price);
    loadToStore(cargo);
    return Store::Response::done;
}

Cargo* Store::getCargo(uint32_t index) const {
    if (cargo_.size() > index) {
        return cargo_[index];
    }
    return nullptr;
}

void Store::generateCargo(Time* time) {
    const int minAmountOfCargo = 50;
    const int maxAmountOfCargo = 300;
    const int minPriceOfCargo = 5;
    const int maxPriceOfCargo = 15;
    std::uniform_int_distribution<> amountOfCargo(minAmountOfCargo, maxAmountOfCargo);
    std::uniform_int_distribution<> priceOfCargo(minPriceOfCargo, maxPriceOfCargo);
    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<std::string> cargoProducts = {"Coffee",    "Tea",     "Cigarette", "Ice cream",
                                              "Chocolate", "Alcohol", "Fruits",    "Chips"};
    for_each(cargoProducts.begin(), cargoProducts.end(), [&](const auto& cargo) {
        cargo_.emplace_back(new Fruit(amountOfCargo(gen), cargo, priceOfCargo(gen), time, 20));
    });
}

void Store::printCargo() const {
    std::cout << "CARGO IN STORE : "
              << "\n";
    std::for_each(cargo_.begin(), cargo_.end(), [](const auto& cargo) {
        std::cout << cargo->getName() << "  " << cargo->getAmount() << "  " << cargo->getBasePrice() << "\n";
    });
}

void Store::loadToStore(Cargo* cargo) {
    for (auto& element : cargo_) {
        if (cargo->getName() == element->getName()) {
            *element += cargo->getAmount();
            return;
        }
    }
    cargo_.emplace_back(cargo);
}
