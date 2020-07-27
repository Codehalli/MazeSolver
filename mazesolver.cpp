#include <iostream>
#include <stdexcept>

#include "mazesolver.hpp"

using namespace std;

/*
 * Constructor to set defaults for private variables
 */
MazeSolver::MazeSolver() //Complete
{
    maze = nullptr;
    explored = nullptr;
    
    rows = 0;
    cols = 0;
    
    row_g = 0;
    col_g = 0;
    
    row_s = 0;
    col_s = 0;
}

/*
 * Constructor to read-in a maze, validate it, and set private variables appropriately (a valid maze
 * will only have characters listed in the project description for an unsolved maze)
 * @param m - a two dimensional character array of size r-by-c
 * @param r - number of rows in the maze
 * @param c - number of columns in the maze
 */
MazeSolver::MazeSolver(char** m, const std::size_t r, const std::size_t c) throw(std::invalid_argument) //Complete
{
    maze = nullptr;
    maze = new char*[r];
    //maze = m;
    //rows = r;
    //cols = c;
    
    int i = 0;
    int counter = 0;
    while(i<r)
    {
        maze[i] = new char[c];
        int j =0;
        while(j<c)
        {
            if ((m[i][j] >35 || m[i][j]<35) && (m[i][j]> 32 || m[i][j] <32) && (m[i][j] > 83 || m[i][j] <83) && (m[i][j]> 69 || m[i][j] < 69))//TA Algorithm
            {
                maze = nullptr;
                throw std::invalid_argument("This maze isn't valid.");
            }
            else
            {
                if (m[i][j] == 83)
                    counter = counter + 1;
            
                maze[i][j] = m[i][j];
            
            j++;
        }
        
        i= i+1;
    }
    if (counter == 0)
        throw std::invalid_argument("There isn't a valid maze becuase of no S.");
    
    rows = r;
    cols = c;
    row_g = 0;
    col_g = 0;
    row_s = 0;
    col_s = 0;
        
    //To clear frontier
    explored = new char*[rows];
    
    i=0;
    
    while(i<rows)
    {
        explored = new char*[cols];
        int j=0;
        while(j < cols)
        {
            explored[i][j] = ' ';
            
            j++;
        }
        
        i= i+1;
    }
  }
}


//Destructor
MazeSolver::~MazeSolver() //Complete
{
    int i= 0;
    
    while(i<rows)
    {
        delete[] maze[i];
        maze[i] = nullptr;
    
        i=i+1;
    }
    
    delete[] maze;
    maze = nullptr;
    
    i = 0;
    while(i<rows)
    {
        delete[] explored[i];
        explored[i] = nullptr;
        i=i+1;
    }
    
    delete[] explored;
    explored = nullptr;
    
    frontier.clear(); //frontier in front
    path.clear(); //clears in front
}

/*
 * Function to set the maze we want to solve, validate it, and set private variables appropriately (a valid maze
 * will only have characters listed in the project description for an unsolved maze)
 * @param m - a two dimensional character array of size r-by-c
 * @param r - number of rows in the maze
 * @param c - number of columns in the maze
 */
void MazeSolver::setMaze(char** m, const std::size_t r, const std::size_t c) throw(std::invalid_argument)//Complete
{
    maze = nullptr;
    //maze = m;
    //rows = r;
    //cols = c;
    
    int i = 0;
    int counter = 0;
    
    maze = new char* [r];
    
    while(i<r)
    {
        maze[i] = new char[c];
        int j =0;
        while(j<c)
        {
            if ((m[i][j] >35 || m[i][j]<35) && (m[i][j]> 32 || m[i][j] <32) && (m[i][j] > 83 || m[i][j] <83) && (m[i][j]> 69 || m[i][j] < 69))//TA Algorithm
            {
                maze = nullptr;
                throw std::invalid_argument("This maze isn't valid.");
            }
            
            if (m[i][j] == 83)
                counter = counter + 1;
            
            maze[i][j] = m[i][j];
            
            j++;
        }
        
        i= i+1;
    }
    if (counter == 0)
        throw std::invalid_argument("There isn't a valid maze becuase of no S.");
    
    rows = r;
    cols = c;
    row_g = 0;
    col_g = 0;
    row_s = 0;
    col_s = 0;
    
    //To clear frontier
    explored = new char*[rows];
    
    i=0;
    
    while(i<rows)
    {
        explored = new char*[cols];
        int j=0;
        while(j < cols)
        {
            explored[i][j] = ' ';
            
            j++;
        }
        
        i= i+1;
    }
}

