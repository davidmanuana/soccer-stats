#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

Player* loadPlayers(const char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        return NULL;
    }

    Player* players = malloc(10 * sizeof(Player)); // Start with space for 10 players
    *count = 0;
    char line[200];
    
    // Skip header line
    fgets(line, sizeof(line), file);
    
    while (fgets(line, sizeof(line), file) && *count < 10) {
        // Simple parsing - assumes format is exactly name,team,position,goals,assists
        sscanf(line, "%49[^,],%49[^,],%19[^,],%d,%d",
               players[*count].name,
               players[*count].team,
               players[*count].position,
               &players[*count].goals,
               &players[*count].assists);
        
        (*count)++;
    }
    
    fclose(file);
    return players;
}

void freePlayers(Player* players) {
    free(players);
}

void showMenu() {
    printf("\n1. Search player\n");
    printf("2. Exit\n");
    printf("Choose option: ");
}
void searchPlayer(Player* players, int count) {
    char name[50];
    printf("Enter player name: ");
    scanf(" %49[^\n]", name);
    
    for (int i = 0; i < count; i++) {
        if (strstr(players[i].name, name) != NULL) {
            printf("\nPlayer found:\n");
            printf("Name: %s\n", players[i].name);
            printf("Team: %s\n", players[i].team);
            printf("Position: %s\n", players[i].position);
            printf("Goals: %d, Assists: %d\n", players[i].goals, players[i].assists);
            return;
        }
    }
    printf("Player not found\n");
}