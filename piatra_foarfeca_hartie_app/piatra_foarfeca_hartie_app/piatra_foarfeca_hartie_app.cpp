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
		printf("Rock\n");
	}

	if (word == SCISSOR) {
		printf("Scissor\n");
	}

	if (word == PAPER) {
		printf("Paper\n");
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
	printf("---------------------\n");
	printf("User score: %d\n", user_score);
	printf("Computer score: %d\n", computer_score);
	printf("---------------------\n\n");
}

void game_play() {
	int user_score = 0;
	int computer_score = 0;
	srand(time(NULL));
	int turn = 1;

	while (1) {
		int user_choice;
		score_print(user_score, computer_score);
		
		printf("1 - Rock\n2 - Scissor\n3 - Paper\n\nChoose [1, 2, 3]:  ");
		scanf("%d", &user_choice);

		int computer_choice = (rand() % 3) + 1;
		system(CLEAR_SCREEN);
		printf("Computer chose: ");
		word_print(computer_choice);
		printf("User chose: ");
		word_print(user_choice);

		if (game_win(user_choice, computer_choice) == 1) {
			user_score++;
			printf("User wins this round\n\n");
			turn++;
		}
		
		if (game_win(user_choice, computer_choice) == 2) {
			computer_score++;
			//score_print(user_score, computer_score);
			printf("Computer wins this round\n\n");
			turn++;
		}

		if (game_win(user_choice, computer_choice) == 0) {
			//score_print(user_score, computer_score);
			printf("It is a draw\n\n");
			turn++;
		}

		if (turn == 10) {
			if (computer_score < user_score) {
				system(CLEAR_SCREEN);
				score_print(user_score, computer_score);
				printf("User wins the game\n\n");
				return;
			}
			else {
				if (computer_score > user_score) {
					system(CLEAR_SCREEN);
					score_print(user_score, computer_score);
					printf("Computer wins the game\n\n");
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