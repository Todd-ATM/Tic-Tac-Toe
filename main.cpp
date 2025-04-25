#include <iostream>

class Board {
  public:
    //constructor
    Board() {
        char value = '0';
        //nested for loops to iterate, and assign value
        //to each element in our 2d array
        for (int i = 0; i < Row; i++) {
            for (int j = 0; j < Col; j++) {
                MainBoard[i][j] = value;
            }
        }
    }

   void DrawBoard() {
    //nested for loop
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            std::cout  << " │ "  << MainBoard[i][j];
        }
    std::cout << " │ "<< std::endl;
    }
    }

  private:
    int Row = 3;
    int Col = 3;
    char MainBoard[3][3];
};

int main() {
    Board main;
    main.DrawBoard();
    std::cout << "Hello World";
    return 0;
}

