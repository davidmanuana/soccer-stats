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
    printf("3. Show top scorers\n");
    printf("4. Save to file\n");
    printf("Choose option: \n");
}
void searchPlayer(Player* players, int count) {
    char name[50];
    printf("Enter player name: ");
    scanf(" %49[^\n]", name);
    
    Player *p = players; // Pointer to first element
    int found = 0;
    
    while (p < players + count) { // Pointer comparison
        if (strstr(p->name, name) != NULL) {
            printf("\nPlayer found:\n");
            printf("Name: %s\n", p->name);
            printf("Team: %s\n", p->team);
            printf("Position: %s\n", p->position);
            printf("Goals: %d, Assists: %d\n", p->goals, p->assists);
            found = 1;
        }
        p++; // Pointer increment
    }
    
    if (!found) {
        printf("Player not found\n");
    }
}
void sortByGoals(Player* players, int count) {
    Player *p, *end;
    for (end = players + count - 1; end > players; end--) {
        for (p = players; p < end; p++) {
            if (p->goals < (p+1)->goals) {
                Player temp = *p;
                *p = *(p+1);
                *(p+1) = temp;
            }
        }
    }
}
void savePlayers(Player* players, int count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error creating file\n");
        return;
    }
    
    fprintf(file, "Name,Team,Position,Goals,Assists\n");
    Player *p = players;
    while (p < players + count) {
        fprintf(file, "%s,%s,%s,%d,%d\n",
               p->name, p->team, p->position,
               p->goals, p->assists);
        p++;
    }
    
    fclose(file);
    printf("Saved %d players to %s\n", count, filename);
}