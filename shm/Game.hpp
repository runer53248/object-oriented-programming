#pragma once

#include "DefaultCargo.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Store.hpp"
#include "Fruit.hpp"
#include "DryFruit.hpp"

#include <array>
#include <cmath>
#include <iostream>
#include <map>

constexpr size_t start_money = 1'000;
constexpr size_t game_days = 100;
constexpr size_t final_goal = 2'000;

// Return by value to give up ownership
std::unique_ptr<Cargo> generateCargo();

#include "Command.hpp"

class Game {
public:
    Game(size_t startMoney, size_t daysLimit, size_t goal)
        : startMoney_(startMoney), daysLimit_(daysLimit), goal_(goal) {}

    void startGame();
    void init();

    constexpr static size_t startingPlayerCargoNumber = 5;
    constexpr static size_t storeCargoNumber = 5;

    void fillCargo(Warehouse &holder, size_t number);
   
private:
    size_t startMoney_;
    size_t daysLimit_;
    size_t goal_;
    bool endGame{false};
    bool playerWin{false};

    std::map<std::string, std::unique_ptr<Command>> commands{};
    Map map{};
    Player player{std::make_unique<Ship>(), startMoney_};
    Store store{};
};