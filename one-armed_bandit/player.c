#include <stdbool.h>
#include <stdlib.h>
#include "player.h"

struct Player{
    int balance;
};

PlayerPtr createPlayer(int balance){
    PlayerPtr player = malloc(sizeof *player);
    if (player)
    {
        player -> balance = balance;
    }

    return player;
}

bool hasEnoughBalance(PlayerPtr player, int rollPrice){
    return player -> balance >= rollPrice;
}

int changeBalance(PlayerPtr player, int value){
    return player -> balance += value;
}

int getBalance(PlayerPtr player){
    return player->balance;
}