/*
description: this cpp file contains code for the board of the game (a matrix of n x n holes)
attributions: thanks to javier lopez (javilop.com) for providing a thorough tutorial on how to build this game for beginners!
*/

#include "board.h"

//initalize the board with the parametrized constructor

Board::Board (Pieces *pieces, int pScreenHeight){
    // Get the screen height
	mScreenHeight = pScreenHeight;

	// Get the pointer to the pieces class
	mPieces = pPieces;

	//Init the board blocks with free positions
	InitBoard();
}

//initialize the board with free positions

void Board::InitBoard(){
    for (int i = 0; i < BOARD_WIDTH; i++)
        for (int j = 0; j < BOARD_HEIGHT; j++)
            mBoard[i][j] = POS_FREE;
}

/* 								
POST: Store a piece in the board by filling the blocks

Parameters: px:Horizontal position in blocks
            py:Vertical position in blocks
            pPiece:	Piece to draw
            pRotation:	1 of the 4 possible rotations 
*/

void Board::StorePiece (int px, int py, int pPiece, int pRotation){
    // Store each block of the piece into the board
    for (int i1 = px, i2 = 0; i1 < px + PIECE_BLOCKS; i1++, i2++){
        for (int j1 = py, j2 = 0; j1 < py + PIECE_BLOCKS; j1++, j2++){	
            // Store only the blocks of the piece that are not holes
            if (mPieces->getBlockType (pPiece, pRotation, j2, i2) != 0)		
                mBoard[i1][j1] = POS_FILLED;	
        }
    }
}

/*							
Check if the game is over based on whether the first line is full or not
Returns true or false
====================================== 
*/
bool Board::IsGameOver()
{
	//If the first line has blocks, then, game over
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		if (mBoard[i][0] == POS_FILLED) return true;
	}

	return false;
}


/* 								
Delete a line of the board and moving all above lines down one

Parameter: py: Vertical position in blocks of the line to delete
*/

void Board::DeleteLine (int py)
{
	// Moves all the upper lines one row down
	for (int j = py; j > 0; j--)
	{
		for (int i = 0; i < BOARD_WIDTH; i++)
		{
			mBoard[i][j] = mBoard[i][j-1];
		}
	}	
}


/* 									
Delete all the lines that should be removed
*/
void Board::DeletePossibleLines ()
{
	for (int j = 0; j < BOARD_HEIGHT; j++)
	{
		int i = 0;
		while (i < BOARD_WIDTH)
		{
			if (mBoard[i][j] != POS_FILLED) break;
			i++;
		}

		if (i == BOARD_WIDTH) DeleteLine (j); //use deleteline!
	}
}


/* 									
Returns true if a specific block of the board is empty, 0 if it is filled

Parameters: px:	Horizontal position in blocks
            py: Vertical position in blocks
*/
bool Board::IsFreeBlock (int px, int py)
{
	if (mBoard [px][py] == POS_FREE){
        return true;
    } else{
        return false;
    }
}


/* 								
Returns the horizontal position (in pixels) of the block given
Parameters: pPos: Horizontal position of the block in the board
*/
int Board::GetXPosInPixels (int pPos)
{
	return  ( ( BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) ) + (pPos * BLOCK_SIZE) );
}


/* 									
Returns the vertical position (in pixels) of the block given

Parameters: pPos: Horizontal position of the block in the board
*/
int Board::GetYPosInPixels (int pPos)
{
	return ( (mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE) );
}


/* 								
Check if the piece can be stored at this position without any collision
Returns true if the movement is possible, false otherwise

Parameters: px:	Horizontal position in blocks
            py:	Vertical position in blocks
            pPiece:	Piece to draw
            pRotation: 1 of the 4 possible rotations
*/
bool Board::IsPossibleMovement (int px, int py, int pPiece, int pRotation)
{
	// Checks if there's chance of a collision with pieces already stored in the board or the board limits
	// This is just to check the 5x5 blocks of a piece with the appropiate area in the board
	for (int i1 = px, i2 = 0; i1 < px + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = py, j2 = 0; j1 < py + PIECE_BLOCKS; j1++, j2++)
		{	
			// Check if the piece is outside the limits of the board
			if (i1 < 0 || i1 > BOARD_WIDTH  - 1	|| j1 > BOARD_HEIGHT - 1)
			{
				if (mPieces->getBlockType (pPiece, pRotation, j2, i2) != 0)
					return 0;		
			}

			// Check if the piece have already collided with a block already stored in the map
			if (j1 >= 0)	
			{
				if ((mPieces->getBlockType (pPiece, pRotation, j2, i2) != 0) && (!IsFreeBlock (i1, j1)))
					return false;
			}
		}
	}

	// No collision
	return true;
}
