#ifndef COOKIE_H
#define COOKIE_H
#include <iostream>
using namespace std;

int check_x(bool** grid){
    /* Return the x-coordinate of the lastest of cookie. */
    for(int i=0;i<10;i++){         //i is row
        for(int j=9;j>-1;j--){     //j is column
            if(grid[i][j] == true){
                return i;
            }
        }
    }
    return -1;
}

int check_y(bool** grid){
    /* Return the y-coordinate of the lastest of cookie. */
    for(int i=0;i<10;i++){         //i is row
        for(int j=9;j>-1;j--){     //j is column
            if(grid[i][j] == true){
                return j;
            }
        }
    }
    return -1;
}

int print_grid(bool** grid){
    /* Print the grid you input. */
    /* Implement this function if necessary, it can help you to check your grid is correct or not. */
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

void placeTop(bool** grid){
    /* Get the coordinate of the cookie which place lastest from grid. */
    /* You can implement check_x(), check_y() above to get the x, y of the lastest cookie you place. */
    int x = check_x(grid);      //x is column
    int y = check_y(grid);      //y is row
    if(x==-1){
        x=9;                    //row
    }
    if(y==-1){
        y=0;                    //column
    }
    //std::cout<<x<<y;
    //std::cout<<'\n';
    /* Check when you place cookie, it will out of bound or not. */
    /* ... */
    /*try{
    }catch(string s){
        cout << s << endl;
        throw;
    }*/
    if(x-1 < 0){
        throw std::string("out of range.");
    }
    
    /* Place cookie from the top of current cookie. */
    grid[x-1][y] = true;
}

void placeRight(bool** grid){
    /* Get the coordinate of the cookie which place lastest from grid. */
    int x = check_x(grid);      //x is column
    int y = check_y(grid);      //y is row
    if(x==-1){
        x=9;                    //row
    }
    if(y==-1){
        y=0;                    //column
    }
    //std::cout<<x<<y;
    //std::cout<<'\n';
    /* Check when you place cookie, it will out of bound or not. */
    if(y+1 > 9){
        throw std::string("out of range.");
    }

    /* Place cookie from the right of current cookie. */
    grid[x][y+1] = true;
}

int calcRow(bool** grid, int row){
    /* Calculate the count of cookie on the specific row */
    if(row<0 || row>9){                 //out of range
        return -1;
    }
    
    int count = 0;
    for(int i=0;i<10;i++){
        if(grid[row][i] == true){
            count++;
        }
    }
    return count;
}

int calcColumn(bool** grid, int column){
    /* Calculate the count of cookie on the specific column */
    if(column<0 || column>9){           //out of range
        return -1;
    }
    
    int count = 0;
    for(int i=0;i<10;i++){
        if(grid[i][column] == true){
            count++;
        }
    }
    return count;
}

#endif
