GROUP 155
Team members:

Chiu Yu Cheung (3035928964)

So Ki Wai Grace (3035927116)

Problem statement:
Our game is loosely inspired by a short story that was written as an assignment in secondary school. We thought it would be interesting to make the story into a game, and share it through an interactive way, hence the text-based interactive mystery story chosen as our topic. Our game lets the player to become the protagonist and decide on her fate through encoutering different events and achieve different endings based on their actions, expanding the story with twist and turns.

Game description:
You are Hestia. Yes, you share the same name with the Greek goddess of the hearth. Much like your divine counterpart, you yearn for a loving family. 

Your boyfriend Asher promised you a trip on your anniversary. Could it be…?

However, you have a secret. One that you have yet to tell your beloved. You gathered up the courage to confide your deepest secret to the one you could depend your life on. Playing with the dice in your palm, you’ve made a decision.

Fate is in your hands.

Game rules:
The player types in certain commands to traverse the map (eg w to go up) and interact with objects (eg dice). When encountering events, the player rolls a dice that determines the follow-up action. Events may consist of tasks which the player needs to do (eg obtain and use a certain item) before they could complete the event. 

The ending depends on the number of tasks and events the player managed to complete throughout the game.

Features to be implemented:
1. Generation of random game sets or events
    - Dice rolling: 
        The outcome of the dice is randomised with current time as the seed.

2. Data structures for storing game status
    - struct: 
        EventProgress:
            The bool variables for each event stores true if the event is complete, false if not. A counter of the number of completed events is also included.
        Position:
            Stores the current room number, x and y coordinates of the player
        SceneChange:
             is used to store 
    - vector: 
        map:
            A map is stored in a 2D vector
        Inventory
            A vector with the type Inventory, which is a class
    - class: Inventory
            A class to store the name of a item, and the quantity

3. Dynamic memory management
    - Inventory
        Items are pushed to the vector if the player picks them up

4. File input/output (e.g., for loading/saving game status)
    - List of commands (commands.txt): 
        Stores the list of valid commands the player can input. When player types help, the contents in commands.txt will be outputted.
    - Record the process of the game (_CERTIFICATE.txt):
        The number of events completed is stored in _CERTIFICATE.txt, which can be accessed after the game is completed.

5. Program codes in multiple files
    List of files included (in alphabetical order):
    - .cpp
        beginning.cpp
        commands.cpp
        ending.cpp
        events.cpp
        main.cpp
        map.cpp
        roll.cpp
    - .h
        commands.h
        ending.h
        events.h
        inventory.h
        map.h
        roll.h
        scenes.h
    - .txt
        commands.txt
        _CERTIFICATE.txt
