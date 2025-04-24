#include <stdio.h>
#include "player.h"

int main() {
    int count = 0;
    Player* players = loadPlayers("players.csv", &count);
    
    if (!players) {
        return 1;
    }
    
    printf("Loaded %d players\n", count);
    
    freePlayers(players);
    return 0;
}