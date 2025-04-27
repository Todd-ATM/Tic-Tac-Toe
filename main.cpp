#include <iostream>

class Board {
  public:
  bool checked[3][3];
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
                            checked[row][col] = true;
                        // if current player is O
                        } else if (CurrentPlayer == false) {
                            MainBoard[row][col] = playerO;
                            checked[row][col] = true;
                        }
        }

        


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
        } else 
        std::cout << "Player invalid" << std::endl;
        return false;

    }


  private:
    int Row = 3;
    int Col = 3;
    char MainBoard[3][3];
    const char playerX = 'X';
    const char playerO = 'O';
    bool CurrentPlayer = false;
    //identical to mainboard but at each element, adds checked bool for true

};

int main() {
    Board main;
    bool CurrentTurn = false; //who's turn is it currently, False = O's
    main.DrawBoard();
    //main game loop
    while (true) {
        int rowDec, colDec;
        char next; //char for next line in cin buffer
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
            if (!std::cin) { //if user enters non number
                std::cin.clear(); //clear fail state
                std::cin.ignore(100, '\n'); //flush bad input
                std::cout << "Please enter valid NUMBER" << std::endl;
                continue; //restart loop
            }
            if (rowDec < 3) {
                next = std::cin.peek(); //set next char in line to next char variable
                if (next == '\n') { 
                    std::cout << "You're good to go" << std::endl;
                }
                else {
                    std::cin.ignore(100, '\n'); //flush bad input
                    std::cout << "Please enter valid NUMBER" << std::endl;
                    continue; //restart loop
                }
            }
            else {
                std::cout << "Invalid Try again" << std::endl;
                continue;
            }
            std::cout << "Enter Col Number -> ";
            std::cin >> colDec;

            //exception handling
            if (!std::cin) { //if user enters non number
                std::cin.clear(); //clear fail state
                std::cin.ignore(100, '\n'); //flush bad input
                std::cout << "Please enter valid Row Number. Retry" << std::endl;
                continue; //restart loop
            }
            if (colDec < 3 && rowDec < 3 && !main.checked[rowDec][colDec]) {
                next = std::cin.peek();
                if (next == '\n') {
                    main.MovePiece(rowDec, colDec);
                    main.DrawBoard();
                    CurrentTurn = main.change();
                } else {
                    std::cin.ignore(100, '\n'); //flush bad input
                    std::cout << "Please enter valid Col Number. Retry" << std::endl;
                    continue; //restart loop
                }

            } else {
                std::cout << "Invalid Try again" << std::endl;
                continue;
            }

        }

    }


