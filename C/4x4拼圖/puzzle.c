#include <stdio.h>
#include <stdlib.h>
#include "myConio.h"

void menu(int attr, int fg, int bg)
{
	gotoxy(5, 5);
	textcolor(attr, fg, bg);
	printf("1. New game");
	gotoxy(5, 6);
	textcolor(attr, fg, bg);
	printf("2. Change piece blackground color");
	gotoxy(5, 7);
	textcolor(attr, fg, bg);
	printf("3. Change piece forground color");
	gotoxy(5, 8);
	textcolor(attr, fg, bg);
	printf("4. Change border color");
	gotoxy(5, 9);
	textcolor(attr, fg, bg);
	printf("5. Exit");
}

void border(int attr, int fg, int bg)
{
	gotoxy(48, 4);
	textcolor(attr, fg, bg);
	printf("              ");
	gotoxy(48, 5);
	printf(" ");
	gotoxy(61, 5);
	printf(" ");
	gotoxy(48, 6);
	printf(" ");
	gotoxy(61, 6);
	printf(" ");
	gotoxy(48, 7);
	printf(" ");
	gotoxy(61, 7);
	printf(" ");
	gotoxy(48, 8);
	printf(" ");
	gotoxy(61, 8);
	printf(" ");
	gotoxy(48, 9);
	printf(" ");
	gotoxy(61, 9);
	printf(" ");
	gotoxy(48, 10);
	printf(" ");
	gotoxy(61, 10);
	printf(" ");
	gotoxy(48, 11);
	printf(" ");
	gotoxy(61, 11);
	printf(" ");
	gotoxy(48, 12);
	printf(" ");
	gotoxy(61, 12);
	printf(" ");
	gotoxy(48, 13);
	printf(" ");
	gotoxy(61, 13);
	printf(" ");
	gotoxy(48, 14);
	printf(" ");
	gotoxy(61, 14);
	printf(" ");
	gotoxy(48, 15);
	printf(" ");
	gotoxy(61, 15);
	printf(" ");
	gotoxy(48, 16);
	printf(" ");
	gotoxy(61, 16);
	printf(" ");
	gotoxy(48, 17);
	printf("              ");
}

void ground(int attr, int fg, int bg, char random[], int num, char correct[], int b)
{
    int counter, count;
    
    textcolor(attr, fg, bg);
    if(random[0] != '0'){
    	gotoxy(49, 5);
    	printf("   ");
    	gotoxy(49, 6);
    	printf(" %c ", random[0]);
    	gotoxy(49, 7);
    	printf("   ");
    }
    if(random[1] != '0'){
    	gotoxy(52, 5);
    	printf("   ");
    	gotoxy(52, 6);
    	printf(" %c ", random[1]);
    	gotoxy(52, 7);
    	printf("   ");
    }
    if(random[2] != '0'){
    	gotoxy(55, 5);
    	printf("   ");
    	gotoxy(55, 6);
    	printf(" %c ", random[2]);
    	gotoxy(55, 7);
    	printf("   ");
    }
    if(random[3] != '0'){
    	gotoxy(58, 5);
    	printf("   ");
    	gotoxy(58, 6);
    	printf(" %c ", random[3]);
    	gotoxy(58, 7);
    	printf("   ");
    }
    if(random[4] != '0'){
    	gotoxy(49, 8);
    	printf("   ");
    	gotoxy(49, 9);
    	printf(" %c ", random[4]);
    	gotoxy(49, 10);
    	printf("   ");
    }
    if(random[5] != '0'){
    	gotoxy(52, 8);
    	printf("   ");
    	gotoxy(52, 9);
    	printf(" %c ", random[5]);
    	gotoxy(52, 10);
    	printf("   ");
    }
    if(random[6] != '0'){
    	gotoxy(55, 8);
    	printf("   ");
    	gotoxy(55, 9);
    	printf(" %c ", random[6]);
    	gotoxy(55, 10);
    	printf("   ");
    }
    if(random[7] != '0'){
    	gotoxy(58, 8);
    	printf("   ");
    	gotoxy(58, 9);
    	printf(" %c ", random[7]);
    	gotoxy(58, 10);
    	printf("   ");
    }
    if(random[8] != '0'){
    	gotoxy(49, 11);
    	printf("   ");
    	gotoxy(49, 12);
    	printf(" %c ", random[8]);
    	gotoxy(49, 13);
    	printf("   ");
    }
    if(random[9] != '0'){
    	gotoxy(52, 11);
    	printf("   ");
    	gotoxy(52, 12);
    	printf(" %c ", random[9]);
    	gotoxy(52, 13);
    	printf("   ");
    }
    if(random[10] != '0'){
    	gotoxy(55, 11);
    	printf("   ");
    	gotoxy(55, 12);
    	printf(" %c ", random[10]);
    	gotoxy(55, 13);
    	printf("   ");
    }
    if(random[11] != '0'){
    	gotoxy(58, 11);
    	printf("   ");
    	gotoxy(58, 12);
    	printf(" %c ", random[11]);
    	gotoxy(58, 13);
    	printf("   ");
    }
    if(random[12] != '0'){
    	gotoxy(49, 14);
    	printf("   ");
    	gotoxy(49, 15);
    	printf(" %c ", random[12]);
    	gotoxy(49, 16);
    	printf("   ");
    }
    if(random[13] != '0'){
    	gotoxy(52, 14);
    	printf("   ");
    	gotoxy(52, 15);
    	printf(" %c ", random[13]);
    	gotoxy(52, 16);
    	printf("   ");
    }
    if(random[14] != '0'){
    	gotoxy(55, 14);
    	printf("   ");
    	gotoxy(55, 15);
    	printf(" %c ", random[14]);
    	gotoxy(55, 16);
    	printf("   ");
    }
    if(random[15] != '0'){
    	gotoxy(58, 14);
    	printf("   ");
    	gotoxy(58, 15);
    	printf(" %c ", random[15]);
    	gotoxy(58, 16);
    	printf("   ");
    }
    if(b == 1){
	    for(counter=0, count=-1; counter <= 15; counter++){
			if(random[counter] == correct[counter]){
				count++;
			}
        }
    }
    if(count == 15){
        textcolor(TC_BG_INTENSIFY, 7, 1);
        gotoxy(10, 11);
        printf("You did a good job!");
        gotoxy(10, 12);
        printf("Type any key to continue");
        getch();
        textcolor(0, 0, 0);
        clrscr();
    }
}

