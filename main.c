#include <stdio.h>
#include "player.h"

int main() {
    int count = 0;
    Player* players = loadPlayers("players.csv", &count);
    
    if (!players) {
        return 1;
    }
    
    int choice;
    do {
        showMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                searchPlayer(players, count);
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 2);
    
    freePlayers(players);
    return 0;
}