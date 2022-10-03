#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define DX 3

static void read_file(FILE *f, WINDOW *win) {
	int c = 0;
	char lines_arr[COLS-2*DX];
	char **lines = NULL;
	int i, str_count, count = 0;

	while(fgets(lines_arr, COLS-2*DX, f)){
		lines = realloc(lines, sizeof(*lines)*(count+1));
		lines[count] = strdup(lines_arr);
		count++;
	}

	for(i=0;i<LINES-2*DX-3;++i){
		wprintw(win,"\t%s", lines[i]);
	}
	str_count = 2;

	while((c = wgetch(win)) != 27) {
		if (c == ' ') {
			werase(win);
			wprintw(win, "\t\n");
			while(i<(str_count*(LINES-2*DX-3)) && i<count){
				wprintw(win, "\t%s", lines[i]);
				++i;
			}
			str_count++;
		}

                box(win, 0, 0);
                wrefresh(win);
        }
	for (i = 0; i<count; i++) {
		free(lines[i]);
	}
	free(lines);
}

int main(int argc, char **argv) {
	
	if (argc > 2) {
		printf("No file name passed\n");
		exit(1);
	}

        WINDOW *win;
        FILE *f;
	f = fopen(argv[1], "r");
	if (f == NULL) {
		printf("The file %s could not be opened\n", argv[1]);
	}

	initscr();
        noecho();
        cbreak();
        printw("FILENAME: %s", argv[1]);
        refresh();

        win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);
        keypad(win, TRUE);
        scrollok(win, TRUE);
        box(win, 0, 0);
        wmove(win, 1, 0);

	read_file(f, win);

	fclose(f);
        endwin();
	return 0;
}
