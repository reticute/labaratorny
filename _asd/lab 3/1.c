#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

void draw(int x, int y);

int main()
{
    initscr();
    noecho();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);

    int m, n;
    getmaxyx(stdscr, m, n);

    int yn = m - 2; 
    int xn = n - 1;

    int r = yn / 2;
    int c = xn / 2;

    if (r >= 0 && r <= yn && c >= 0 && c <= xn) {
        draw(r, c);
    }

    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};

    int h_len = 1;
    int v_len = 1; 

    int total_cells = (yn + 1) * (xn + 1);
    int drawn = 1;
    int dir = 0; 

    while (drawn < total_cells) {
        int current_len = (dir == 0 || dir == 2) ? h_len : v_len;

        for (int s = 0; s < current_len; s++) {
            r += dr[dir];
            c += dc[dir];

            if (r >= 0 && r <= yn && c >= 0 && c <= xn) {
                draw(r, c);
            }
            drawn++;
            if (drawn >= total_cells) break;
        }

        if (dir == 0 || dir == 2) {
            h_len++;
        } else {
            v_len++;
        }

        dir = (dir + 1) % 4;
    }

    getch();
    endwin();
    return 0;
}

void draw(int x, int y)
{
    attron(COLOR_PAIR(1));
    mvaddch(x, y, '#');
    refresh();
    usleep(20000);
}