//Function To check if Maze is Valid
bool MazeSolver::validMaze() const //Complete
{
    int i = 0;
    int counter = 0;
    
    while(i< rows)
    {
       int j = 0;
       while(j < cols)
       {
           if ((maze[i][j] > 35 || maze[i][j] < 35) && (maze[i][j] > 32 || maze[i][j] < 32) && (maze[i][j] > 83 || maze[i][j] < 83) && (maze[i][j] > 69 || maze[i][j] < 69))
               return false;

           if (maze[i][j] == 83)
               counter= counter+1;
           j++;
       }
       i=i+1;
   }
    if (counter == 0)
    {
        return false;
    }
    else if (!(counter == 0))
    {
        return true;
    }
    else
    {
        return true;
    }
}

//Function to return the Maze
char** MazeSolver::getMaze() const //Complete
{
    /*if(getMazeSize().first == 0 || getMazeSize().second == 0)
        return nullptr;
    else */
        return maze;
}

//Function to provide the size of the pair
std::pair<std::size_t, std::size_t> MazeSolver::getMazeSize() const //Complete
{
    return std::make_pair(rows, cols);
}

//Function that will print the Maze
void MazeSolver::showMaze() const throw (std::runtime_error) //Complete
{
    if (!validMaze())
        throw std::runtime_error("The Maze is invalid");
    
    int i = 0;
    
    while( i< rows)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << maze[i][j];
        }
        std::cout << std::endl;
        i= i+1;
    }
}

