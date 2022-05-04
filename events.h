#ifndef EVENTS
#define EVENTS
#include <vector>
#include "inventory.h"

struct EventProgress{
    bool event1;
    bool event2;
    bool event3;
    bool event4;
    bool event5;
    bool event6;
    bool event7;
    int events=0;
};

bool event1(EventProgress progress);
bool event2(vector <Inventory> inventory, EventProgress progress);
bool event3(EventProgress progress);
bool event4(EventProgress progress);
bool event5(vector <Inventory> inventory, EventProgress progress);

bool event6(vector <Inventory> inventory, EventProgress progress);
bool event7(vector <Inventory> inventory, EventProgress progress);

// int checkEventLocation(Position player);

#endif