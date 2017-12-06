#include <iostream>
#include <fstream>
using namespace std;


void showhistogram(int options[],char letters[]);
void fillAnswers(char question[],char answer[],int size, ifstream &openPI);
int calculateMode(char answers[], int options[], int size, int &mode);
void showMode(int mode, int response);

int main() 
{
    cout<<"Proyecto integrador!\n";
    ifstream openPI;
    ofstream savePI;
    char question[100];
    char answers[2888],answers2[362],answers3[1086],answers4[1448];
    int options[8];
    char letters[]={'A','B','C','D','E','F','G','H'};
    int sizeQ1 = 2888,sizeQ2 = 362, sizeQ3 = 1086, sizeQ4 = 1448;
    int mode = 0;
    int response;
    int opc;
    char save;
    openPI.open("c://Datos//baseDeDatos.txt");
    savePI.open("c://Datos//datoGuardado.xls",ios::trunc); 
    fillAnswers(question,answers,sizeQ1,openPI);
    fillAnswers(question,answers2,sizeQ2,openPI);
    fillAnswers(question,answers3,sizeQ3,openPI);
    fillAnswers(question,answers4,sizeQ4,openPI);

    do {
        cout<<"Introduce numero de pregunta: ";
        cin>>opc;
        if (opc==1) {
            response = calculateMode(answers,options,sizeQ1,mode);
            showMode(mode,response);
            showhistogram(options,letters);
        }
        else if(opc==2){
            response = calculateMode(answers2,options,sizeQ2,mode);
            showMode(mode,response);
            showhistogram(options,letters);
        }
        else if(opc==3){
            response = calculateMode(answers3,options,sizeQ3,mode);
            showMode(mode,response);
            showhistogram(options,letters);
        }
        else if (opc==4){
            response = calculateMode(answers4,options,sizeQ4,mode);
            showMode(mode,response);
            showhistogram(options,letters);
        }
        if(opc!=0){
        cout<<"Quiere guardar los datos?:[S/N]";
        cin>>save;
        if (save=='s'||save=='S')
            for (int i=0; i<8; i++)
                savePI<<letters[i]<<","<<options[i]<<"\n";
        }
    } while (opc!=0);
    
    openPI.close();
    savePI.close();
    return 0;
}

int calculateMode(char answers[],int options[], int size,int &mode)
{
    for (int i=0; i<8; i++)
        options[i]=0;

    for (int i=0; i<size; i++) {
        if (answers[i]=='a')
            options[0]++;
        else  if (answers[i]=='b')
            options[1]++;
        else  if (answers[i]=='c')
            options[2]++;
        else  if (answers[i]=='d')
            options[3]++;
        else  if (answers[i]=='e')
            options[4]++;
        else  if (answers[i]=='f')
            options[5]++;
        else  if (answers[i]=='g')
            options[6]++;
        else  if (answers[i]=='h')
            options[7]++;
    }
    int response=0;
    mode = 0;
    for (int j=0; j<8; j++)
        if (options[j]>mode){
            mode = options[j];
            response = j;
        }
    return response;
}


void showhistogram(int options[],char letters[])
{
    cout<<"Histograma!\n";
    for (int i=0; i<8; i++) {
        if (options[i]!=0) {
            cout<<"Respuesta "<<letters[i]<<": "<<options[i]<<"\n";
        }
    }
}


void showMode(int mode, int response)
{
    if (response==0)
        cout<<"la moda fue de: "<<mode<<" la respuesta fue la ""A"" "<<"\n";
    if (response==1)
        cout<<"la moda fue de: "<<mode<<" la respuesta fue la ""B"" "<<"\n";
    if (response==2)
        cout<<"la moda fue de: "<<mode<<" la respuesta fue la ""C"" "<<"\n";
    if (response==3)
        cout<<"la moda fue de: "<<mode<<" la respuesta fue la ""D"" "<<"\n";
    if (response==4)
        cout<<"la moda fue de: "<<mode<<" la respuesta fue la ""E"" "<<"\n";
    if (response==5)
        cout<<"la moda fue de: "<<mode<<" la respuesta fue la ""F"" "<<"\n";
    if (response==6)
        cout<<"la moda fue de: "<<mode<<" la respuesta fue la ""G"" "<<"\n";
    if (response==7)
        cout<<"la moda fue de: "<<mode<<" la respuesta fue la ""H"" "<<"\n";
}


void fillAnswers(char question[], char answer[],int size, ifstream &openPI)
{
    openPI.getline(question, 100,'\r');
    for (int i=0; i<size; i++)
    answer[i]='z';
    for (int i=0; i<size; i++)
        openPI>>answer[i];
}
