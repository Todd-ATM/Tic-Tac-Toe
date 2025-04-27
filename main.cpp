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
    bool change() {
        if (CurrentPlayer == true) {
            CurrentPlayer = false;
            return false;
        } 
        else if (CurrentPlayer == false) {
            CurrentPlayer = true;
            return true;
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
    bool CurrentTurn = false; //who's turn is it currently,, False = O's
    //main game loop
    while (true) {
        int rowDec, colDec;
        //cases for who's turn
        if (CurrentTurn == false) {
            std::cout << "O's Turn" << std::endl;
        }
        if (CurrentTurn == true) {
            std::cout << "X's Turn" << std::endl;
        }
            std::cout << "Enter Row Number -> ";
            std::cin >> rowDec;
            //exception handling
            if (rowDec < 3) {
                std::cout << "Good value" << std::endl;
            }
            else {
                std::cout << "Invalid Try again" << std::endl;
                continue;
            }
            std::cout << "Enter Col Number -> ";
            std::cin >> colDec;

            //exception handling
            if (colDec < 3 && rowDec < 3) {
                main.MovePiece(rowDec, colDec);
                main.DrawBoard();
                CurrentTurn = main.change();
            } else {
                std::cout << "Invalid Try again" << std::endl;
                continue;
            }

        }

    }


