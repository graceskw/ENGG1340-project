#ifndef COMMANDS
#define COMMANDS

#include <vector>
#include "events.h"
#include "inventory.h"
#include "map.h"

void commands(Position &player, std::vector<std::vector<char>> map, SceneChange &sceneChange, std::vector<Inventory> inventory, EventProgress eventProgress);

#endif