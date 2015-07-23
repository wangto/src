#include <stdio.h>

#include "Schedule_UI.h"
#include "Studio_UI.h"
#include "Play_UI.h"
#include "Sale_UI.h"
#include "Seat_UI.h"
void Main_Menu(void) {
	char choice;
	do {
		printf("\n==================================================================\n");
		printf("**************** Theater Ticket Management System ****************\n");
		printf("[S]tudio Management.\n");
		printf("[P]lay Management.\n");
		printf("[T]icket Sale.\n");
		printf("[Q]Schedule\n");
		//printf("Ra[n]king and Statistics.\n");
		printf("[E]xist.\n");
        printf("[X]seat");
		printf("\n==================================================================\n");
		printf("Please input your choice:");
		fflush(stdin);
		choice = getchar();
		switch (choice) {
		case 'S':
		case 's':
			Studio_UI_MgtEntry();
			break;
		case 'P':
		case 'p':
			Play_UI_MgtEntry();
			break;
		case 'Q':
		case 'q':
            Schedule_UI_MgtEntry();
            break;
		case 'T':
		case 't':
			Sale_UI_MgtEntry();
			break;
		//case 'N':
		//case 'n':
		//	SalesAanalysis_UI_MgtEntry();
		//	break;
        case 'X':
        case 'x':
                Seat_UI_MgtEntry();
                break;
        }
	} while ('E' != choice && 'e' != choice);
}

int main()
{
    Main_Menu();
    return 0;
}
