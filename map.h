#ifndef MAP
#define MAP
struct Position{
	int roomnum;
	int x;
	int y;
};

struct SceneChange{
	bool change;
	char direction;
};

void generatemap (Position &player, std::vector<std::vector<char>> &map);

Position Movement(string input, Position player, std::vector<std::vector<char>> map, SceneChange &sceneChange);

void checkScene(Position &player, SceneChange sceneChange);

void Printmap(Position player, std::vector<std::vector<char>> map);

#endif