#ifndef GRAPH_GENERATOR_H
#define GRAPH_GENERATOR_H

#include <vector>
#include "room.h"

class GraphGenerator {
public:
    GraphGenerator(int minRooms = 8, int maxRooms = 12);
    std::vector<Room> generateLevel();

private:
    int minRooms;
    int maxRooms;
    int currentID;

    std::vector<Room> rooms;

    void addRoom(RoomType type);
    void connectRooms(int fromID, int toID);
    void enforceRules();
    void placeShop();
    void placeOptionalRoom();
    void placeTreasureIfNeeded();
    void distributeEnemies();
};

#endif // GRAPH_GENERATOR_H
