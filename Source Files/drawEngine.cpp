//
// Created by Ben on 3/29/21.
//
#include "../Header Files/drawEngine.h"
#include <iostream>
#include <curses.h>

DrawEngine::DrawEngine(int xSize, int ySize) {
    screenWidth = xSize;
    screenHeight = ySize;
    cursorVisibility(false);
}

DrawEngine::~DrawEngine() {
    cursorVisibility(true);
}

int DrawEngine::createSprite(int index, char c) {
    if(index >= 0 && index < 16){
        spriteImage[index] = c;
        return index;
    }
    return -1;
}

void DrawEngine::drawSprite(int index, int posx, int posy) {
    gotoxy(posx, posy);
    const char *sp = &spriteImage[index];
    printw("%c", *sp);
    refresh();
}

void DrawEngine::gotoxy(int x, int y) {
    initscr();
    move(x, y);
}

void DrawEngine::cursorVisibility(bool visibility) {
    if (visibility){
        endwin();
    }
}

void DrawEngine::eraseSprite(int posx, int posy)
{
    gotoxy(posy,posx);
    printw(" ");
    refresh();
}