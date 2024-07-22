# IslandFactorySimulator

Project Description

This project was developed as part of the Object-Oriented Programming course in the 2nd year of the Bachelor's degree in Computer Engineering. The goal was to create a simulation game focused on construction and development, where a player must industrialize and expand a given island.

Project Objective

The aim is to build a C++ simulator/game (single-player) of construction and development. The player is granted the concession of an island and must develop it by industrializing and building a factory complex. The geography of the island consists of a set of adjacent zones, with various types of zones possible. The player can construct buildings, which will be placed in the zones chosen by the player (maximum one building per zone). The player will manage a team of workers, including various types of workers. The player can move workers around the island to perform their tasks. Throughout the game, resources produced on the island will be used. The game is controlled by actions specified by the player through written commands.

The game progresses in days, with a certain number of actions allowed per day. Certain events occur automatically at the beginning of the day and others at the end of the day. The player's specified actions occur in the middle of the day (after the beginning-of-day events but before the end-of-day events). The game ends either when the player chooses or when the player is unable to continue due to a loss of all resources/workers. The game's score is the wealth accumulated by the player when the game ends.
Project Structure

The project is structured with a total of 32 classes, the main ones being:

    Ilha: Manages all game logic related to the island, including interactions with different zones.
    Zona: Contains information about resources, buildings, and workers in a specific zone of the island.
    Edifício: Stores data about buildings, such as storage capacity and operational status.
    Trabalhador: Holds details about workers, such as ID, hire dates, among others.
    GameData: Acts as an intermediary between the interface and the island, managing game logic and delegating functions to the Ilha class.
    Interface: Responsible for user interaction, receiving commands, and requesting actions from GameData.

Concepts Used

    Encapsulation: Each class is responsible for its own information and methods, ensuring that data is manipulated in a controlled manner.
    Inheritance: Some classes, such as different types of zones and resources, inherit properties and behaviors from base classes, promoting code reuse.
    Polymorphism: Implemented, for example, in the Zona class, where the “despede” function behaves differently depending on the type of zone and worker, such as Loggers and Miners.

Game Operation

    GameData: Initialized at the start of the program, this object manages almost all game logic and is stored in the Interface class.
    Interface: Interacts with the user, receiving commands and delegating actions to GameData. It is also responsible for save, load, and delete functions, as well as displaying the island.
    Ilha and Zona: The Ilha class controls activities within the zones, such as selling buildings and adding workers, while the Zona class manages specific resources and buildings.

This project allowed for the practical application of advanced Object-Oriented Programming concepts, resulting in an organized and modular code, facilitating future maintenance and expansion.
