#include <time.h>
#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "Cargo.hpp"
#include "DefaultCargo.hpp"
#include "Island.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Store.hpp"
#include "Time.hpp"

#include "Game.hpp"

void testCargoShipPlayer() {
    Time* time = Time::getInstance();
    constexpr size_t testCases{10};
    constexpr size_t testShipCapacity{100};
    std::vector<std::unique_ptr<Cargo>> cargoVec;
    cargoVec.reserve(testShipCapacity);
    for (size_t i = 0; i < testCases; ++i) {
        size_t cargoAmount = rand() % testShipCapacity;
        for (size_t i = 0; i < cargoAmount; ++i) {
            cargoVec.push_back(generateCargo());
        }
        auto pirateShip = std::make_unique<Ship>(testShipCapacity, 40, 10, "The Adventure Galley Pirate Ship", 0, std::move(cargoVec));
        cargoVec.clear();
        Player pirate(std::move(pirateShip), 1000);
        std::cout << "\n\n--- CARGO/SHIP/PLAYER TEST ---\n";
        pirate.printCargoManifest();
        time->nextDay();
    }
}

void testIslandMap() {
    constexpr size_t testCases{10};
    for (size_t i = 0; i < testCases; ++i) {
        Map map;
        auto mapVec = map.getIslandVec();
        size_t num{1};
        std::cout << "\n\n--- MAP/ISLAND TEST ---\n";
        for (const auto& island : mapVec) {
            std::cout << num++ << ". ";
            std::cout << island.getPosition();
            if (map.getIsland(island.getPosition()) != nullptr) {
                std::cout << "^-Island exists\n";
            } else {
                std::cout << "^-Island does not exist\n";
            }
        }
    }
}

void testTime() {
    Time* time = Time::getInstance();
    CargoDefault cargo1{"Cargo1", 100, 100};
    CargoDefault cargo2{"Cargo2", 100, 100};
    CargoDefault cargo3{"Cargo2", 100, 100};
    Ship ship1{100, 100, 100, "Ship1", 1, {}};
    Ship ship2{100, 100, 100, "Ship2", 2, {}};
    Ship ship3{100, 100, 100, "Ship3", 3, {}};
    Store store;
    time->nextDay();
}

void timePassTest() {
    Time* time = Time::getInstance();
    CargoDefault cargo1{"Cargo1", 100, 100};
    CargoDefault cargo2{"Cargo2", 100, 100};
    CargoDefault cargo3{"Cargo2", 100, 100};
    Ship ship1{100, 100, 100, "Ship1", 1, {}};
    Ship ship2{100, 100, 100, "Ship2", 2, {}};
    Ship ship3{100, 100, 100, "Ship3", 3, {}};
    Store store;
    time->update();
}

int main() {
    std::srand(std::time(0));
    /*testCargoShipPlayer();
    testIslandMap();
    testTime();
    timePassTest();*/

    Game game(start_money, game_days, final_goal);
    game.startGame();

    return 0;
}
