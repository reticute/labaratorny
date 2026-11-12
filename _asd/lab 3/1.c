#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

void draw(int x, int y);

int main()
{
    initscr();
    noecho();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);

    int m, n;
    getmaxyx(stdscr, m, n);

    int yn = m - 2; 
    int xn = n - 1;

    int total_cells = (yn + 1) * (xn + 1);
    int drawn = 0;

    int visited[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    int r = yn / 2;
    int c = xn / 2;

    if (r >= 0 && r <= yn && c >= 0 && c <= xn) {
        draw(r, c);
        visited[r][c] = 1;
        drawn++;
    }

    int dr[] = {0, -1, 0, 1};
    int dc[] = {-1, 0, 1, 0};

    int steps = 1;
    int dir = 0; 

    while (drawn < total_cells) {
        for (int i = 0; i < 2; i++) {
            for (int s = 0; s < steps; s++) {
                r += dr[dir];
                c += dc[dir];

                if (r >= 0 && r <= yn && c >= 0 && c <= xn) {
                    if (!visited[r][c]) {
                        draw(r, c);
                        visited[r][c] = 1;
                        drawn++;
                    }
                }
                if (drawn >= total_cells) break;
            }
            if (drawn >= total_cells) break;
            dir = (dir + 1) % 4;
        }
        steps++;
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
