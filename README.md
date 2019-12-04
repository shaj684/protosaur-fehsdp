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

Day 6 (11/30/19)
	- Random integer function to determine obstacle frame
	- Added buzzer when game over
	- Determined max dino jump height of 80 pixel
	- Clear screen after each calculation
	- Determined new gravity constant based on Chromedino observations

Day 7 (12/1/19)
	- Drew the game score numbers and "Game Over" for the game score in Excel
	- Draw random cactus (frames 0, 1, 2)


Day 8 (12/2/19)
	- Figured out the positioning of the "Game Over," score numbers, and replay button
	- FEHIcon for the replay button
	- Check to see if the player wants to replay
	- Input code into Qt Creater and fixed errors
	- Fixed collision equation (switch case with three cactus)
	- Determined that a max of three cactus can be on the screen
	- Keep the cactus frame throughout
	- Move cactus left, if negative, send cactus back to origin, check frames
	- Determine the dino frame depending on the jump loop condition

Day 9 (12/3/19)
	- Updated the visual studio code with error-free Qt code 
	- Deleted the "onGround variable" since we have "jumping"
	- Function call "Game Over"
	- Velocity for dino
	- Score and high score
	- Title and credits
	- Documentation of images and video
	- Width of the replay button

Day 10 (12/4/19)
	- Checking cactus creation
	- Clouds
	- Noise at checkpoints
	- Gravitational force
	- Score
	- Replay / Menu
		- Display instructions
		- check positions
	- 