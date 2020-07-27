#ifndef _MAZESOLVER_HPP_
#define _MAZESOLVER_HPP_

#include <iostream>
#include <stdexcept>
#include "Stack.hpp"

class MazeSolver
{
private:
  //size of maze
  std::size_t rows;
  std::size_t cols;
  //maze is stored internally as two-dimensional array
  char** maze;
  //cells in the maze we have already visited
  char** explored; 
  
  //cells in maze we need to explore
  Stack<std::pair<std::size_t, std::size_t> > frontier;
  //the path (maze indices in terms of row/columns) taken to go from S to E
  Stack<std::pair<std::size_t, std::size_t> > path;

  //row and column of goal (E)
  std::size_t row_g;
  std::size_t col_g;

  //row and column of initial (S)
  std::size_t row_s;
  std::size_t col_s;
    
    bool c_sol;

public:
  /*
   * Constructor to set defaults for private variables
   */ 
  MazeSolver();

  /*
   * Constructor to read-in a maze, validate it, and set private variables appropriately (a valid maze
   * will only have characters listed in the project description for an unsolved maze)
   * @param m - a two dimensional character array of size r-by-c
   * @param r - number of rows in the maze
   * @param c - number of columns in the maze
   */ 
  MazeSolver(char** m, const std::size_t r, const std::size_t c) throw(std::invalid_argument);

  /*
   * Destructor to destroy dynamically allocated variables
   */
  ~MazeSolver();
  
  /*
   * Function to set the maze we want to solve, validate it, and set private variables appropriately (a valid maze
   * will only have characters listed in the project description for an unsolved maze)
   * @param m - a two dimensional character array of size r-by-c
   * @param r - number of rows in the maze
   * @param c - number of columns in the maze
   */ 
  void setMaze(char** m, const std::size_t r, const std::size_t c) throw(std::invalid_argument);

  /*
   *  Return whether the maze is valid
   * @return true if the maze is valid, false otherwise
   */
  bool validMaze() const;
  
  /*
   * Return the maze we are attempting to solve as a two-dimensional array; nullptr if the maze is not defined
   * @return a pointer to the current maze
   */
  char** getMaze() const;

  /*
   * Provide the user with the size of the current maze
   * @return the number of rows and columns as a std::pair of the current maze
   */
  std::pair<std::size_t, std::size_t> getMazeSize() const;

  /*
   * Print the unsolved maze to std::cout according to the specification given in the project description;
   * if the was invalid/not set throw runtime error
   */
    void showMaze() const throw (std::runtime_error);
  /*
   * Find the shortest path from S to E in the current maze
   * @return false if no path could be found from S to E or error, true otherwise
   */
  bool solveMaze();

  /*
   * Return whether the maze has been be solved
   * @return true if the maze has been solved, false otherwise
   */
  bool solvedMaze() const;

  /*
   * Provide the user with the solved maze according to the project description: path should be marked in the maze leading
   * from S to E
   * @return a two-dimensional character array that includes the original maze and the path needed to solve it; if the 
   * maze cannot be solved or other error then nullptr
   */
  char** getMazeSolution();

  /*
   * Print the solved maze, with path, to std::cout according to the specification given in the project description; 
   * if the maze can't be solved throw runtime error
   */
  void showMazeSolution()const  throw(std::runtime_error);

  /*
   * Provide the user with the shortest path necessary to go from S to E
   * @return a stack with the rows/columns needed to go from S to E; point closes to S on the bottom of the stack
   * and the point closest to E on the top; if no solution is available return empty stack
   */
  Stack<std::pair<std::size_t, std::size_t> > getPath();
};
#endif
