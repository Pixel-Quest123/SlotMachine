#ifndef SMINIGAMES_H
#define SMINIGAMES_H

#include <iostream>
#include <array>
#include <random>

#include "macros.h"


class sminigames
{
public:

    sminigames(std::mt19937& gen);
    ~sminigames();

    int play_s_minigame();

    const int get_counter();
    const int reset_counter();

private:

    std::mt19937 gen_;
    int counter_ = x0030;

    int choose_s_minigame();
    int get_random_outcome(std::array<int, 4> values);

    int coinflip(); // coin flip with an 2x or 10x
    int dices(); // 2 dices = multiplier
    int wheel(); // 17 wheel with 7 ones, 5 threes, 2 fives, 2 tens, 1 double
    int lucky_wheel(); // 17 wheel with 7 ones, 5 fives, 2 tens, 1 twenty, 1 fifty, 1 double

};

#endif //SMINIGAMES_H