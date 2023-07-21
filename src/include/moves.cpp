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





