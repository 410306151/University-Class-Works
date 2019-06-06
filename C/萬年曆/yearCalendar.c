#include <stdio.h>
#include <stdlib.h>
#include "myConio.h"
#include <time.h>

int fun(int year, int month, int day)
{
	int Y, y, c, d, m, w;
	if(month == 1){
		m=11;
	}else if(month == 2){
		m=12;
	}else{
		m=month-2;
	}
	Y=year-1;
	y=year%100;
	c=year/100;
	d=day;
	w=(d+(2.6*m-0.2)+y+(y/4)+(c/4)-2*c);
	while(w < 0){
		w+=7;
	}
	w=w%7;
	return w;
}

void showmonth(int attr, int fg, int bg, int year, int month, int x, int y)
{
	int x2, y2;
	
	x2=x;
	y2=y;
	gotoxy(x2, y2);
	textcolor(attr, 3, 0);
	switch(month){
		case 1: printf("一月, %d\n", year); break;
		case 2: printf("二月, %d\n", year); break;
		case 3: printf("三月, %d\n", year); break;
		case 4: printf("四月, %d\n", year); break;
		case 5: printf("五月, %d\n", year); break;
		case 6: printf("六月, %d\n", year); break;
		case 7: printf("七月, %d\n", year); break;
		case 8: printf("八月, %d\n", year); break;
		case 9: printf("九月, %d\n", year); break;
		case 10: printf("十月, %d\n", year); break;
		case 11: printf("十一月, %d\n", year); break;
		case 12: printf("十二月, %d\n", year); break;
	}
}

void showday(int attr, int fg, int bg, int firstday, int month, int x, int y, int year)
{
	int mon[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int weekday, count=1, monthday, x2, y2, b=0;
	
	
	x2=x;
	y2=y+1;
	gotoxy(x2, y2);
	textcolor(attr, 1, 0);
	printf("日 ");
	gotoxy(x2+3, y2);
	textcolor(attr, 7, 0);
	printf("一 二 三 四 五");
	gotoxy(x2+18, y2);
	textcolor(attr, 2, 0);
	printf("六");
	y2=y+2;
	monthday=mon[month];
	switch(firstday){
		case 0: textcolor(attr, 1, 0); gotoxy(x2, y2); printf("%2d ", count); weekday=1; break;
		case 1: textcolor(attr, 7, 0); gotoxy(x2+3, y2); printf("%2d ", count); weekday=2; break;
		case 2: textcolor(attr, 7, 0); gotoxy(x2+6, y2); printf("%2d ", count); weekday=3; break;
		case 3: textcolor(attr, 7, 0); gotoxy(x2+9, y2); printf("%2d ", count); weekday=4; break;
		case 4: textcolor(attr, 7, 0); gotoxy(x2+12, y2); printf("%2d ", count); weekday=5; break;
		case 5: textcolor(attr, 7, 0); gotoxy(x2+15, y2); printf("%2d ", count); weekday=6; break;
		case 6: textcolor(attr, 2, 0); gotoxy(x2+18, y2); printf("%2d ", count); weekday=7; break;
	}
	if(weekday == 7){
		b=1;
		weekday=1;
		x2=x;
		y2++;
	}
	while(count < monthday){
		count++;
		if(b == 0){
			switch(weekday+1){
				case 1: textcolor(attr, 1, 0); break;
				case 2: textcolor(attr, 7, 0); break;
				case 3: textcolor(attr, 7, 0); break;
				case 4: textcolor(attr, 7, 0); break;
				case 5: textcolor(attr, 7, 0); break;
				case 6: textcolor(attr, 7, 0); break;
				case 7: textcolor(attr, 2, 0); break;
			}
			weekday++;
			if(weekday >= 7){
				y2++;
				weekday=1;
				b=1;
				x2=x;
			}
			printf("%2d ", count);
		}else if(b == 1){
			switch(weekday){
				case 1: textcolor(attr, 1, 0); break;
				case 2: textcolor(attr, 7, 0); break;
				case 3: textcolor(attr, 7, 0); break;
				case 4: textcolor(attr, 7, 0); break;
				case 5: textcolor(attr, 7, 0); break;
				case 6: textcolor(attr, 7, 0); break;
				case 7: textcolor(attr, 2, 0); break;
			}
			gotoxy(x2, y2);
			printf("%2d", count);
			weekday++;
			x2+=3;
			if(weekday == 8){
				y2++;
				x2=x;
				weekday=1;
				b=1;
			}
		}
	}
	b=0;
}

int main(int argc, char *argv[])
{
	int year, month=1, day=1, monthday, weekday;
	int firstday, count=1, mmm, x, y, a, x3, y3;
	int press, press2;
	
	struct tm *timer;
	time_t times=time(NULL);
	timer=localtime(&times);
	year=timer->tm_year+1900;
	while(1){
		showCursor(0);
		for(month=1, x=5, y=0, x3=x, a=1; month <= 12; month++, a++){
			firstday=fun(year, month, day);
			showmonth(TC_FG_INTENSIFY, 0, 0, year, month, x, y);
			showday(TC_FG_INTENSIFY, 0, 0, firstday, month, x, y, year);
			if(a == 3){
				y+=8;
				x=x3;
				a=0;
			}else{
				x+=24;
			}
		}
		textcolor(TC_FG_INTENSIFY, 6, 0);
		gotoxy(19, 34);
		printf("Press Page Up/Down to change year");
		gotoxy(19, 35);
		printf("Press ESC to end");
		if(kbhit){
			press=getch();
			if(press == 224){
				press2=getch();
				if(press2 == 73){
					year=year-1;
					clrscr();
				}else if(press2 == 81){
					year=year+1;
					clrscr();
				}
			}else if(press == 27){
				break;
			}
		}
		count=1;
	}	
  return 0;
}
