#include "combination.h"
#include "player.h"

#define COMBINATIONS_COUNT 11

typedef struct Machine* MachinePtr;

MachinePtr createMachine(CombinationPtr winning_combinations[], int bet);

CombinationPtr roll(MachinePtr machine, PlayerPtr player);

int getRollPrize(MachinePtr machine, CombinationPtr combination);

int changePlayerBalance(MachinePtr machine, PlayerPtr player, CombinationPtr combination);

void destroyMachine(MachinePtr machine);