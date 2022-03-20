Team members:

Chiu Yu Cheung ()

So Ki Wai Grace (3035927116)

Game description:
You are Hestia. Yes, you share the same name with the Greek goddess of the hearth. Much like your divine counterpart, you yearn for a loving family. 

Your boyfriend Asher promised you a trip on your anniversary. Could it be…?

However, you have a secret. One that you have yet to tell your beloved. You gatherd up the courage to confide your deepest secret to the one you could depend your life on. Playing with the dice in your palm, you’ve made a decision.

Fate is in your hands.

Game rules:
The player types in certain commands to traverse the map (eg N to go north) and interact with objects (eg use item). When encountering events, the player rolls a dice to determine the follow-up action. Events may consists of tasks which the player needs to do (eg obtain and use a certain item) before they could complete the event. 

The ending depeneds on the number of tasks and events the player managed to complete throughout the game.

Features to be implemented:
1. Generation of random game sets or events
    - Game map:
        At the beginning of the game, the players would roll the dice to determine the set of map they would play. The events in each map would be the same, the only difference is the layout, and the possible sequence of events that the player would encounter.
    - Random events:
        Other than events in designated scenes and rooms, the sequence of events will be randomly distributed accross the map.
    - Random tasks:
        Designated items for tasks will be placed randomly throughout the map.

2. Data structures for storing game status
    - Structure: for items
    - Integer: outcome of dice rolling
    - String: Dialogues, scenes, events
    - 2D array: representation of map

3. Dynamic memory management
    - Inventory
    - Game map

4. File input/output (e.g., for loading/saving game status)
    - Record the process of the game:
        The number of tasks and events completed.

5. Program codes in multiple files
    - Main program
    - Commands:
        A file consisting all the possible commands will be called whenever the player types in a command. If it exists in the file, the corresponding functions/codes will be called and executed.
    - Scenes:
        The codes for the beginning and ending scenes will be written separate files.
    - Dice rolling
    - Game maps