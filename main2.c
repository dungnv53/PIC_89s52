#include <REGX52.H>
#include <main.h>	
#include<stdio.h>
#include<string.h>
#include <var.h>
//=======a....d la cac bit dau vao cua 74HC47
#define a P2_0
#define b P2_1
#define c P2_2
#define d P2_3
//========thu tu led tinh tu phai qua trai
#define led1 P2_4 
#define led2 P2_5
#define led3 P2_6
#define led4 P2_7
//********Khai báo các bie^'n******************
unsigned char t1,t2,t3,t4,thu_tu_led;
//*********Ham tao do tre*******************
void delay(unsigned int ms)
  { 
    unsigned int i,j;
    for (i=0; i<ms; i++)
	  { for (j=0; j<120; j++) ;
//----------------led 7 thanh-------------------------
void display(unsigned char number)
//hie^?n thi. 1 so^' trên led 7 thanh.
//ðo^?i so^' number thành ma~ BCD
 { char x,y;
x=number/8;y=number-x*8;d=x;
x=y/4;y=y-x*4;c=x;
x=y/2;y=y-x*2;b=x;
a=y;


}
void display_led(unsigned int number,led)
{
 if(led==1)
    {P2=0xff;led1=0;}
 else if (led==2)
 	{P2=0xff;led2=0;}
 else if (led==3)
 	{P2=0xff;led3=0;}
 else if (led==4)
 	{P2=0xff;led4=0;}
 else 
 	{P2=0xff;}
 display(number);
}
void timer0_init()//dung cho ngat timer 0
 {
   TMOD&=0xF0;//0xFO=1111.0000
   TMOD|=0x01;//timer0 in mode 1(16bit)
   ET0=1;
   EA=1;   //tham khao "ho vi dieu khien 8051"
   TH0=0x00;       //Phai chu y
   TL0=0x00;     //Phai chu y
   TR0=1;
  }
void chuongtrinh_timer0 (void) interrupt 1//chuong trinh phuc vu ngat timer0
{	unsigned char hh;
	if      (thu_tu_led==1){hh=t1;}
	else if (thu_tu_led==2){hh=t2;}
	else if (thu_tu_led==3){hh=t3;}
	else                   {hh=t4;}
	display_led(hh,thu_tu_led);
	thu_tu_led= thu_tu_led+1;
	if (thu_tu_led>4){thu_tu_led=1;}
//giu nguyen	
	TH0=0xf0;
	TL0=0xf0;
	TF0=0;
	TR0=1;
}
	    
	  }
  }
main()
{//làm gi` thi` làm
//lýu y':t1,t2,t3,t4 là các giá tri. hie^?n thi. trên led 7 thanh
//co`n vie^.c ba.n la^'y giá tri. cu?a nó o+? ðâu thi` tùy ba.n
display(10);
}