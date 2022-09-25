typedef struct Player* PlayerPtr;

PlayerPtr createPlayer(int balance);

bool hasEnoughBalance(PlayerPtr player, int rollPrice);

int changeBalance(PlayerPtr player, int value);

int getBalance(PlayerPtr player);

void destroyPlayer(PlayerPtr player);