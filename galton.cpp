//galton board in c++
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(){
    //create an array to mimic the layout of pegs of board

    const int SIZE = 10;
    int* counts[SIZE]; //coutns[i] where 0<= i < 10 is a pointer int
    for(int row  = 0;row < SIZE;row++){
        counts[row] = new int[row+1]; //create triangle array
        //counts[0] points to an int
        //counts[1] points to (1+1) ints
        //counts[9] points (9+1) ints where 9 is row index
    
    }
    //initialize triangle array
    for(int row = 0;row < SIZE;row++){
        for(int col = 0; col < row+1;col++){
            for(int col = 0; col < row+1;col++){
                counts[row][col] = 0;
            }
        }
    }
    int numThrows = 1000;
    for(int ball = 0;ball < numThrows;ball++){
        //throw a ball
        int row = 0;
        int col = 0;
        counts[row][col]++; //each ball goes thru containger
                        //counts[0][0]
        //decide how to go to the col in the new row
        for(row = 1;row < SIZE;row++){
            int randVal = rand() % 2;
            if (randVal % 2 != 0){
                col++;
            }
            counts[row][col]++;
        }
    }

    //display content
    for(int row = 0; row <SIZE;row++){
        for (int col = 0;col < row+1;col++){
            cout << setw(6) << counts[row][col];
        }
        cout << endl;
    }
    for(int row = 0;row < SIZE;row++){
        delete[] counts[row]; //release space
        counts[row] = nullptr; //mark the address pointing
        //to that adress as invalid
        //to avoid dangling pointer problem
    }

    return 0;
}