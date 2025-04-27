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
        //add scope
        if (row <= 3 && col <= 3) {
                        // if current player is X
                        if (CurrentPlayer == true) {
                            MainBoard[row][col] = playerX;
                        // if current player is O
                        } else if (CurrentPlayer == false) {
                            MainBoard[row][col] = playerO;
                        }
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
    main.MovePiece(1, 1);
    main.MovePiece(2,2);
    main.MovePiece(0,0);
    main.DrawBoard();
    std::cout << "Hello World";
    return 0;
}

