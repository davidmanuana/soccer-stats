#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char name[50];
    char team[50];
    char position[20];
    int goals;
    int assists;
} Player;


// Function declaration
Player* loadPlayers(const char* filename, int* count);
void freePlayers(Player* players);
void showMenu();
void searchPlayer(Player* players, int count);
void sortByGoals(Player* players, int count);
void savePlayers(Player* players, int count, const char* filename);

#endif