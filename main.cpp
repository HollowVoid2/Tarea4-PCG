#include <iostream>
#include <vector>
#include "generator/graph_generator.h"
#include "utils/room.h"
#include "utils/room_type.h"

std::string roomTypeToString(RoomType type) {
    switch (type) {
        case RoomType::Start: return "Inicio";
        case RoomType::Combat: return "Combate";
        case RoomType::Treasure: return "Tesoro";
        case RoomType::Shop: return "Tienda";
        case RoomType::Rest: return "Descanso";
        case RoomType::Boss: return "Jefe";
        default: return "Desconocido";
    }
}

int main() {
    GraphGenerator generator;
    std::vector<Room> level = generator.generateLevel();

    std::cout << "=== Grafo del Nivel Generado ===\n";
    for (const Room& room : level) {
        std::cout << "Sala ID " << room.id << " [" << roomTypeToString(room.type) << "] -> ";
        for (int conn : room.connections) {
            std::cout << conn << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
