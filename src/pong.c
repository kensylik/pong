// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI

#include <stdio.h>

void fieldStart();
void fieldPlay();

int main(void) {
    //   int row = 25;
    //   int column = 80;
    int r_rocket = 12;
    int l_rocket = 12;
    fieldStart();
    char input_key;
    
    while (1) {
        scanf("%c", &input_key);
        switch (input_key) {
            case ('k'):
                if(r_rocket - 1 > 1){
                    r_rocket--;
                }   
                break;
            case 'm':
                if(r_rocket + 1 <= 22){
                    r_rocket++;
                }
                break;
            case 'a':
                if(l_rocket - 1 > 1){
                    l_rocket--;
                }
                break;
            case 'z':
                if(l_rocket + 1 <= 22){
                    l_rocket++;
                }
                break;
            default:
                scanf("%c", &input_key);
                break;
        }
        scanf("%c", &input_key);
        fieldPlay(r_rocket, l_rocket);
    }

    return 0;
}

void fieldStart() {
    for (int l_row = 1; l_row <= 25; l_row++) {
        for (int l_col = 1; l_col <= 80; l_col++) {
            if (l_row == 1 || l_row == 25) {
                printf("%c", '-');

            } else if ((l_col == 1 || l_col == 80) && l_row >= 12 && l_row <= 14) {
                printf("%c", '|');
            } else {
                printf("%c", ' ');
            }
        }
        printf("%c", '\n');
    }
}
void fieldPlay(int r_rocket, int l_rocket) {
    for (int l_row = 1; l_row <= 25; l_row++) {
        for (int l_col = 1; l_col <= 80; l_col++) {
            if (l_row == 1 || l_row == 25) {
                printf("%c", '-');

            } else if ((l_col == 1) && l_row >= l_rocket && l_row <= l_rocket + 2) {
                printf("%c", '|');
            } else if ((l_col == 80) && l_row >= r_rocket && l_row <= r_rocket + 2) {
                printf("%c", '|');
            } else {
                printf("%c", ' ');
            }
        }
        printf("%c", '\n');
    }
}
