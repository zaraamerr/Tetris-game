/*
description: this hpp file contains the Board class for the board of the game (a matrix of n x n holes)
attributions: thanks to javier lopez (javilop.com) for providing a thorough tutorial on how to build this game for beginners!
*/

#ifndef BOARD_HPP_
#define BOARD_HPP_
#include "pieces.h"

#define BOARD_LINE_WIDTH 6			// Width of each of the two lines that delimit the board
#define BLOCK_SIZE 16				// Width and Height of each block of a piece
#define BOARD_POSITION 320			// Center position of the board from the left of the screen
#define BOARD_WIDTH 10				// Board width in blocks 
#define BOARD_HEIGHT 20				// Board height in blocks
#define MIN_VERTICAL_MARGIN 20		// Minimum vertical margin for the board limit 		
#define MIN_HORIZONTAL_MARGIN 20	// Minimum horizontal margin for the board limit
#define PIECE_BLOCKS 5				// Number of horizontal and vertical blocks of a matrix piece

class Board
{
    public:
	    Board (Pieces *pPieces, int pScreenHeight); //parametrized constructor
        int GetXPosInPixels(int pPos);
	    int GetYPosInPixels(int pPos);
	    bool IsFreeBlock(int px, int py);
	    bool IsPossibleMovement(int px, int py, int pPiece, int pRotation);
	    void StorePiece(int px, int py, int pPiece, int pRotation);
	    void DeletePossibleLines();
	    bool IsGameOver();

    private:
        enum { POS_FREE, POS_FILLED };			// POS_FREE = free position of the board; POS_FILLED = filled position of the board
	    int mBoard [BOARD_WIDTH][BOARD_HEIGHT];	// Board that contains the pieces
	    Pieces *mPieces;
	    int mScreenHeight;

	    void InitBoard();
	    void DeleteLine (int pY);
};

#endif // BOARD_HPP_