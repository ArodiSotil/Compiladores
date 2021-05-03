#include <iostream>

using namespace std;

int main(){

	char cadena[100];
	cin.getline(cadena,100);
	int i=0;
		
	while(cadena[i] != '\0'){
		cout << cadena[i] << endl;
		i++;
	
	}
	return 0;
}
