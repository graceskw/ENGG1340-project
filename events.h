#ifndef EVENTS
#define EVENTS
#include "inventory.h"

struct EventProgress{
    bool event1;
    bool event2;
    bool event3;
    bool event4;
    bool event5;
    bool event6;
    bool event7;
};

bool event1();
bool event2(bool haveFirewood);     //in main.cpp: event2(inventory.firewood);
bool event3();
bool event4();
bool event5(Inventory inventory);

bool event6(Inventory inventory);
bool event7(Inventory inventory);

#endif