//
// Created by Ben on 3/26/21.
//
#include "../Header Files/game.h"
#include <iostream>
#include <future>

using namespace std;

bool Game::run(){
    char key = ' ';
    frameCount = 0;
    while(key != 'q'){
        while(!getInput(&key)){
            cout << "I'm int\n";
            timerUpdate();
        }
        cout << "Here's what you pressed: " << key << endl;
        cin.ignore();
    }
    cout << frameCount << endl;
    cout << "end of the game\n";
    return true;
}
bool Game::getInput(char *c) {
    *c = getchar();
    if(*c)
        return true;
    return false;
}
void Game::timerUpdate() {
    frameCount++;

}