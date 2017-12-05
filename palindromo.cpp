#include <iostream>
#include <string>
using namespace std ;
int igualacion(char frase[]);
int longitud(char c[]);
	
int main ()
{
	
	char palindromo[35] ;
	int res ;
	
	cout << "Ingresa texto: " << endl ;
	cin.getline(palindromo , 35 , '\n');

	res = igualacion(palindromo) ;
	if (res == 1)
		cout << "Tu texto no es palindromo" << endl ;
	else 
		cout << "Tu texto es palindromo" << endl ; 
	
	return 0 ;
}

int igualacion(char palindromo[])
{
	int cont = 0 , p1 = 0 , p2 = longitud(palindromo)-1;
	
	while(p2 >= p1)
	{
		if (palindromo[p1] == 32)
			p1 += 1 ;
		if (palindromo[p2] == 32 )
			p2 -= 1 ;
			
		if (palindromo[p1] == palindromo[p2])
			cont++ ;
		else
			return 1 ;
		p1++;
		p2--;
	}
	
	
		return cont ;
} 

int longitud(char palabra[])
{
	int cont = 0 ;
	for ( ; palabra[cont]; cont++);
	return cont ;
}
