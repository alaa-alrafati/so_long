*This project has been created as part of the 42 curriculum by aalrofat.*

# 🎮 so_long

## 📝 Description
The **so_long** project is a small 2D top-down game built in C using **MiniLibX**. The player moves through a 2D map, collects all required collectibles, and reaches the exit while avoiding obstacles and following strict map validation rules.

### 💡 What did I learn from the project
Working on **so_long** taught me how to build a basic game loop, handle keyboard events, and render 2D sprites and windows using MiniLibX. I also practiced validating map files carefully (walls, rectangular shape, required elements, and reachable paths), using the **Flood Fill** algorithm to verify path validity, managing memory cleanly, and following the Norminette.

### 🖼️ Gameplay & Output
![The Wizard Gameplay](./images/gameplay.jpg)
*2D map rendering with the player, collectibles, walls, and exit in MiniLibX.*[cite: 5]

![Terminal Move Counter & Win Message](./images/win_terminal.jpg)
*Move counter and win message (`CONGRATS.YOU WIN`) printed in the terminal.*[cite: 4]

## ⚙️ How to play
1. `cd so_long` (or navigate to the project directory)
2. `make` (compiles the game and creates `so_long`)
3. **Run the game** with a `.ber` map file:
   - `./so_long maps/map.ber`
4. **Controls**:
   - `W` / `A` / `S` / `D` or Arrow keys: Move the player.
   - `ESC` or `X` (close window button): Exit the game cleanly.
5. **Useful Makefile rules**:
   - `make clean` : Removes object files (`.o`).
   - `make fclean` : Removes object files and `so_long`.
   - `make re` : Rebuilds the game from scratch.

## 🛠️ Key Features
- **Map Parsing & Validation**: Checks file extensions, map layout, enclosed walls, player/exit/collectible counts, and valid movement paths.
- **Flood Fill Path Checking**: Uses a **Flood Fill** algorithm on a copy of the map starting from the player's position to ensure all collectibles and the exit are reachable before starting the game.
- **2D Rendering & Movement**: Draws tiles and sprites smoothly using MiniLibX and counts player moves.
- **Clean Resource Cleanup**: Frees allocated memory and destroys images/windows properly when quitting via `ESC` or the `X` close button.

## 🔗 Resources
- [MiniLibX Documentation & Guides](https://harm-smits.github.io/42docs/libs/minilibx)
- [Flood Fill Algorithm Overview](https://en.wikipedia.org/wiki/Flood_fill)
- [2D Grid & Pathfinding Basics](https://www.redblobgames.com/pathfinding/a-star/introduction.html)
- [42 Norminette](https://github.com/42School/norminette)

### 🤖 AI Usage
- **Game Sprites & Image Setup**: Helped generate player sprite ideas/assets and fine-tune game image settings so the visuals fit smoothly into the map.
- **Documentation**: Helped structure and polish this README so the instructions and game overview are clear and easy to follow.
