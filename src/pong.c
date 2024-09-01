// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI

#include <stdio.h>

void fieldStart( int y_ball, int x_ball);
void fieldPlay(int r_rocket, int l_rocket, int y_ball, int x_ball);
void clear();
//void Ball(int x, int y);

//void checkPoint();
int main(void) {
    //   int row = 25;
    //   int column = 80;
    int r_rocket = 12;
    int l_rocket = 12;
   
    int y_ball=13;
    int x_ball = 40;
    int vectorX=1;
    int vectorY=1;
    char input_key;
    fieldStart(y_ball, x_ball);
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
                printf("ERROR: enter correct characters");
                scanf("%c", &input_key);

                break;
        }
        scanf("%c", &input_key);
        fieldPlay(r_rocket, l_rocket,x_ball,y_ball);
        //clear();
        //Ball(y_ball, x_ball);
       
            if((x_ball ==0 || x_ball == 80-1) && ((y_ball >= r_rocket+1 && y_ball <= r_rocket +3)||(y_ball >= l_rocket+1 && y_ball <= l_rocket +3))){
                vectorX = -vectorX;
            }else if(x_ball <0 || x_ball > 80){
                return 1;
            }
            if(y_ball <= 2|| y_ball >= 24){
                vectorY = -vectorY;
            } 
            y_ball += vectorY;
            x_ball += vectorX;
            printf("%d %d\n", y_ball, x_ball);
            printf("%d %d", l_rocket, r_rocket);
    }
    
    return 0;
}

void clear(){
    printf("\033[H");
}

// void Ball(int x, int y){

//     for (int l_row = 1; l_row <= 25; l_row++) {
//         for (int l_col = 1; l_col <= 80; l_col++) {
//             if(l_row==y && l_col == x){
//                 printf("%c",'*');
//             }else{
//                 printf("%c", ' ');
//             }
//                printf("\n");
//         }
//     }
// }


// else if(l_col == 20 && l_row == 5 ){
//                 printf("%d", l_counter);
//             }else if(l_col == 60 && l_row == 5 ){
//                 printf("%d", r_counter);

//             }

void fieldStart( int y_ball, int x_ball) {
    for (int l_row = 1; l_row <= 25; l_row++) {
        for (int l_col = 1; l_col <= 80; l_col++) {
            if (l_row == 1 || l_row == 25) {
                printf("%c", '#');
            }else if((l_col == (80/2)) && (l_row > 2 && l_row < 24 && l_row != 13)){
                printf("%c", '|');

            } else if ((l_col == 1 || l_col == 80) && l_row >= 12 && l_row <= 14) {
                printf("%c", '|');
            }else if(l_row == y_ball && l_col == x_ball){
                printf("%c", '*');
            }else{
                printf("%c", ' ');
            }
        }
        printf("%c", '\n');
    }
}
void fieldPlay(int r_rocket, int l_rocket, int y_ball, int x_ball) {
     
    for (int l_row = 1; l_row <= 25; l_row++) {
        for (int l_col = 1; l_col <= 80; l_col++) {
            if (l_row == 1 || l_row == 25) {
                printf("%c", '#');
            } else if ((l_col == 1) && l_row >= l_rocket && l_row <= l_rocket + 2) {
                printf("%c", '|');
            } else if ((l_col == 80) && l_row >= r_rocket && l_row <= r_rocket + 2) {
                printf("%c", '|');
            }else if((l_col == (80/2)) && (l_row > 2 && l_row < 24 && l_row != 13)){
                printf("%c", '|');
            }else if(l_row==x_ball && l_col == y_ball){
                printf("%c",'*');
            }else {
                printf("%c", ' ');
            }
        }
        printf("%c", '\n');
    }

}
