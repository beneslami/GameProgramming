//
// Created by Ben on 3/26/21.
//
#include "game.h"
#include <random>
#include <stdio.h>

bool isTermAvail = true; // check this global variable before ncurses calls

int main(int argc, const char * argv[])
{
    for (int argi = 1; argi < argc; argi++)
    {
        if (isTermAvail && strcmp(argv[argi], "--debug-in-terminal") == 0)
        {
            printf("Debugging in terminal enabled\n");
            getchar(); // Without this call debugging will be skipped
            break;
        }
    }

    isTermAvail = (getenv("TERM") != NULL);

//----------------------------------

    //std::random_device r;
    //std::seed_seq seed_seq{r(), r(), r(), r(), r(), r()};
    //std::mt19937 engine{seed_seq};

    srand( (int) time( NULL ));
    //srand( (int) time( NULL ) + engine() );

    EvilMonkeys::DrawEngine drawArea;

    EvilMonkeys::Game game;
    game.run(&drawArea);

//----------------------------------

    if (isTermAvail)
    {
        nodelay(stdscr, FALSE);
        printw("\n\n Press any key to exit... \n\n");
        refresh();
        getch();
        endwin();
    }

    return 0;
}
