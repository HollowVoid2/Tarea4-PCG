#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "room_type.h"

struct Room {
    int id;
    RoomType type;
    std::vector<int> connections;

    Room(int id, RoomType type = RoomType::Unknown)
        : id(id), type(type) {}
};

#endif