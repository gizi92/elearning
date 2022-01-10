#include <ncurses.h>
using namespace std;

int main(int argc, char ** argv)
{
    // initializes the screen
    // sets up memory and clears the screen
    initscr();

    int height, width, start_y, start_x;
    height = 10;
    width = 20;
    start_y = start_x = 5;

    WINDOW *win = newwin(height, width, start_y, start_x);
    refresh();

    box(win, 0, 0);
    mvwprintw(win, 2, 2,"this is my box");
    wrefresh(win);

    // waits for user input, returns int value of that key
    getch();
    
    endwin();
    // deallocate memory and ends ncurses

    return 0;
}