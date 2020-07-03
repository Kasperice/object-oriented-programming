#include "cargo.hpp"
//#include "fruit.hpp"
#include "player.hpp"
#include "ship.hpp"
#include "store.hpp"
#include "time.hpp"

#include <iostream>
#include <memory>
#include <string>

int main() {
    // std::cout << pawellos.getMoney() << "\n";
    // std::cout << pawellos.getAvailableSpace() << "\n";
    // std::cout << pawellos.getSpeed() << "\n";
    // std::cout << pawellos.getShip()->getName() << "\n";

    Time gameTime;

    Ship blackPearl(200, 50, 180, "black pearl", 1, &gameTime);
    std::shared_ptr<Ship> ptr = std::make_shared<Ship>(200, 50, 180, "black pearl", 1, &gameTime);

    Player pawellos(ptr, 300, 70);

    // Fruit bananas(10, "Bananas", 100);
    // Cargo oranges(50, "Oranges", 10, &gameTime);
    // Cargo apples(200, "Apples", 50, &gameTime);

    // Cargo Chocolate(5, "milka", 3, &gameTime);
    // Cargo IceCream(6, "scholler", 8, &gameTime);

    // std::shared_ptr<Cargo> ptrCargo1 = std::make_shared<Cargo>(Chocolate);
    // std::shared_ptr<Cargo> ptrCargo2 = std::make_shared<Cargo>(IceCream);

    // pawellos.getShip()->load(ptrCargo1);
    // pawellos.getShip()->load(ptrCargo2);
    std::cout << "---------Before buy------ \n\n";
    pawellos.getShip()->printCargo();
    std::cout << "Money of player: " << pawellos.getMoney() << '\n';
    std::cout << "Available place on ship: " << pawellos.getAvailableSpace() << '\n';
    Store biedronka;
    biedronka.generateCargo();
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
    biedronka.sell(pawellos.getCargo(1), 3, &pawellos);
    biedronka.sell(pawellos.getCargo(2), 2, &pawellos);
    std::cout << "---------After sell------ \n\n";
    pawellos.getShip()->printCargo();
    std::cout << "Money of player: " << pawellos.getMoney() << '\n';
    std::cout << "Available place on ship: " << pawellos.getAvailableSpace() << '\n';
    biedronka.printCargo();

    std::cout << "\n**************\n";

    Ship ship01(100, 20, 21, "Ship #1", 1, &gameTime);

    std::shared_ptr<Cargo> bananasPtr = std::make_shared<Fruit>(10, "Bananas", 100, 10);
    std::shared_ptr<Cargo> orangesPtr = std::make_shared<Fruit>(50, "Oranges", 10, 10);
    std::shared_ptr<Cargo> applesPtr = std::make_shared<Fruit>(200, "Apples", 50, 10);

    ship01.load(bananasPtr);
    ship01.load(orangesPtr);
    ship01.load(applesPtr);

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
}
// #include "game.hpp"
// #include "player.hpp"
// #include "ship.hpp"
// #include "store.hpp"

// constexpr uint32_t start_money = 1000;
// constexpr uint32_t game_days = 100;
// constexpr uint32_t final_goal = 2000;

// int main() {
//     Game game(start_money, game_days, final_goal);
//     game.startGame();
//     return 0;
// }
