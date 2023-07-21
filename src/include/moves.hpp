#ifndef MOVES_hpp
#define MOVES_hpp
#include <iostream>

class Cboard;
// BAse class for any chess piece
class piece {
    public :
    piece() : posX(0),posY(0){}
    virtual ~piece () { }
    virtual std::pair<int, int>*getMoves (const Cboard& cboard, int& numMoves) const  0;
    void setPosition(int x , int y){
        posX = x;
        posY = y;
    }
    private :
    int posX;
    int posY;
};
class Pawn : public piece {
    using piece::piece;
    virtual std::pair<int,int>*getMoves(const Cboard& cboard , int& numMoves) const override ;
};

class Bishop : public piece{
    using piece::piece;
    virtual std::pair<int,int>* getMoves(const Cboard& cboard , int& numMoves) const override ;
    };

class Rook : public piece{
    using piece::piece;
    virtual std::pair<int,int>* getMoves(const Cboard& cboard , int& numMoves) const override ;
    };
class Knight : public piece{
    using piece::piece;
    virtual std::pair<int,int>* getMoves(const Cboard& cboard , int& numMoves) const override ;
    };

class Queen : public piece{
    using piece::piece;
    virtual std::pair<int,int>* getMoves(const Cboard& cboard , int& numMoves) const override ;
    };
class King : public piece{
    using piece::piece;
    virtual std::pair<int,int>* getMoves(const Cboard& cboard , int& numMoves) const override ;
    };
class Cboard{
    public :
    Cboard();
    void placepiece(piece*piece , int x , int y);
    int operator()(int x , int y) const ;
    void printCbord() const ;

    private :
    int cboard[8][8];


};

#endif 





















