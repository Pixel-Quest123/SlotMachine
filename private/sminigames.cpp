#include "sminigames.h"

sminigames::sminigames(std::mt19937& gen) : gen_(gen)
{
}

sminigames::~sminigames()
{
}

int sminigames::play_s_minigame()
{
    counter_ -= 1;
    if(counter_ == 0)
    {
        reset_counter();
        return choose_s_minigame();
    }
    else
    {
        return 0;
    }
}

const int sminigames::get_counter()
{
    return counter_;
}

const int sminigames::reset_counter()
{
    counter_ = x0030;
}

int sminigames::choose_s_minigame()
{
    std::array<int, 4> values;
    std::array<int, 4> raw_values;
    int total_raw = 0;

    for (int &val : raw_values) 
    {
        val = std::uniform_int_distribution<int>(1, 100)(gen_); 
        total_raw += val; 
    }

    int total_adjusted = 0;
    for (int i = 0; i < 4; ++i) 
    {
        values[i] = (raw_values[i] * 100) / total_raw; 
        total_adjusted += values[i];
    }

    values[3] += (100 - total_adjusted);

    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4 - i - 1; ++j)  
        {
            if(values[j] > values[j + 1])  
            {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }

    int res = get_random_outcome(values);
    std::cout << res << "\n";
    if (res == 0)
    {
        return lucky_wheel();
    }
    if (res == 1)
    {  
        return wheel();
    }
    if (res == 2)
    {
        return dices();
    }
    if (res == 3)
    {
        return coinflip();
    }
    
    return -1;
}

int sminigames::get_random_outcome(std::array<int, 4> values)
{
    int sum = 100;
    int random = std::uniform_int_distribution<int>(1, 100)(gen_);
    int accumulated = 0;
    for(int i = 0; i < 4; ++i)
    {
        accumulated += values[i];
        if(random <= accumulated)
        {
            return i;
        }
    }
    return -1;
}

int sminigames::coinflip()
{
    return 0;
}

int sminigames::dices()
{
    return 0;
}

int sminigames::wheel()
{
    return 0;
}

int sminigames::lucky_wheel()
{
    return 0;
}
