#include <iostream>
#include "maze.h"
#include <cassert>

using std::ostream;
using data_structures_assignment_5::maze;
using data_structures_assignment_5::maze_node;

using std::cout;
using std::endl;

///////////////////////////////////////////////////////////////////////////////////////////

void triangle(ostream& outs, unsigned int m, unsigned int n)
// Precondition: m <= n
// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
// to the output stream outs. The first line contains m asterisks, the next
// line contains m+1 asterisks, and so on up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.
/* Example output:
   triangle(cout, 3, 5) will print this to cout:
   ***
   ****
   *****
   *****
   ****
   ***
*/
{


    // BASE CASE:
    if (m == n){
        for (std::size_t i = 0; i < m; i++){
            outs << "*";
        }
        outs << endl;
        for (std::size_t i = 0; i < m; i++){
            outs << "*";
        }
        outs << endl;
        return;
    }

    // INDUCTIVE STEP:

    if (m > n){
        cout << "N cannot be less then M" << endl;
        assert(m <= n);  // Precondition: m <= n
        return;
    }else if( m < n){


        for(std::size_t i =0; i < m; i++){
            outs << "*";
        }
        outs << endl;

        triangle(cout, m+1, n);

        for (std::size_t i =0; i < m; i++){
            outs << "*";
        }
        outs << endl;

    }
}

///////////////////////////////////////////////////////////////////////////////////////////

int count_ways_to_step(int number_of_stepping_stones)
// Postcondition: The number of ways to reach the final stepping stone using
// either a small step (moving 1 stepping stone) or a large step (moving 2 stepping
// stones) in any combination is returned.
// For 3 stepping stones there are 3 ways. For 4 stepping stones, there are 5 ways.
{
    if (number_of_stepping_stones == 1){
        cout << "Number of possible paths: " << number_of_stepping_stones << endl; // if it reaches the end;
        return number_of_stepping_stones;
    }
    if (number_of_stepping_stones == 2){
        return number_of_stepping_stones;  // If there is 1 step left
    }

    return (count_ways_to_step(number_of_stepping_stones -1) + count_ways_to_step(number_of_stepping_stones -2));
}

///////////////////////////////////////////////////////////////////////////////////////////

bool print_path_through_maze(const maze_node* maze_position)
// Postcondition: Prints the path through the maze, with 0s representing right
// turns and 1s representing left turns.
// You may print the path in reverse order (this will be easier).
// Hint: Use the return boolean to signify that the current path is the correct path.
{
    // BASE CASE:

    if (maze_position->right() == nullptr && maze_position->left() == nullptr){
        if (maze_position->is_finish()){
            return true;
        }else{
            return false;
        }
    }


    // INDUCTIVE STEP:

    // Checks the left Node, if the left node in not NULL;
    if (maze_position->left() != nullptr){
        bool value = print_path_through_maze(maze_position->left());
        if (value) {
            cout << "0" << endl;
            return value;
        }
    }
    // Checks the right Node, if the right node in not NULL;
    if (maze_position->right() != nullptr) {
        bool value = print_path_through_maze(maze_position->right());
        if(value){
            cout << "1" << endl;
            return value;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// EXTRA CREDIT:       TO BE DONE LATER IN re-submition
///////////////////////////////////////////////////////////////////////////////////////////

void Every_possible_path_to_the_maze(const maze_node* maze_position){

    cout << " Recursion.cpp " << endl;

    if(maze_position->left() == nullptr && maze_position->right() == nullptr){
        // This must be a BASE CASE, where we're dealing with a leaf node ...
    }


    if(maze_position->left() != nullptr){
        bool store = print_path_through_maze(maze_position->left());

    }
    if(maze_position->right() != nullptr){
        bool store = print_path_through_maze(maze_position->right());

    }



}

///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    // You can test your code by adding it here.

    // maze m1(1);
    // print_path_through_maze(m1.get_start());

    // count_ways_to_step(4);

    // cout << count_ways_to_step(5) << endl;

    maze m1(1);
    Every_possible_path_to_the_maze(m1.get_start());


    // triangle(cout, 3,5);


    return 0;
}
