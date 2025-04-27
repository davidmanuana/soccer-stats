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

            case 3:
                sortByGoals(players, count);
                printf("\nTop Scorers:\n");
                Player *p = players;
                 for (int i = 0; i < 5 && i < count; i++, p++) {
                    printf("%d. %s - %d goals\n", i+1, p->name, p->goals);
            }
            break;
            case 4:
                savePlayers(players, count, "updated_stats.csv");
                 break;
        }
    } while (choice != 2);
    
    freePlayers(players);
    return 0;
}