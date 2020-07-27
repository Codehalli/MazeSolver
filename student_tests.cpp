#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE

#include <iostream>

#include "catch.hpp"
#include "mazesolver.hpp"

/*
 * #####
 * S # #
 * #   E
 * #####
 */
char m[4][5] = {{'#','#','#','#','#'},
	   {'S',' ','#',' ','#'},
	   {'#',' ',' ',' ','E'},
	   {'#','#','#','#','#'}};

char** maze;

void maze_4_5()
{
  maze = new char*[4];

  for(int i = 0; i < 4; i++)
    {
      maze[i] = new char[5];
      
      for(int j = 0; j < 5; j++)
	maze[i][j] = m[i][j];
    }
}

TEST_CASE( "Test constructor", "[MazeSolver]" )
{
  maze_4_5();
  
  MazeSolver ms(maze,4,5);

  ms.showMaze();
  
  REQUIRE(ms.solveMaze());

  ms.showMazeSolution();
}
