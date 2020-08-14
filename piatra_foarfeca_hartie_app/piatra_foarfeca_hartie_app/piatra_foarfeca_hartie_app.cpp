#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 1
#define SCISSOR 2
#define PAPER 3

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif


void word_print(int word) {
	if (word == ROCK) {
		printf("\033[0;31mRock\n\033[0m\n");
	}

	if (word == SCISSOR) {
		printf("\033[0;33mScissor\n\033[0m\n");
	}

	if (word == PAPER) {
		printf("\033[0;34mPaper\n\033[0m\n");
	}
}

int game_win(int player1, int player2) {
	if (player1 == ROCK && player2 == SCISSOR) {
		return 1;
	}
	else {
		if (player1 == ROCK && player2 == PAPER) {
			return 2;
		}
		else {
			if (player1 == SCISSOR && player2 == ROCK) {
				return 2;
			}
			else {
				if (player1 == SCISSOR && player2 == PAPER) {
					return 1;
				}
				else {
					if (player1 == PAPER && player2 == ROCK) {
						return 1;
					}
					else {
						if (player1 == PAPER && player2 == SCISSOR) {
							return 2;
						}
						else {
							return 0;
						}
					}
				}
			}
		}
	}
}

void score_print(int user_score, int computer_score) {
	printf("\033[0;36m* * * * * * * * * * * *\n\033[0m");
	printf("\033[0;36m*  User score: %d      *\n\033[0m", user_score);
	printf("\033[0;36m*  Computer score: %d  *\n\033[0m", computer_score);
	printf("\033[0;36m* * * * * * * * * * * *\n\n\033[0m");
}

void game_play() {
	int user_score = 0;
	int computer_score = 0;
	srand(time(NULL));
	int turn = 1;

	while (1) {
		score_print(user_score, computer_score);
		int user_choice;
		printf("\033[0;31m1 - Rock\n\033[0m\033[0;33m2 - Scissor\n\033[0m\033[0;34m3 - Paper\n\n\033[0m\033[1;32mChoose 1, 2 or 3: \033[0m");
		scanf("%d", &user_choice);
		do {
			if (user_choice < 1 || user_choice > 3) {
				printf("\033[1;32mYou are out of range, try again. Choose 1, 2 or 3: \033[0m");
				scanf("%d", &user_choice);
			}
		} while (user_choice < 1 || user_choice > 3);

		system(CLEAR_SCREEN);
		int computer_choice = (rand() % 3) + 1;
		printf("\033[1;32mComputer chose: \033[0m");
		word_print(computer_choice);
		printf("\033[1;35mUser chose: \033[0m");
		word_print(user_choice);

		if (game_win(user_choice, computer_choice) == 1) {
			user_score++;
			printf("\033[1;35mUser wins this round\n\n\033[0m");
			turn++;
		}

		if (game_win(user_choice, computer_choice) == 2) {
			computer_score++;
			printf("\033[1;32mComputer wins this round\n\n\033[0m");
			turn++;
		}

		if (game_win(user_choice, computer_choice) == 0) {
			printf("It is a draw\n\n");
			turn++;
		}

		if (turn == 8) {
			if (computer_score < user_score) {
				system(CLEAR_SCREEN);
				score_print(user_score, computer_score);
				printf("\033[1;35mUser wins the game\n\n\033[0m");
				return;
			}
			else {
				if (computer_score > user_score) {
					system(CLEAR_SCREEN);
					score_print(user_score, computer_score);
					printf("\033[1;32mComputer wins the game\n\n\033[0m");
					return;
				}
				else {
					if (computer_score == user_score) {
						system(CLEAR_SCREEN);
						score_print(user_score, computer_score);
						printf("It is a draw\n\n");
						return;
					}
				}
			}
		}
	}
}

int main() {
	int a;
	game_play();
	while (1) {
		printf("\033[1;36mDo you want to play again? Choose 1 for YES or 0 for NO \033[0m");
		scanf("%d", &a);

		if (a == 1) {
			system(CLEAR_SCREEN);
			game_play();
		}
		else {
			if (a == 0) {
				return 0;

			}
		}
	}
}