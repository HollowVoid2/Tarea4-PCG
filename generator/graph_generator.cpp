#include "graph_generator.h"
#include <random>
#include <iostream>
#include <unordered_map>
#include <algorithm>

GraphGenerator::GraphGenerator(int minR, int maxR)
    : minRooms(minR), maxRooms(maxR), currentID(0) {}

void GraphGenerator::addRoom(RoomType type) {
    rooms.emplace_back(currentID++, type);
}

void GraphGenerator::connectRooms(int fromID, int toID) {
    rooms[fromID].connections.push_back(toID);
}

std::vector<Room> GraphGenerator::generateLevel() {
    int totalRooms = rand() % (maxRooms - minRooms + 1) + minRooms;

    // Regla 1: Secuencia básica
    addRoom(RoomType::Start);     // 0
    addRoom(RoomType::Combat);    // 1
    addRoom(RoomType::Combat);    // 2
    addRoom(RoomType::Combat);    // 3
    addRoom(RoomType::Boss);      // 4

    connectRooms(0, 1);
    connectRooms(1, 2);
    connectRooms(2, 3);
    connectRooms(3, 4);

    // Reglas adicionales
    placeShop();
    placeOptionalRoom();
    placeTreasureIfNeeded();
    distributeEnemies();

    return rooms;
}

void GraphGenerator::placeShop() {
    int position = std::min(5, std::max(2, rand() % 4 + 2));
    if (position < rooms.size()) {
        rooms[position].type = RoomType::Shop;
    } else {
        addRoom(RoomType::Shop);
        connectRooms(2, currentID - 1);
    }
}

void GraphGenerator::placeOptionalRoom() {
    addRoom(RoomType::Rest);
    connectRooms(1, currentID - 1); // Conectar desde la segunda sala
}

void GraphGenerator::placeTreasureIfNeeded() {
    if (rooms.size() >= 6) {
        addRoom(RoomType::Treasure);
        connectRooms(3, currentID - 1); // Después de combate
    }
}

void GraphGenerator::distributeEnemies() {
    for (Room& r : rooms) {
        if (r.type == RoomType::Combat) {
            // Este es un marcador lógico, no se muestra directamente
            // En implementación completa, podrías guardar cantidad o tipos de enemigos
        }
    }
}
