# Bubble Pop Game

A fun and simple arcade game built using **C++17** and the **Raylib** library. Pop as many bubbles as you can before the timer runs out!

## 🎮 Features

- **Dynamic Gameplay**: Bubbles spawn at random locations and bounce realistically off screen boundaries and each other.
- **Physics-Based Movement**: Implemented bubble-to-bubble collision using elastic collision physics.
- **Scoring System**: Earn 1 point for every bubble you click and "pop".
- **Timed Challenges**: Each round lasts for 30 seconds. Try to beat your high score!
- **State Management**: Smooth transitions between Title, Gameplay, and End screens.

## Screenshot preview
<img width="800" height="480" alt="螢幕擷取畫面 2026-04-18 210824" src="https://github.com/user-attachments/assets/da94a588-73d9-40ee-aca1-cdf506cd3e45" />

<img width="800" height="480" alt="螢幕擷取畫面 2026-04-18 210838" src="https://github.com/user-attachments/assets/633de1ff-06c7-4335-9b55-ac1e1bd72396" />

<img width="800" height="480" alt="螢幕擷取畫面 2026-04-18 210846" src="https://github.com/user-attachments/assets/b37dd7f4-0b47-4b46-9da5-5516209b1023" />

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
