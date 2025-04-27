#include <iostream>

class Board {
  public:
    //constructor
    Board() {
        char value = ' '; 
        //nested for loops to iterate, and assign value
        //to each element in our 2d array
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                MainBoard[i][j] = value;
            }
        }
    }

   void DrawBoard() {
    //nested for loop to draw horizontal and vertical dividers of our board
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            std::cout  << " │ "  << MainBoard[i][j];
        }
    std::cout << " │ " << std::endl;
    std::cout << " +---+---+---+" << std::endl;

    }
    }

    void MovePiece(int row, int col) {
        //scope
        if (row < 3 && col < 3) {
                        // if current player is X
                        if (CurrentPlayer == true) {
                            MainBoard[row][col] = playerX;
                        // if current player is O
                        } else if (CurrentPlayer == false) {
                            MainBoard[row][col] = playerO;
                        }
        }
        else 
        std::cout << "not valid range" << std::endl;
        


    }

    //basic changer
    void change() {
        if (CurrentPlayer == true) {
            CurrentPlayer = false;
        } 
        else if (CurrentPlayer == false) {
            CurrentPlayer = true;
        }

    }


  private:
    int Row = 3;
    int Col = 3;
    char MainBoard[3][3];
    const char playerX = 'X';
    const char playerO = 'O';
    bool CurrentPlayer = false;
};

int main() {
    Board main;
    //add O to 0,0
    main.MovePiece(0, 0);
    //change to X
    main.change();
    //add X to 1,1
    main.MovePiece(1,1);
    //change back to O
    main.change();
    //add O to 2,2
    main.MovePiece(2,2);
    //draw the finalized board
    main.DrawBoard();
    //try adding O to 3,3. Should return in the error message set
    main.MovePiece(3,3);
    std::cout << "Hello World";
    return 0;
}

