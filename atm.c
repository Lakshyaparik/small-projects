#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int amount=1000,td=0,tw=0,tt=0;
int menu()
{   int ch;
    printf("PRESS 1 FOR DEPOSIT");
    printf("\nPRESS 2 FOR FOR WITHDRAW");
    printf("\nPRESS 3 FOR TRANSFER");
    printf("\nPRESS 4 FOR DETAIL");
    printf("\nPRESS 5 FOR EXIT");
    printf("\n\nENTER YOUR CHOICE:");
    scanf("%d",&ch);
    return ch;

}

void deposit()
{   int d;
    printf("ENTER HOW MUCH AMOUNT U WANT DEPOSIT=");
    scanf("%d",&d);
    amount+=d;
    td+=d;
}
void withdraw()
{   int w;
    printf("ENTER HOW MUCH AMOUNT U WANT WITHDRAW=");
    scanf("%d",&w);
    amount-=w;
    tw+=w;
}
void transfer()
{   int t;
    printf("ENTER HOW MUCH AMOUNT U WANT TRANSFER=");
    scanf("%d",&t);
    tt=tt+t;
    amount-=t;
    
}
void detail()
{
    printf("YOUR BANK BALANCE IS %d",amount);
    printf("\nYOUR TOTAL DEPOSIT AMOUNT IS:%d",td);
    printf("\nYOUR TOTAL WITHDRAW AMOUNT IS:%d",tw);
    printf("\nYOUR TOTAL TRANSFER AMOUNT IS:%d",tt);

}

void main()
{
  while (1)
  { system("cls");
   switch (menu())
    {
    case 1: deposit();
            break;
    case 2: withdraw();
            break;
    case 3: transfer();
            break;
    case 4: detail();
            break;
    case 5: exit(0);
            break;
    
    default: printf("INVALID CHOICE");
            break;
    }
    getch();
  }
}

