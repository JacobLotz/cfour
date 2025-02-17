# cfour
Connect Four is a two-player strategy game where the goal is to be the first to connect four of your colored discs in a row, either horizontally, vertically, or diagonally.

## Game Setup:
Connect Four is played on a grid with seven columns and six rows, though some variations exist. Each player has a set of colored discs, usually red or yellow. The player and the computer take turns dropping a disc into one of the seven columns. Once dropped, the disc falls to the lowest available space in that column.

### Winning the Game:
A player wins by aligning four of their discs in a row, whether horizontally in a straight line, vertically in a stacked column, or diagonally with a positive or negative gradient.

### Game End:
If a player connects four first, the player wins immediately. However, if the grid fills up completely without a winner, the game ends in a draw.

## Running this code
To play the game, you can clone this repository and install the game using
```
bash deploy.sh
```

This will create a `build` folder in which the game is compiled. In this folder, the game can be played by running the command
```
./cfour
```

## Requirements
To compile the code using `deploy.sh` you need
- `g++`
- `cmake`
- `make`

You can install these with
```
sudo apt install g++ cmake make
```

This code is only tested on `linux-mint 21.2`.