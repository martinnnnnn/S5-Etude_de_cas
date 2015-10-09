//
//  main.c
//  Ruzzle_XCODE
//
//  Created by Martin on 09/10/2015.
//  Copyright © 2015 Martin. All rights reserved.
//

#include <stdio.h>
#include <SDL/SDL.h>
/*
 * Lesson 0: Test to make sure SDL is setup properly
 */

int main (int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
            return 1;
    }
    SDL_Quit();
    return 0;
}