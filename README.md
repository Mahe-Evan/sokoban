# Sokoban

Sokoban is a classic puzzle game where the player pushes crates or boxes onto designated storage locations within a maze. This version is implemented in C using the `ncurses` library to create a terminal-based UI.

---

## 🧩 Goal of the Game

In Sokoban, you control a player (`P`) in a warehouse filled with boxes (`X`) and target storage locations (`O`).

**Objective:**  
Push all the boxes onto the storage locations.

### Game Rules:
- You can only **push** one box at a time.
- You **cannot pull** boxes.
- Boxes **cannot be pushed into walls** (`#`) or other boxes.
- You win when **all boxes are on storage locations**.

---

## 📦 Installing ncurses

This game uses the `ncurses` library. You must install it before compiling.

### Ubuntu / Debian

```sh
sudo apt update
sudo apt install libncurses5-dev libncursesw5-dev
```
## Launch the programm.

Clone the repository and do the `make` command. After the compilation do `./sokoban <path_to_the_map>` and enjoy the game.
