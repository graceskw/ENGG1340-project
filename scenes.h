#ifndef SCENES
#define SCENES

#include <vector>
#include "events.h"
#include "map.h"

void beginning(Position &player, std::vector<std::vector<char>> &map, SceneChange &sceneChange);

void ending1();
void ending2();
void final(EventProgress eventprogress);

#endif