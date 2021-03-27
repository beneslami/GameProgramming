//
// Created by Ben on 3/26/21.
//
#include "../Header Files/game.h"
#include <iostream>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
using namespace std;
struct termios orig_termios;

static void reset_terminal_mode()
{
    tcsetattr(0, TCSANOW, &orig_termios);
}

static void set_conio_terminal_mode()
{
    struct termios new_termios;

    /* take two copies - one for now, one for later */
    tcgetattr(0, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));

    /* register cleanup handler, and set the new terminal mode */
    atexit(reset_terminal_mode);
    cfmakeraw(&new_termios);
    tcsetattr(0, TCSANOW, &new_termios);
}

static int kbhit()
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

static int getch()
{
    int r;
    unsigned char c;
    if ((r = read(0, &c, sizeof(c))) < 0) {
        return r;
    } else {
        return c;
    }
}

bool Game::run(){
    char key = ' ';
    frameCount = 0;
    set_conio_terminal_mode();
    while(key != 'q'){
        while(!getInput(&key)){
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
    if(kbhit()){
        *c = getch();
        return true;
    }
    return false;
}

void Game::timerUpdate() {
    frameCount++;

}

