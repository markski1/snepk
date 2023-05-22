// fill the screen space with void.
void clear_scr() {
	int i, j;

	for (i = 0; i <= GAME_HEIGHT; ++i) {
		goto_xy(0, i);
		for (j = 0; j <= GAME_WIDTH + 15; ++j) {
			printf(" ");
		}
	}
}

void update_score()
{
	goto_xy(GAME_WIDTH + 11, 5);
	printf("%i", snk.len - SNAKE_INITIAL_LENGTH);
}

void create_game_field()
{
	printf(ANSI_COLOR_BLUE);
	clear_scr();
	int i, j;
	// print the upper and lower borders border
	goto_xy(0, 0);
	for (i = 0; i < GAME_WIDTH; ++i) {
		printf("=");
	}
	goto_xy(0, GAME_HEIGHT);
	for (i = 0; i < GAME_WIDTH; ++i) {
		printf("=");
	}

	// and the side borders, too
	for (i = 0; i < GAME_HEIGHT + 1; ++i) {
		goto_xy(GAME_WIDTH, i);
		printf("|");
		goto_xy(0, i);
		printf("|");
	}

	printf(ANSI_COLOR_RESET);

	// and off to the right, a score counter.
	goto_xy(GAME_WIDTH + 3, 5);
	printf("Score: ");

	goto_xy(GAME_WIDTH + 5, 2);
	printf(ANSI_COLOR_CYAN "SNEPK!" ANSI_COLOR_RESET);
}