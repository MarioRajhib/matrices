#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int menu();
void log (float n, float lim);
void seno (float n,float lim);
void coseno (float n,float lim);
int main()
{
    int op;
    float num, lim;
    do
    {
        op=menu();
        switch(op)
        {
            case 1:
                cout<<"x=";
                cin>>num;//corrige esta linea
                cout<<"limite=";
                cin>>lim;
                log(num, lim);
                break;
            case 2:
                cout<<"x=";
                cin>>num;
                cout<<"limite=";
                cin>>lim;
                seno(num, lim);
                break;
            case 3:
                cout<<"x=";
                cin>>num;
                cout<<"limite=";
                cin>>lim;
                coseno(num, lim);
                break;
        }
    } while(op!=0);
    cout<<"adios...";

}

int menu()
{
    int op;
    do
    {
        cout<<"MENU\n";
        cout<<"1-Logaritmo natural\n";
        cout<<"2-Seno\n";
        cout<<"3-Coseno\n";
        cout<<"0-Salir\n";
        cin>>op;
        cout<<endl;
        system("pause");
        system("cls");
    } while(op>=0 && op>4);
    return op;
}

void log (float n,float lim)
{
    float sum=0, suma=0, p=0;
    for(int i=1; i<=lim; i++)
    {
        p=(n-1)/n;
        sum=pow(p,i);
        sum=sum*(1/i);
        suma+=sum;
    }
    cout<<"logaritmo igual a:"<<suma<<endl;
    system("pause");
    system("cls");

}

void seno (float n,float lim)
{
    float sum=n, suma=3, elev, po=3, fact=1, menos=1;
    for(float i=1; i<=lim; i++)
    {
        elev=pow(n,po);
        po+=2;
        fact=1;
        for(int j=1; j<=suma; j++)
        {
            fact*=j;
        }
        if(menos==1)
        {
            menos++;
            sum+=(elev/fact)*-1;
        }
        else
        {
            menos=1;
            sum+=(elev/fact);
        }
        suma+=2;

    }
    cout<<"el seno es igual a:"<<sum<<endl;
    system("pause");
    system("cls");
}

void coseno (float n,float lim)
{
    float sum=1, suma=2, elev, po=2, fact=1, menos=1;
    for(float i=1; i<=lim; i++)
    {
        elev=pow(n,po);
        po+=2;
        fact=1;
        for(int j=1; j<=suma; j++)
        {
            fact*=j;
        }
        if(menos==1)
        {
            menos++;
            sum+=(elev/fact)*-1;
        }
        else
        {
            menos=1;
            sum+=(elev/fact);
        }
        sum+=2;

    }
    cout<<"el coseno es igual a:"<<sum<<endl;
    system("pause");
    system("cls");
}



