#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

int main()
{
	srand(time(0));
    char mv,timepass;
    char repeat='y';
    int highscore=0;
    cout<<""<<endl;
    cout<<" --------------------------------------------------------  "<<endl;
    cout<<"|                                                        | "<<endl;
    cout<<"|   **** *    **** **** **** *   *    ***  * ***  ***    | "<<endl;
    cout<<"|   *    *    *  * *  * *  * *   *    *  * * *  * *  *   | "<<endl;
    cout<<"|   ***  *    **** **** **** *****    ***  * ***  *  *   | "<<endl;
    cout<<"|   *    *    *  * *    *      *      *  * * *  * *  *   | "<<endl;
    cout<<"|   *    **** *  * *    *      *      ***  * *  * ***    | "<<endl;
    cout<<"|                                                  v 1.0 | "<<endl;
    cout<<" --------------------------------------------------------  "<<endl;
    cout<<""<<endl<<endl;
    cout<<"Press any key to continue..."<<endl;
    timepass=getch();
    while (repeat=='y')
    {
        int score=0;
        bool val_check=true;
        int x=9;
        int Yaxis[3]; 
        int Xaxis[3]; 

        Xaxis[0]=10;
        Xaxis[1]=18;
        Xaxis[2]=27; 

        for (int i=0;i<3;i++)
            Yaxis[i]=(rand()-1)%12+2;
        string map[20][30];
        for (int i=0;i<20;i++)
        {
            for (int j=0;j<30;j++)
            {
                if ( i==0 || i==19|| j==29 || j==0)
                    map[i][j]="* ";
                else
                    map[i][j]="  ";
            }
        }
        while (val_check == true)
        {
            for (int i =0;i<3;i++)
            {
                for (int j=1;j<19;j++)
                {
                    map[j][Xaxis[i]]="  ";
                }
            }
            for (int i=0;i<3;i++) 
            {
                Xaxis[i]--;
            }
            for (int i =0;i<3;i++) 
            {
                for (int j=1;j<19;j++)
                {
                    map[j][Xaxis[i]]="* ";
                }
            }
            for (int i=0;i<3;i++) 
            {
                map[Yaxis[i]][Xaxis[i]]="  ";
                map[Yaxis[i]+1][Xaxis[i]]="  ";
                map[Yaxis[i]+2][Xaxis[i]]="  ";
                map[Yaxis[i]+3][Xaxis[i]]="  ";
                map[Yaxis[i]+4][Xaxis[i]]="  ";
            }
            for (int i=0;i<3;i++)
            {
                if (Xaxis[i]==1)
                    {Xaxis[i]=28;
                    Yaxis[i]=(rand()-1)%12+2;
                    }
            }
            map[x][3]="  ";
            if (kbhit())
            {
                mv=getch();
                x=x-3;
            }
            x++;
            if(x<1)
                x=1;
            for (int i=0;i<3;i++)
            {
                if (Xaxis[i]==3)
                    if (map[x][3]=="  ")
                        score=score+1;
                    if (map[x][3]=="* ")
                        val_check=false;
            }
            map[x][3]="& ";
            for (int i=1;i<19;i++)
            {
                map[i][1]="  ";
            }
            for (int i=0;i<20;i++)
            {
                for (int j=0;j<30;j++)
                {
                    cout << map[i][j];
                }
            cout <<endl;
            }
            cout << "Score = "<<score;
            Sleep (100);
            system ("cls");
        }
        cout << "Score = " <<score<<endl;
        if (highscore<score)
            highscore=score;
        cout << "Highscore= "<<highscore<<endl;
        cout << "retry?(y/n) = "; 
        cin >> repeat;
    }
    return 0;
}
