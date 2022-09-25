#include <stdlib.h>
#include <stdio.h>
#include "machine.h"
#include "player.h"
#include "combination.h"

struct Machine{
    CombinationPtr* winning_combinations;
    int bet;
};


MachinePtr createMachine(CombinationPtr* winning_combinations, int bet){
    MachinePtr machine = malloc(sizeof *machine);
    if(machine){
        machine -> winning_combinations = winning_combinations;
        machine  -> bet = bet;
    }
    return machine;
}

CombinationPtr roll(MachinePtr machine, PlayerPtr player){
    if (!hasEnoughBalance(player, machine->bet))
    {
        // not enough balance
        printf("\nNot enough balance");
        exit(0);
    }

    changeBalance(player, -(machine->bet));
    
    CombinationPtr combination = createRandomCombination();
    if (isJackpot(combination))
    {
        printf("\nWon jackpot");
        exit(0);
    }

    changePlayerBalance(machine, player, combination);

    return combination;
}

// returns player's new balance
int changePlayerBalance(MachinePtr machine, PlayerPtr player, CombinationPtr combination){
    int prize = getRollPrize(machine, combination);

    return changeBalance(player, prize);
}

int getRollPrize(MachinePtr machine, CombinationPtr combination){
    for (size_t i = 0; i < COMBINATIONS_COUNT; i++)
    {
        if (equals(combination, machine -> winning_combinations[i]))
        {
            return getPrize(machine -> winning_combinations[i]);
        }
    }
    return 0;
}

void destroyMachine(MachinePtr machine){

}