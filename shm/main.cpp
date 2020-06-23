#include <iostream>
#include <memory>
#include <string>

#include "alcohol.hpp"
#include "cargo.hpp"
#include "coordinates.hpp"
#include "fruit.hpp"
#include "island.hpp"
#include "item.hpp"
#include "map.hpp"
#include "player.hpp"
#include "ship.hpp"

int main() {
    Ship blackPearl(200, 50, 180, "black pearl", 1);
    std::unique_ptr<Ship> ptr = std::make_unique<Ship>(blackPearl);
    Player pawellos(std::move(ptr), 300, 70);
    std::cout << pawellos.getMoney() << "\n";
    std::cout << pawellos.getAvailableSpace() << "\n";
    std::cout << pawellos.getSpeed() << "\n";
    std::cout << blackPearl.getName() << "\n";
    std::cout << blackPearl.getId() << "\n";
    std::cout << blackPearl.getMaxCrew() << "\n";
    std::cout << blackPearl.getCapacity() << "\n \n";

    std::cout << blackPearl.getCrew() << "\n";
    blackPearl += 6;
    std::cout << blackPearl.getCrew() << "\n";
    blackPearl -= 3;
    std::cout << blackPearl.getCrew() << "\n";
    blackPearl -= 8;
    std::cout << blackPearl.getCrew() << "\n";

    Fruit Banana(6, "Banana", 5, 10);
    std::shared_ptr<Fruit> banana = std::make_shared<Fruit>(Banana);
    Item Chocolate(5, "Milka", 5, Rarity::epic);
    Item IceCream(6, "scholler", 6, Rarity::common);

    std::cout << Banana.getName() << "\n";
    std::cout << Banana.getAmount() << "\n";
    std::cout << Banana.getBasePrice() << "\n";
    Banana += 7;
    std::cout << Banana.getAmount() << "\n";
    --Banana;
    --Banana;
    std::cout << Banana.getPrice() << "\n";
    IceCream -= 4;
    std::cout << IceCream.getAmount() << "\n";

    blackPearl.load(Banana);
    // blackPearl.load(IceCream);
    // Cargo* ptr_ = blackPearl.getCargo(1);
    std::cout << ptr_->getName() << "\n";
    // std::cout << blackPearl.getCargo(0)->getName() << "\n";

    // for (const auto& element : blackPearl.getVectorCargo()) {
    //     std::cout << element.getName() << "\n";
    // }

    Map mainMap;

    Coordinates location(1, 1);

    if (mainMap.getIsland(location)) {
        std::cout << "Island found!\n";
    }

    // std::cout << pawellos.getAvailableSpace() << "\n";

    // std::cout << pawellos.getShip()->getName() << "\n";
    // pawellos.getShip()->addToCargo(Chocolate);
    // std::cout << pawellos.getShip()->getCargo(0) << "\n";
    // std::cout << pawellos.getCargo(0)->getName() << "\n";
    return 0;
}
