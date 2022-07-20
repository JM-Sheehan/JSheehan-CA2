
# :wave: CA2 Game Prototype
## 🤓 Practical/Assignment 2 overview and learning outcomes

The goal of this lab is to:
1. Use multiple programming paradigms appropriate to the game being developed such Data Driven Development.
2. Use a suitable game framework and integrate additional libraries necessary for physics, networking, AI and sound as required.



## Notes on Carrying-out this and the following assignment
* In this module students can carry out their practials and assignment independently, however, we for some assignments and practicals the following is permitted:
 * **Cooperative learning/peer tutoring (i.e. Pair-programming for practicals and team-based approaches for some assignments).**
* Please note that students will be graded independently and interviews (probably online) will be used to help assess students.

## Notes on Grading
According to the module discriptor we use the following for grading for all of the assignments in this module:
* <40%: Inability to design and implement a game. Inability to develop bespoke tools for managing game assets as per learning outcome (2). Inability to critically assess techniques for managing game resources.
* 40-49%: Ability to design and implement a stand-alone game. Ability to develop bespoke tools for managing game assets as per learning outcome (2). Ability to critically assess techniques for managing game resources.
* 50-59%: All the above and in addition, correctly choose appropriate data structures, algorithms and patterns.
* 60-69%: All of the above, in addition implement all required features consistently well.
* 70%+: All previous to an excellent level. Starts to extend game and framework with features such as resource caching, goal-based behaviour, etc.

I would like to point out **correctly choose appropriate data structures, algorithms and patterns.**

## Recap on what you've done so far
* So far you have partially completed this assignment by doing the ECS practical and its tasks; this will be taken into account in the grading.
* You have the means to create different types of entities by adding existing components.


### Background to the Tasks:
* You have the bones of a game engine but its missing some features. While we have components for rendering sprites, we do not have animated sprites.
* We have a simple map implementation but we had a better approach in the data driven assignment, where we used a JSON file to store the map data. We need to use that here again!
#### Main Aims
* Refactor the code: The code is not clean! It needs refactoring. 
* Update sprite component to perform animation. Write code that tests/uses this e.g. in main.cpp or elsewhere.
* Include code that checks collisions with tiles.
* Add two additional components for any other purpose than what is outlines here.


### Task/Assignment main steps
1. Refactor the code: So far most of the code is in the headers i.e. in the class definitions. Move this code, where possible to the .cpp counter parts. This applies to components and elsewhere.
2. Update sprite component to perform animation. Write code that tests/uses this e.g. in main.cpp or elsewhere.
3. Tiling is only rudimentary. Use the JSON implementation at least for the tiling. Use your tile editor to design new maps and test them out in your new implementation of code in this assignment.
4. Collision. There is currently no collision between the player and tiles. Write code in a suitable location (e.g. component) that will check if a tile is grass (moveable) or stone/wall (impassible). Don't permit the character to move in the impassible case.
5. Write two new components that inherit from the main component that add features that you would like to include. Write code that tests/uses these features.
6. Use either a JSON file or otherwise to read in data that will implement an entity. Write code that tests this.
7. Document all your work/additions in a new markdown document titled AssignmentDocumentation.md.


