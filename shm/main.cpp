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
#include "store.hpp"
#include "time.hpp"

int main() {
    // std::cout << pawellos.getMoney() << "\n";
    // std::cout << pawellos.getAvailableSpace() << "\n";
    // std::cout << pawellos.getSpeed() << "\n";
    // std::cout << pawellos.getShip()->getName() << "\n";
    /* std::cout << blackPearl.getName() << "\n";
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
    */

    Time gameTime;

    Ship blackPearl(200, 50, 180, "black pearl", 1, &gameTime);
    std::shared_ptr<Ship> ptr = std::make_shared<Ship>(200, 50, 180, "black pearl", 1, &gameTime);

    Player pawellos(ptr, 300, 70);

    // Cargo* bananas = new Fruit{10, "Bananas", 100, &gameTime, 10};
    // Cargo* oranges = new Fruit{50, "Oranges", 10, &gameTime, 10};
    // Cargo* apples = new Fruit{200, "Apples", 50, &gameTime, 10};
    // Cargo bananas(10, "Bananas", 100, &gameTime);
    // Cargo oranges(50, "Oranges", 10, &gameTime);
    // Cargo apples(200, "Apples", 50, &gameTime);

    // Cargo Chocolate(5, "milka", 3, &gameTime);
    // Cargo* Chocolate = new Item{5, "milka", 3, &gameTime, Rarity::legendary};
    // Cargo IceCream(6, "scholler", 8, &gameTime);
    // Cargo* IceCream = new Item{200, "scholler", 50, &gameTime, Rarity::epic};

    Cargo* ptrCargo1 = new Item(5, "milka", 3, &gameTime, Rarity::legendary);
    Cargo* ptrCargo2 = new Item(200, "scholler", 50, &gameTime, Rarity::epic);
    /*Cargo* Banana = new Fruit{6, "Banana", 5, 10};
    Item Chocolate(5, "Milka", 5, Rarity::epic);
    // Item IceCream(6, "scholler", 6, Rarity::common);
    std::shared_ptr<Cargo> ptrCargo = std::make_shared<Cargo>(Banana);
    std::cout << ptrCargo->getName() << "\n";
    std::cout << ptrCargo->getAmount() << "\n";
    std::cout << ptrCargo->getBasePrice() << "\n";
    Banana += 7;
    std::cout << ptrCargo->getAmount() << "\n";
    --Banana;
    --Banana;
    std::cout << ptrCargo->getPrice() << "\n";

    blackPearl.load(ptrCargo);*/

    pawellos.getShip()->load(ptrCargo1);
    pawellos.getShip()->load(ptrCargo2);
    std::cout << "---------Before buy------ \n\n";
    pawellos.getShip()->printCargo();
    std::cout << "Money of player: " << pawellos.getMoney() << '\n';
    std::cout << "Available place on ship: " << pawellos.getAvailableSpace() << '\n';
    Store biedronka;
    biedronka.generateCargo(&gameTime);
    biedronka.printCargo();
    std::cout << "---------After buy------ \n\n";
    // Player* ptrPlayer = &pawellos;
    biedronka.buy(biedronka.getCargo(0), 2, &pawellos);
    biedronka.buy(biedronka.getCargo(2), 8, &pawellos);
    biedronka.buy(biedronka.getCargo(1), 19, &pawellos);
    biedronka.buy(biedronka.getCargo(1), 190, &pawellos);
    biedronka.buy(biedronka.getCargo(3), 4, &pawellos);
    pawellos.getShip()->printCargo();
    std::cout << "Money of player: " << pawellos.getMoney() << '\n';
    std::cout << "Available place on ship: " << pawellos.getAvailableSpace() << '\n';
    biedronka.printCargo();

    std::cout << "---------Before sell------ \n\n";
    pawellos.getShip()->printCargo();
    std::cout << "Money of player: " << pawellos.getMoney() << '\n';
    std::cout << "Available place on ship: " << pawellos.getAvailableSpace() << '\n';
    biedronka.printCargo();
    // Nie działa sell - Naruszenie Ochrony Pamięci :/
    // Problem występuje dokładnie w store.cpp  linia 41
    // biedronka.sell(pawellos.getCargo(1), 3, &pawellos);
    // biedronka.sell(pawellos.getCargo(2), 2, &pawellos);
    std::cout << "---------After sell------ \n\n";
    pawellos.getShip()->printCargo();
    std::cout << "Money of player: " << pawellos.getMoney() << '\n';
    std::cout << "Available place on ship: " << pawellos.getAvailableSpace() << '\n';
    biedronka.printCargo();

    std::cout << "\n**************\n";

    Ship ship01(100, 20, 21, "Ship #1", 1, &gameTime);

    Cargo* bananasPtr = new Fruit(10, "Bananas", 100, &gameTime, 10);
    Cargo* orangesPtr = new Fruit(50, "Oranges", 10, &gameTime, 10);
    Cargo* applesPtr = new Fruit(200, "Apples", 50, &gameTime, 10);

    ship01.load(bananasPtr);
    ship01.load(bananasPtr);
    ship01.load(bananasPtr);

    ++gameTime;
    {
        Ship ship02(100, 20, 21, "Ship #2", 1, &gameTime);
        ship02.load(orangesPtr);

        ++gameTime;
        ++gameTime;
    }
    std::cout << "\n**************\n";

    Ship ship03(100, 20, 21, "Ship #3", 1, &gameTime);
    ship03.load(applesPtr);

    ++gameTime;
    ++gameTime;

    return 0;
}
