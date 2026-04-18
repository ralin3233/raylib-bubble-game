# Bubble Pop Game

A fun and simple arcade game built using **C++17** and the **Raylib** library. Pop as many bubbles as you can before the timer runs out!

## 🎮 Features

- **Dynamic Gameplay**: Bubbles spawn at random locations and bounce realistically off screen boundaries and each other.
- **Physics-Based Movement**: Implemented bubble-to-bubble collision using elastic collision physics.
- **Scoring System**: Earn 1 point for every bubble you click and "pop".
- **Timed Challenges**: Each round lasts for 30 seconds. Try to beat your high score!
- **State Management**: Smooth transitions between Title, Gameplay, and End screens.

## ⌨️ Controls

- **Mouse (Left Click)**: Pop bubbles.
- **Enter**:
  - **Title Screen**: Start the game.
  - **Gameplay**: Immediately end the game (Go to Game Over).
  - **Ending Screen**: Return to the Title screen.

## 🛠️ Technical Stack

- **Language**: C++17
- **Graphics Library**: Raylib 5.5
- **Build System**: CMake 3.14+


## 📁 Project Structure

- `src/`: Source code (`main.cpp`, `bubble.cpp`, `bubble.h`).
- `include/`: Header files (Raylib dependencies).
- `resources/`: Assets and other game data.
- `CMakeLists.txt`: Build configuration.
