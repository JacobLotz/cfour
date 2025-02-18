# C-4
```
    _____        _  _    
   / ____|      | || |   
  | |   ______  | || |_  
  | |  |______| |__   _| 
  | |____          | |   
   \_____|         |_|   

```
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

## Playing the game


The grid looks like this:

```
---------------------
 0  0  0  0  0  0  0 
 0  0  0  0  0  0  0 
 0  0  0  0  0  0  0 
 0  0  0  0  0  0  0 
 0  0  0  0  0  0  0 
 0  0  0  0  0  0  0 
---------------------
```

Here

 - -1 indicates that this location is filled by a fiche of me; 
 -  0 means it empty;
 -  1 means that one of your fiches fills this spot.

If it is your turn you can play your piece by picking a column between 0-6 and returning your answer to the command line. The computer plays automatically.




## Testing this code
After the code is compiled using `deploy.sh`, it is tested directly. To enforce testing manually one can run

```
./cfour --test
```

or

```
make test
```
It should pass all tests.

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

## Source code
The source code of this project can be found in the folder `src`. The connect four grid, the computer player and the human player are defined in separate classes in separate files.


## To do

 - Streamline CFOUR_Grid::Win()
 - More elegant grid
