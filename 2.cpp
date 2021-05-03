#include <iostream>
#include <cstdio>

using namespace std;

int main ()
{
	freopen ("file.txt", "r", stdin);
	char cadena;
	while ((cadena = getchar ())!= EOF)
	{
		cout << cadena <<endl;
	}
	fclose (stdin);
	return 0;
}
