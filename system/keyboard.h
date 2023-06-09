// runs on it's own thread
void * handle_keystrokes(void *ptr) {
	int i;

	for (i = 0; i < KB_BFR_SIZE; ++i) {
		movement_buffer[i] = MOVE_NONE;
	}

	while (true) {
		char input = getch();

		int entered_move = MOVE_NONE;
		
		switch (input)
		{
			case 'W':
			case 'w':
				entered_move = MOVE_UP;
				break;
			case 'S':
			case 's':
				entered_move = MOVE_DOWN;
				break;
			case 'A':
			case 'a':
				entered_move = MOVE_LEFT;
				break;
			case 'D':
			case 'd':
				entered_move = MOVE_RIGHT;
				break;
			// escape exits the game.
			case 'O':
			case 'o':
				game_over = true;
		}

		if (entered_move == MOVE_NONE)
			continue;

		for (i = 0; i < KB_BFR_SIZE; ++i) {
			if (movement_buffer[i] == MOVE_NONE) {
				// do not fill the buffer with the same keystroke, this introduces a lot of delay if a key is held down.
				if (i > 0 && movement_buffer[i - 1] == entered_move) break;
				// do not enter the current movement in the first buffer entry, this also introduces delay for meaningful inputs.
				if (i == 0) {
					if (snk.dir == entered_move) break;
				}
				movement_buffer[i] = entered_move;
				break;
			}
		}
	}
}