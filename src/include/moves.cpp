#include "moves.hpp"
#include <iostream>

std::pair<int,int>* Pawn::getMoves(const Cboard& cboard ,int& numMoves  ) const {
    std::pair<int,int>* moves = new std::pair<int,int >[2];
    numMove = 0;
     
     int newX = posX+1;
     int newY =  posY+1;

     if(cboard.isValidSquare(newX, newY)&& cboard(newX,newY )==0){
        moves[numMoves++]={newX,newY};


     }
     return moves ; 

}
std::pair<int,int>* Bishop::getMoves(const Cboard& cboard , int& numMoves ) const{
    std::pair<int,int>* moves = new std::pair<int , int>[14];

   numMoves = 0;

   int dx[] = {-1 , -1 , 1 ,1 }
   int dy[]={-1 , 1, -1, 1 }

       for  (int i= 0 ; i<4 ; ++i) {
            int newX = posX;
            int newY = posY;
            while (ture ){
             newX += dx[i];
             newY +=dy[i];

         if (!chessboard.isValidSquare(newX, newY))
                break;

            if (chessboard(newX, newY) == 0)
                moves[numMoves++] = {newX, newY};
            else
                break;


            }
         }  
         return moves ; 
 }
std::pair<int, int>* Rook::getMoves(const Chessboard& chessboard, int& numMoves) const {
    std::pair<int, int>* moves = new std::pair<int, int>[14];
    numMoves = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int newX = posX;
        int newY = posY;
        while (true) {
            newX += dx[i];
            newY += dy[i];

            if (!chessboard.isValidSquare(newX, newY))
                break;

            if (chessboard(newX, newY) == 0)
                moves[numMoves++] = {newX, newY};
            else
                break;
        }
    }

    return moves;
}

std::pair<int, int>* Knight::getMoves(const Chessboard& chessboard, int& numMoves) const {
    std::pair<int, int>* moves = new std::pair<int, int>[8];
    numMoves = 0;

    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; ++i) {
        int newX = posX + dx[i];
        int newY = posY + dy[i];

        if (chessboard.isValidSquare(newX, newY) && chessboard(newX, newY) == 0) {
            moves[numMoves++] = {newX, newY};
        }
    }

    return moves;
}

std::pair<int, int>* Queen::getMoves(const Chessboard& chessboard, int& numMoves) const {
    std::pair<int, int>* moves = new std::pair<int, int>[27];
    numMoves = 0;

    Bishop bishop;
    Rook rook;

    int numBishopMoves = 0, numRookMoves = 0;
    std::pair<int, int>* bishopMoves = bishop.getMoves(chessboard, numBishopMoves);
    std::pair<int, int>* rookMoves = rook.getMoves(chessboard, numRookMoves);

    for (int i = 0; i < numBishopMoves; ++i) {
        moves[numMoves++] = bishopMoves[i];
    }

    for (int i = 0; i < numRookMoves; ++i) {
        moves[numMoves++] = rookMoves[i];
    }

    delete[] bishopMoves;
    delete[] rookMoves;

    return moves;
}

std::pair<int, int>* King::getMoves(const Chessboard& chessboard, int& numMoves) const {
    std::pair<int, int>* moves = new std::pair<int, int>[8];
    numMoves = 0;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
for (int i = 0; i < 8; ++i) {
        int newX = posX + dx[i];
        int newY = posY + dy[i];

        if (chessboard.isValidSquare(newX, newY) && chessboard(newX, newY) == 0) {
            moves[numMoves++] = {newX, newY};
        }
    }

    return moves;
}

Chessboard::Chessboard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            chessboard[i][j] = 0;
        }
    }
}

void Chessboard::placePiece(Piece* piece, int x, int y) {
    chessboard[x][y] = 1;
    piece->setPosition(x, y);
}

bool Chessboard::isValidSquare(int x, int y) const {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int Chessboard::operator()(int x, int y) const {
    return chessboard[x][y];
}

void Chessboard::printChessboard() const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << chessboard[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Main function
int main() {
    Chessboard chessboard;

    // Create and place the pieces on the chessboard (skipping this step for brevity)

    // Print the initial state of the chessboard (skipping this step for brevity)

    // Enter moves until the user types "exit"
    char move[6]; // Store user input as character array
    while (true) {
        std::cout << "Enter move (e.g., 'c5 d6') or 'exit' to quit: ";
        std::cin.getline(move, 6); // Read user input

        if (std::strcmp(move, "exit") == 0)
            break;

        // Extract 'from_square' and 'to_square' from user input
        char from_square[3], to_square[3];
        std::sscanf(move, "%s %s", from_square, to_square);

        // Convert algebraic notation to coordinates
        std::pair<int, int> from_coords = {from_square[1] - '1', from_square[0] - 'a'};
        std::pair<int, int> to_coords = {to_square[1] - '1', to_square[0] - 'a'};

        // Perform any additional validation if required
        // ...

        // Process the move
        // ...

        // Print the updated state of the chessboard (skipping this step for brevity)
    }

    return 0;
}




