int main(int argc, char *argv[])
{
	int press1, press2, a, num=0, zero, position, b=0, i, j;
	int FG=0, BG=6, B_BG=5;
	char correct[16]={'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', '0'};
	char random[16]={'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', '0'};
	char hold[1];
	
	srand((unsigned) time(NULL));
	while(1){
		menu(TC_FG_INTENSIFY, 3, 0);
		border(TC_NONE, 0, B_BG);
		ground(TC_BG_INTENSIFY, FG, BG, random, num, correct, b);
		textcolor(0, 0, 0);
		showCursor(0);
		for(a=0; a <= 15; a++){
            if(random[a] == '0'){
                zero=a;
                break;
            }
        }
        b=0;
        press1=getch();
		if(press1 == 50){
			BG++;
			if(BG == 8){
				BG=0;
			}
			clrscr();
		}else if(press1 == 51){
			FG++;
			if(FG == 8){
				FG=0;
			}
			clrscr();
			}else if(press1 == 52){
			B_BG++;
			if(B_BG == 8){
				B_BG=0;
			}
		}else if(press1 == 49){
			for(i=0; i < 16; i++){
				random[i]=rand()%16;
				switch(random[i]){
					case 0: random[i]='0'; break;
					case 1: random[i]='1'; break;
					case 2: random[i]='2'; break;
					case 3: random[i]='3'; break;
					case 4: random[i]='4'; break;
					case 5: random[i]='5'; break;
					case 6: random[i]='6'; break;
					case 7: random[i]='7'; break;
					case 8: random[i]='8'; break;
					case 9: random[i]='9'; break;
					case 10: random[i]='A'; break;
					case 11: random[i]='B'; break;
					case 12: random[i]='C'; break;
					case 13: random[i]='D'; break;
					case 14: random[i]='E'; break;
					case 15: random[i]='F'; break;
				}
				for(j=0; j < i; j++){
					if(random[i] == random[j]){
						i=i-1;
						break;
					}
				}
			}
		clrscr();
		}else if(press1 == 53){
			gotoxy(10, 11);
			textcolor(TC_NONE, 0, 7);
			printf("Are you sure to exit (y/n)?");
			press2=getch();
			if(press2 == 'y' || press2 == 'Y'){
				break;
			}else{
                textcolor(0, 0, 0);
				clrscr();
			}
		}else if(press1 == 224){
            press2=getch();
            if(press2 == 72){
				if(zero-4 >= 0){
					hold[0]=random[zero];
					random[zero]=random[zero-4];
   	            	random[zero-4]=hold[0];
				}
            }else if(press2 == 80){
				if(zero+4 <= 15){
					hold[0]=random[zero];
					random[zero]=random[zero+4];
   	            	random[zero+4]=hold[0];
				}
            }else if(press2 == 75){
				if(zero/4 == 0 && zero-1 >= 0){
					hold[0]=random[zero];
					random[zero]=random[zero-1];
   	            	random[zero-1]=hold[0];
				}else if(zero/4 == 1 && zero-1 >= 4){
					hold[0]=random[zero];
					random[zero]=random[zero-1];
   	            	random[zero-1]=hold[0];
				}else if(zero/4 == 2 && zero-1 >= 8){
					hold[0]=random[zero];
					random[zero]=random[zero-1];
   	            	random[zero-1]=hold[0];
				}else if(zero/4 == 3 && zero-1 >= 12){
					hold[0]=random[zero];
					random[zero]=random[zero-1];
   	            	random[zero-1]=hold[0];
				}
            }else if(press2 == 77){
				if(zero/4 == 0 && zero+1 <= 3){
					hold[0]=random[zero];
					random[zero]=random[zero+1];
   	            	random[zero+1]=hold[0];
				}else if(zero/4 == 1 && zero+1 <= 7){
					hold[0]=random[zero];
					random[zero]=random[zero+1];
   	            	random[zero+1]=hold[0];
				}else if(zero/4 == 2 && zero+1 <= 11){
					hold[0]=random[zero];
					random[zero]=random[zero+1];
   	            	random[zero+1]=hold[0];
				}else if(zero/4 == 3 && zero+1 <= 15){
					hold[0]=random[zero];
					random[zero]=random[zero+1];
   	            	random[zero+1]=hold[0];
				}
            }
            b=1;
            clrscr();
        }
	}
  return 0;
}
