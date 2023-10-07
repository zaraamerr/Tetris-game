/*
description: this cpp file contains code for all the tetris pieces, their respective rotations, as well as, displacements for the hotspot.
attributions: thanks to javier lopez (javilop.com) for providing a thorough tutorial on how to build this game for beginners!
*/

#include "pieces.h"

/*
Notes:
- There are 7 different types of pieces: square, I, L, L-mirrored, N, N-mirrored and T.
- Each piece is stores in a 5x5 matrix where 0 means no block, 1 means normal block, and 2 means pivot block (rotation point)
- There are 4 possible rotations for each piece
- To store the 4 possible rotations of each piece (5x5 matrices), we need a 4D array!
*/

//Pieces definition
char mPieces [7][4][5][5] = {
    // Square
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    }
   },

// I
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 2, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0}, 
    {0, 0, 2, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 1, 2, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    }
   }
  ,
// L
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 2, 1, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 2, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   },
// L mirrored
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 2, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 2, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0}
    }
   },
// N
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 2, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 2, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   },
// N mirrored
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 2, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 1, 2, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   },
// T
  {
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 2, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 2, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 2, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
    },
   {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 2, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
    }
   }
};

//Displacement definition
int mDisplacement [7][4][2]{
    /* Square */
  {
	{-2, -3}, 
    {-2, -3},
    {-2, -3},
    {-2, -3}
   },
/* I */
  {
	{-2, -2},
    {-2, -3},
    {-2, -2},
    {-2, -3}
   },
/* L */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* L mirrored */
  {
	{-2, -3},
    {-2, -2},
    {-2, -3},
    {-2, -3}
   },
/* N */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* N mirrored */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
/* T */
  {
	{-2, -3},
    {-2, -3},
    {-2, -3},
    {-2, -2}
   },
};

//Define the Pieces public member functions
/*
Returns that can be expected: 0 = no block, 1 = normal block, 2 = pivot block
Parameters: pPiece: piece to draw
            pRotation: 1 of the 4 possible rotations
            px: horizontal position in blocks
            py: vertical position in blocks
*/

int Pieces::getBlockType (int pPiece, int pRotation, int px, int py)
{
    return mPieces [pPiece][pRotation][px][py];
}

/*
Returns the horizontal displacement of the piece that has to be applied in order for it to be in the correct position
Parameters: pPiece: piece to draw
            pRotation: 1 of the 4 possible rotations
*/

int Pieces::getXInitialPos (int pPiece, int pRotation)
{
    return mDisplacement [pPiece][pRotation][0];
}

/*
Returns the vertical displacement of the piece that has to be applied in order for it to be in the correct position
Parameters: pPiece: piece to draw
            pRotation: 1 of the 4 possible rotations
*/

int Pieces::getYInitialPos (int pPiece, int pRotation)
{
    return mDisplacement [pPiece][pRotation][1];
}


