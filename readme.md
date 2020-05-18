# Scrabble Solver Projet
The aim of this project was to program an automatic Scrabble player capable of determining the move with the most points using the [GADDAG](https://en.wikipedia.org/wiki/GADDAG) data structure.

## Usage
Clone or download and unzip the archive. Compiling this repository is done using the `premake4` command. You must therefore verify that it is installed. For that, you can use ```apt policy premake4``` or ``` dpkg -l premake4```. Otherwise, Premake packages are available for most linux distributions.

To compile the program type:
```bash
premake4 gmake
make
```
To launch it type:
```
./bin/main
```

## Options
To make it easier for you to get started, we made several options that can help you debug and better visualize the results.
 
### To slow down the scrolling of the game
```bash
./bin/main --slow [seconds: optional]
```
### Debugging mode
This mode helps you debug the game using a saved instance of the board and a particular hand to visualize the results
#### To get the best move using a board in text format
```bash
./bin/main --suzette-text [board] [hand]
```
Example :
```bash
./bin/main --suzette-text ................................................................................................................B.........P....A.........E....T.........R....E.........L....A.........ESBROUFA.......R........................... EELMSTT
```
 
#### To get the best move using a board saved in a (.txt) file
```bash
./bin/main --suzette-file [filename]
```
Example:
```bash
./bin/main --suzette-file ./data/boards/board3.txt
```
P.S. when launching the solver in the normal mode, all the boards are saved in the folder ./data/boards

#### Other debugging options
You can use the following options: 

  - -case, -c [number] -> to choose a particular starting CASE using a [number] included between [0, 224]
  - -vertical, -v      -> to search, the best move, vertically
  - -horizontal, -h    -> to search, the best move, horizontally
  
Example:
```bash
./bin/main --suzette-file ./data/boards/board3.txt -case 200 -vertical
```

### Need some help?
You can use the help option to visualize all the available options (with their explanation)
```bash
./bin/main --help
```
or
```bash
./bin/main --h
```

### Project details
This project was developped by Khaled Abdrabo and Salem Messoud during the 3rd year of our Computer Science bachelor's degree in Claude Bernard University - Lyon 1.
