# so_long

## Description

This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.
My game was made in C with the graphical library MLX42. The goal of the game is to collect all pickups and go through the exit and...

## What I learned
  1. [DFS Algorithm](https://www.programiz.com/dsa/graph-dfs) - Depth first Search or Depth first traversal is a [RECURSIVE](https://www.geeksforgeeks.org/introduction-to-recursion-data-structure-and-algorithm-tutorials/) algorithm for searching all the vertices of a graph or tree data structure. Traversal means visiting all the nodes of a graph.
  2. [MLX42](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) - MiniLibX is a tiny graphics library which allows you to do the most basic things for rendering something in screens


## Steps 
  
### Error handling
  1. Check inputed arguments if argc < 2 or argc > 2
  2. Program has to take as parameter a map description file ending with the .ber extension.
  3. The map has to be constructed with 3 components: walls, collectibles, and free space.
  4. The map can be composed of only these 5 characters:
    0 for an empty space,
    1 for a wall,
    C for a collectible,
    E for a map exit,
    P for the player’s starting position.
  5. The map must contain at least 1 exit, 1 collectible, and 1 starting position.
  6. If the map contains a duplicates characters (exit/start), you should display an error message.
  7. The map must be rectangular.
  8. The map must be closed/surrounded by walls. If it’s not, the program must return an error.
  9. You have to check if there’s a valid path in the map
  10. You must be able to parse any kind of map, as long as it respects the above rules.

### Getting map
  1. Get whole the map with gnl and place it to string
  2. Split string to 2D array and assing to map2
  3. Split string to 2D array and assing to tmp (it will be use to find a valid path to exit(check DFS))
  
### Using MLX display map<img width="1218" alt="Screen Shot 2022-11-07 at 5 45 42 PM" src="https://user-images.githubusercontent.com/106797151/200366602-e4658440-ca60-4782-bdd4-fe416e1d808e.png">



