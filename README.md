[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9845079&assignment_repo_type=AssignmentRepo)
 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Project 1

 > Journey Game

 > Authors: [Felix Diaz](https://github.com/FelixMDM), [Paul Yokota](https://github.com/phyokota), [Kathalinne Bella Gonzalez](https://github.com/kathalinne), [Garman Zhen](https://github.com/Garman18)

 > You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list and start thinking about the features you will implement. If you want to propose your own original idea, you will have to contact your instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). The project work should be divided almost equally among team members. You can of course help each other, but it needs to be clear who will be responsible for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings.

 > ## Expectations
 > * The backend of your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * **Each member of the group must actively participate in the Github Project board, writing unit tests, and reviewing commited code.**
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two to three scrum/check-in meetings with your lab TA/reader at different times in addition to the final demo.

## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include:
 > * Why is it important or interesting to you?
 > * - We think that the idea of a text-based RPG game is fun & provides a good platform for creativity. Additionally, it lends itself well to scalablility. 
 > 
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 > * - For the most part C++ will be used as the porject will strictly be text-based
 > 
 > * What will be the input/output of your project?
 > * - Every iteration of the program the user will be prompted with a set of options ranging from (A-N) that will determine the direction of the user 
 > 
 > * What are the features that the project provides?
 > * - Features 
 > * - Character Selection (different storylines based on what you choose)
 > * - Quests (To get rewards that will help you become stronger)
 > * - Quests can be like beat x monsters potentially
 > * - The final goal is to be able to beat some boss (turn-based warfare)
 > * - 3 central locations (Hub of sorts, somewhere to grind xp, a boss room that only opens up after you reach a certain level)
 > * - XP system/Leveling system
 > * - Character Types - Melee/Range/eMag
 > * - Game ending screen - either a Victory Screen or a Death Screen
 > * - Have to restart from the beginning - all or nothing
 > 
 > This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 
 > 
 > You also need to set up an empty project board using GitHub projects (board view). Make sure you add the board under your project repository. You should also have a Product Backlog and In testing columns added.


 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 > Link to UML Diagram: https://drive.google.com/file/d/173Na_coSmMmaJZdC1Mhe1tWamCqH6ojC/view?usp=sharing
 > 
 
 > The class diagram contains 6 main classes that each contain their own set of derived classes. 
 > The 6 main classes that will be implemented:
 > 1. Player class
 >   * The purpose of the player class is to track and update the statistics of the players progress as they traverse through the game.
 >   * There are three main subclasses of Player class which include
 >      * Melee - Sword
 >      * Ranged - Archer
 >      * Mage - Magic
 > 2. Inventory class
 >   * The purpose of the inventory class is to store a list of items that the player obtains throughout the game.
 >      * OpenInventory - Opens current inventory and displays current items
 > 3. Inventory Actions class
 >    * There are a couple of specific actions the user can perform in their inventory
 >      * ListInventory - List items in current inventory (after changes have been made)
 >      * SwapItems - swaps item for another inventory item
 >      * DropItems - removes item from inventory
 >      * AddItem - adds item to inventory
 >      * CurrItem - displays the current item the player is holding
 >      * SwapItems - swaps item for another inventory item
 > 4. Collectable Items class
 >    * Three private variables: supplies, food, weapons
 >       * get_Supplies
 >       * get_Weapon
 >       * get_Food
 > 5. Enemy class
 >   * The purpose of the enemy class is to serve as a virtual class from which enemies of different typings can derive the core variables such as attack and health from
 >   * There are two main types of enemy
 >      * Regular enemy - easier enemy to defeat
 >      * Boss enemy - harder enemy to defeat
 > 6. NPC class
 >   * The purpose of the NPC class is to allow the user to play through artificial interactions with in game characters which can prove side quests and allow the user to progress through the game.
 >   * Some interactions include
 >      * Shop Keep - allows for user to purchase items from NPC
 > 7. Location class
 >   * The purpose of the location class is to provide a way for the user to understand their progression through traversing through different landscapes along their journey. It simply contains the name and description for certain locations.
 >   * In locations, NPC's and enemies can be found.
 > 8. Main Menu Class
 >   * the purpose of the main menu class is to provide a user interface for the player to interact with as they tweak options and how the start of the game will play out.
 


 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 > 
 > Link to updated UML Diagram:  https://drive.google.com/file/d/173Na_coSmMmaJZdC1Mhe1tWamCqH6ojC/view?usp=sharing
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.



 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application

Title: ![Screenshot 2023-03-17 152255](https://user-images.githubusercontent.com/102873027/226064267-043b3ef5-cd0c-4bf8-bb39-9684e29a7451.png)

Option a: ![Screenshot 2023-03-17 152330](https://user-images.githubusercontent.com/102873027/226064367-2ca23525-ea8c-44fb-a413-8c4d2fb4fbda.png)
![Screenshot 2023-03-17 153109](https://user-images.githubusercontent.com/102873027/226064416-283f03fb-ccc4-4e83-9970-ed2d9a845cad.png)

Option b: ![Uploading Screenshot 2023-03-17 153109.png…]()

Option c: ![Screenshot 2023-03-17 153010](https://user-images.githubusercontent.com/102873027/226064481-8cca36ac-d3dd-4350-a8b9-d91bcf1bdc66.png)

Option q: ![Screenshot 2023-03-17 153137](https://user-images.githubusercontent.com/102873027/226064523-e780a78a-72ff-4fc3-93a1-563d95d107c1.png)

Playing: ![Screenshot 2023-03-17 152330](https://user-images.githubusercontent.com/102873027/226064555-d5b248a7-b10d-4543-98bb-f9b4cb63deba.png)



 ## Installation/Usage
https://docs.google.com/document/d/1v1SaDAsEmtJYq1Bt84bI-QVGFxLP125sPUgKh-JKPSo/edit?usp=sharing 
 ## Testing
 Each project member was in charge of implementing their own unit tests throughout each sprint. Individual test files of each class (i.e. Inventory, Player, Location, Enemy, etc) can be found under test folder. Our approach to testing the program was by running the executable code very frequently to make sure eachimplementationn of code was working as it should. For example, validating input in main.cpp.
