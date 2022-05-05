// events.h
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

bool event1(EventProgress eventProgress);
bool event2(std::vector <Inventory> inventory, EventProgress eventProgress);
bool event3(EventProgress eventProgress);
bool event4(EventProgress eventProgress);
bool event5(std::vector <Inventory> inventory, EventProgress eventProgress);

bool event6(std::vector <Inventory> &inventory, EventProgress eventProgress);
bool event7(std::vector <Inventory> &inventory, EventProgress eventProgress);

#endif