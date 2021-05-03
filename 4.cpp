#include <iostream>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <cstdio>
#include <fstream>
using namespace std;

bool esCaracter(char a){
	char caracter[5]={"+-*/"};
	for (int i = 0; i < 4; ++i)
	{     
		if (a==caracter[i])
		{
			return true;
		}
	}
	return false;
}
bool esPalabra(char a[],int tam){
	int es=1;
	for (int i = 0; i < tam; ++i)
	{
		if (!isalpha(a[i]))
		{
			return false;
		}

	}
	return true;
}
bool esNumero(char a[],int tam){
	int es=1;
	for (int i = 0; i < tam; ++i)
	{
		if (isdigit(a[i]) == 0)
		{
			return false;
		}

	}
	return true;
}

void identificar(){
	string entrada;
	
	vector<string> vocablo;
	vector<int> tipo;//1=palabra 2=numero 3=caracterespecial
	int it=0,pos=0;
	int asa=0;
	ifstream archivo("archivo.txt");
	if (archivo.is_open())
	{
		while(!archivo.eof()){
			getline(archivo,entrada);
			entrada+='\n';
			char aux[100];
			while(entrada[it]!='\0'){
				if (entrada[it]==' ' || entrada[it]=='\n' || entrada[it]=='	')
				{
					aux[pos]='\0';
					if(entrada[it+1]==' ' || entrada[it+1]=='\n' || pos==0){
						it++;
						continue;
					}
					if (entrada[it]=='\n'&& pos==0)
					{
						break;
					}
					else if (esPalabra(aux,pos))
					{
						tipo.push_back(1);
					}
					else if (esNumero(aux,pos))
					{
						tipo.push_back(2);
					}
					else if (esCaracter(*aux))
					{
						tipo.push_back(3);
					}
					else{
						tipo.push_back(4);

					}
					pos=0;
					vocablo.push_back(aux);

				}
				else{

					aux[pos]=entrada[it];
					pos++;
					

				}

				it++;
			}
			it=0;
			pos=0;
		}
	}
	else{
		cout << "ERROR AL ABRIR EL ARCHIVO\n";
		return;
	}
	archivo.close();

	for (int i = 0; i < tipo.size(); ++i)
	{
		switch(tipo[i]){
			case 1:
				cout<<"PALABRA: "<<vocablo[i]<<endl;
			break;
			case 2:
				cout <<"NUMERO: "<<vocablo[i]<<endl;
			break;
			case 3:
				cout <<"CARACTER_ESPECIAL: "<<vocablo[i]<<endl;
				//imprimir(a);
			break;
			default:
				cout <<"ERROR: "<<vocablo[i]<<endl;	
		}
	}
}

int main(int argc, char const *argv[])
{
	identificar();

	return 0;
}