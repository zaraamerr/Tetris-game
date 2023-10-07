/*
description: this hpp file contains code for the IO class that uses SDL in order to create the window, clear it, update the screen and take care of the keyboard input
attributions: thanks to javier lopez (javilop.com) for providing a thorough tutorial on how to build this game for beginners!
*/

#ifndef IO_HPP_
#define IO_HPP_

#ifndef LINUX
#include "SDL/include/SDL.h"							
#include "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives.h"
#else
#include <SDL/SDL.h>									
#include "SDL/SDL_GfxPrimitives/sdl_gfxprimitives.h"	
#endif
#pragma comment (lib, "SDL/lib/SDL.lib")
#pragma comment (lib, "SDL/SDL_GfxPrimitives/SDL_GfxPrimitives_Static.lib")

enum color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX}; // Colors

class IO{
    public:
        IO (); //default constructor
        void DrawRectangle(int px1, int py1, int px2, int py2, enum color pC);
	    void ClearScreen();
	    int GetScreenHeight();
	    int InitGraph();
	    int Pollkey();
	    int Getkey();
	    int IsKeyDown(int pKey);
	    void UpdateScreen();
}

#endif //IO_HPP_