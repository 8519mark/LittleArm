#include <ncurses.h>


int main() {

  // initilize the scree + allocate memeory + clear screen
  initscr();
  // cbreak(); // can break with crtl + C --> default
  // raw(); // take all input as raw value
  // noecho(); // user input does not show


  // print string, const char *, to a window
  // printw("Hello Wolrd"); 

  // refresh to match screen IN MEMORY
  refresh();

  // create a window
  int height = 10;
  int width = 20;
  int start_y = 10;
  int start_x = 10;
  WINDOW * win = newwin(height, width, start_y, start_x);
  refresh(); // refresh the entire screen to acknowledge it is created
  // create a box AROUND the WINDOW
  box(win, 0, 0);
  wrefresh(win); // refresh the specific window since we do the box()
  /*
  value is changed here in MEMORY, but the screen is still oblivioud of this change 
  --> refresh
  */


  // wprintw(win, "Hello Window"); 
  wrefresh(win);



  int x, y, xBeg, yBeg, xMax, yMax;
  getyx(stdscr, y, x);
  getbegyx(stdscr, yBeg, xBeg);
  getmaxyx(stdscr, yMax, xMax);

  int wx, wy, wxBeg, wyBeg, wxMax, wyMax;
  getyx(win, wy, wx);
  getbegyx(win, wyBeg, wxBeg);
  getmaxyx(win, wyMax, wxMax);

  printw("%d %d %d %d %d %d \n", x, y, xBeg, yBeg, xMax, yMax);
  printw("%d %d %d %d %d %d \n", wx, wy, wxBeg, wyBeg, wxMax, wyMax);

  refresh();
  // user input
  int userInputC = wgetch(win);
  if (userInputC == 'j') {
    mvwprintw(win, 1, 1, "you press j");
    wrefresh(win);
  } else {
    mvwprintw(win, 1, 1, "you did not press j");
    wrefresh(win);
  }


  // wait for user input, return INT value of key
  getch();

  // deallocate memeory + end ncurses
  endwin();
  

  return 0;
}