#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    char name[50];
    char team[50];
    char position[20];
    int goals;
    int assists;
} Player;

Player* loadPlayers(const char* filename, int* count);
void freePlayers(Player* players);

#endif