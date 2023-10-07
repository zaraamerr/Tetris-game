/*
description: this hpp file contains the class for all the tetris pieces, their respective rotations, as well as, displacements for the hotspot.
attributions: thanks to javier lopez (javilop.com) for providing a thorough tutorial on how to build this game for beginners!
*/

#ifndef PIECES_HPP
#define PIECES_HPP

class Pieces{
    public:
        int getBlockType (int pPiece, int pRotation, int px, int py);
        int getXInitialPos (int pPiece, int pRotation);
        int getYInitialPos (int pPiece, int pRotation);
};

#endif //PIECES_HPP