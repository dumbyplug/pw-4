#include "game.c"

int main() {
	srand(time(NULL));  // Initialize randomness once
	char run = 1;
	int choice = 3;
	char buffer;
	char player_char = '*';

	while(run){
		printf("+------ Connect 4 ------+\n"
			   "|      (1) Start        |\n"
			   "|      (2) About        |\n"
			   "|      (0) Exit         |\n"
			   "+-----------------------+\n"
			   "Choose option: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf(
				"+----------------------------+\n"
				"|   (1) Player vs Player     |\n"
				"|   (2) Player vs Computer   |\n"
				"|   (0) Back                 |\n"
				"+----------------------------+\n"
				"Choose option: ");
				scanf("%d", &choice);
				while(1){
					switch(choice){
						case 1:
							player_char = game(player_char);
							break;
						case 2:
							game_vs_ai(player_char);
							break;
						case 0:
							break;
						default:
							printf("\n =>> Error. Undefined option <<==\n");
					}
					printf("Want to play again?[Y/n]: ");
					scanf(" %c", &buffer);
					if((buffer == 'N') || (buffer == 'n'))
						break;
				}
				break;





			case 2:
				printf("\nThis program is created by\n"
				"Ayhan Safarov, Tural Haji-Nabili, Ilaha Algayeva and Zaur Valiyev\n\n"
				"While making of this project, even though caused problems, GitHub was used\n"
				"Program was made to work in both Windows and Linux terminals\n"
				"Please support us on our patreon...\n\n");
				break;





			case 0:
				run = 0;
				break;



			default:
				printf("\n =>> Error. Undefined option <<==\n");
		}
	}

	return 0;
}
