#include <stdio.h>
#include "player.h"

// Main soccer stats program
// Handles menu and user input
int main() {
    int count = 0;
    Player* players = loadPlayers("players.csv", &count);
    
    if (!players || count == 0) {
        printf("Failed to load player data\n");
        return 1;
    }

    int choice;
    do {
        showMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // Search player
                searchPlayer(players, count);
                break;
                
            case 2: // Show top scorers
                sortByGoals(players, count);
                printf("\nTop 5 Scorers:\n");
                Player *p = players;
                for (int i = 0; i < 5 && i < count; i++, p++) {
                    printf("%d. %s - %d goals\n", i+1, p->name, p->goals);
                }
                break;
                
            case 3: // Save to file
                savePlayers(players, count, "updated_stats.csv");
                break;
                
            case 4: // Add new player 
                addPlayer(&players, &count);
                break;
                
            case 5: 
                printf("Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice\n");
        }
        
        // Clear input buffer to prevent menu issues
        while (getchar() != '\n');
        
    } while (choice != 5); 
    
    freePlayers(players);
    return 0;
}