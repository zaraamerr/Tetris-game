/*
description: this hpp file contains the Game class which initializes the game, draws the board and pieces by drawing each block as a rectangle 
and creates new random pieces.
attributions: thanks to javier lopez (javilop.com) for providing a thorough tutorial on how to build this game for beginners!
*/

#ifndef GAME_HPP
#define GAME_HPP

#include "pieces.h"
#include "board.h"
#include "io.h"
#include <time.h>

#define WAIT_TIME 600       //number of milliseconds the piece remains before going one block down

class Game {
    public:
        Game (Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight); //parametrized constructor
        void DrawScene ();
	    void CreateNewPiece ();

	    int mPosX, mPosY;				// Position of the piece that is falling down
	    int mPiece, mRotation;			// Type and rotation of the piece that is falling down
    private: 
        int mScreenHeight;				// Screen height in pixels
	    int mNextPosX, mNextPosY;		// Position of the next piece
	    int mNextPiece, mNextRotation;	// Type  and rotation of the next piece

	    Board *mBoard;
	    Pieces *mPieces;
	    IO *mIO;

	    int GetRand (int pA, int pB);
	    void InitGame();
	    void DrawPiece (int pX, int pY, int pPiece, int pRotation);
	    void DrawBoard ();
};

#endif //GAME_HPP