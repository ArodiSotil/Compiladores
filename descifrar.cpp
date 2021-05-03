#include <iostream>
#include <ctype.h>
#include <vector>
#include <fstream>

using namespace std;

char alfabetoMay[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char alfabetoMIN[27]="abcdefghijklmnopqrstuvwxyz";

void decifrar(){
	ifstream f( "texto.txt" );
	string entrada;
	string aux;
	int clave;
	cout << "Clave:";cin >>clave;
	int it=0,pos,opc;
	if (f.is_open())
	{
		while(!f.eof()){
			getline(f,entrada);
			while(entrada[it]!='\0'){
				if (isalpha(entrada[it]))
				{
					for (int i = 0; i < 26; ++i)
					{
						if (entrada[it]==alfabetoMIN[i])
						{
							entrada[it]=alfabetoMIN[((i-clave)%26+26)%26];
							break;
						}
						else if (entrada[it]==alfabetoMay[i])
						{
							entrada[it]=alfabetoMay[((i-clave)%26+26)%26];
							break;
						}
					}
				}
				it++;
			}
			aux+=entrada+'\n';
			it=0;
		}
	}
	f.close();
	ofstream f2("texto.txt");
	f2 <<aux;
	f2.close();
	cout << aux;
}


int main(int argc, char const *argv[])
{
	decifrar();

		
	return 0;
}