# protosaur-fehsdp
Protosaur, the game. Developed for OSU's FEH SDP 

# Pseudocode:

1. Display selection menu
    a. Theme options
    b. Past Scores + Names
    c.Play Button
    d.Game theme sound
2. Hit the play button
3. Sleep
4. Display initial platform, given gametheme option
5. Start animation of the platform
6. Check for input + collision conditions
7. Update the platform
8. Return to step 3
9. If jump button is pressed, move dino up
10. If collision is true, display Game Over + Score + Name + High score+ noise
11. Replay option, return to 1


# ----------------------------------
Day 0 (11/22/19)
    - Creating project

Day 1 (11/25/19)
    - Deciding game structure
    - Reviewed PROTEUS hardware
	- Asked Drew for advice on animation


Day 2 (11/26/19)
    - Created player classes and member variables
    - Found Proteus documentation that can be implemented
    - Initialized Git Repository
	- Excel mock-ups for Dino and Cactus
	- Choose colors for objects on PROTEUS screen
	- Determined constants for gravity, sleep, and position of dino

Day 3 (11/27/19)
    - Draw four dino frames 
	- Draw three cactus frames
    - Collision function
    - Determined collision circle radius + centerpoint
	- Excel mock-up for cloud

Day 5 (11/29/19)
	- Determined Dino and Obstacle draw arguments (lower left corner)
	- Created visual representation of PROTEUS 320 x 240 on Excel
	- Wrote code for check collision