bool MazeSolver::solveMaze()
{
    if (!validMaze())
    {
        return false;
    }
    
    bool s_reg = false;
    int i =0;
    while (i < rows)
    {
        int j = 0;
        while(j<cols)
        {
            if (maze[i][j] == 'S')
            {
                row_s = i;
                col_s = j;
                frontier.push(std::make_pair(i, j));
                s_reg = true;
                break;
            }
            j++;
        }
        if (s_reg == true)
            break;
        i = i+1;
    }
    
    std::pair<std::size_t, std::size_t> s = std::make_pair(0, 0);
    
    bool lp = true;
    bool right_P = true;

    while (lp == true)
    {
        if (frontier.size() == 0)
            lp = false;
        
        if (right_P == false)
        {
            bool finish = false;
            while (path.size() > 0 && finish == false)
            {
                
                std::pair<std::size_t, std::size_t> a = std::make_pair(0, 0);
                a = path.peek();
                
                if (a.first == 0){}
                else{
                    if (explored[a.first - 1][a.second] == 32 && maze[a.first -1][a.second] == 32)
                        finish = true;
                }
        
                if (a.first == rows - 1){}
                else
                {
                    if (explored[a.first + 1][a.second] == 32 && maze[a.first + 1][a.second] == 32)
                        finish = true;
                }

                if (a.second == cols - 1){}
                else{
                    if (explored[a.first][a.second + 1] ==32 && maze[a.first][a.second + 1] == 32){
                        finish = true;
                    }
                }
                if (a.second == 0){}
                else
                {
                    if (explored[a.first][a.second - 1] == 32 && maze[a.first][a.second - 1] == 32){
                        finish = true;
                    }
                }
                
                if (finish == false)
                {
                    path.pop();
                }
            }
        }
        
        if (frontier.size() > 0)
        {
            s = frontier.peek();
            
            if(maze[s.first][s.second] != 83)
                path.push(frontier.peek());
        }
    
        explored[s.first][s.second] = 'X';
        frontier.pop();
        
        right_P = false;
        int i=0;
        while(i<4)
        {
        //Top
            if (i == 0)
            {
                if (s.first == 0){}
                else
                {
                    if ((frontier.size() == 0 || s != frontier.peek()) && explored[s.first - 1][s.second] == 32)
                    {
                        if (maze[s.first - 1][s.second] == 69)
                        {
                            lp = false;
                            c_sol = true;
                            row_g = s.first - 1;
                            col_g = s.second;
                            break;
                        }
                        if (maze[s.first - 1][s.second] == 32)
                        {
                            frontier.push(std::make_pair(s.first - 1, s.second));
                            right_P = true;
                        }
                        
                     }
                    
                }
                
             }
        //Bottom
            if (i == 1)
            {
                if (s.first == (rows - 1)){}
                else
                {
                    if ((frontier.size() == 0 || s != frontier.peek()) && explored[s.first + 1][s.second] == 32)
                    {
                        if (maze[s.first + 1][s.second] == 69)
                        {
                            lp = false;
                            c_sol = true;
                            row_g = s.first + 1;
                            col_g = s.second;
                            break;
                        }
                        if (maze[s.first + 1][s.second] == 32)
                        {
                            frontier.push(std::make_pair(s.first - 1, s.second));
                            right_P = true;
                        }
                        
                    }
                    
                }
                
             }
        //Right
            if (i == 2)
            {
                if (s.second == (cols + 1)){}
                else
                {
                    if ((frontier.size() == 0 || s != frontier.peek()) && explored[s.first][s.second +1] == 32)
                    {
                        if (maze[s.first][s.second + 1] == 69)
                        {
                            lp = false;
                            c_sol = true;
                            row_g = s.first ;
                            col_g = s.second + 1;
                            break;
                        }
                        if (maze[s.first][s.second + 1] == 32)
                        {
                            frontier.push(std::make_pair(s.first, s.second+1));
                            right_P = true;
                        }
                        
                    }
                    
                }
                
            }
        //Left
            if (i == 3)
            {
                if (s.second == 0){}
                else
                {
                    if ((frontier.size() == 0 || s != frontier.peek()) && explored[s.first][s.second - 1] == 32)
                    {
                        if (maze[s.first][s.second - 1] == 69)
                        {
                            lp = false;
                            c_sol = true;
                            row_g = s.first ;
                            col_g = s.second - 1;
                            break;
                        }
                        if (maze[s.first][s.second-1] == 32)
                        {
                            frontier.push(std::make_pair(s.first, s.second -1 ));
                            right_P = true;
                        }
                        
                    }
                    
                }
                
            }
    }
            
            if (c_sol == true)
            {
                Stack<std::pair<std::size_t, std::size_t>> copy = getPath();
                int h = path.size();
                std::pair<std::size_t, std::size_t> p = std::make_pair(0, 0);
                
                i = 0;
                while(i<h)
                {
                    s = copy.peek();
                    copy.pop();
                    
                    
                    maze[s.first][s.second] = '*';
                
                    i=i+1;
                }
                copy.clear();
             }
    }
    return c_sol;
}

    
//Function return the solve Maze
bool MazeSolver::solvedMaze() const //Complete
{
    return c_sol;
}

//Function gets the Maze solution
char** MazeSolver::getMazeSolution()//Complete
{
    if (!solvedMaze())
        return nullptr;
    else
        return maze;
}

//Function Shows the Maze soltion
void MazeSolver::showMazeSolution()const throw(std::runtime_error)//Complete
{
    if (!solvedMaze())
        throw std::runtime_error("Couldn't Solve the Maze");
    else
    {
        int i=0;
        while(i<rows)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << maze[i][j];
                
            }
            
            std::cout << '\n';
            i = i+1;
        }
    }
}
//Function returns the getPath
Stack<std::pair<std::size_t, std::size_t>> MazeSolver:: getPath() //Complete
{
    return path;
}

