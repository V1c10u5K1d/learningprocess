//Заполнить двумерный массив случайными  числами от 10  до 100. Посчитать сумму элементов отдельно в каждой строке и определить номер строки,  в которой эта сумма максимальна.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	srand(time(0));
	int a,b;
	cin >> a;
	cin >> b;
	int massiv[a][b];
	int podschet[a];
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			massiv[i][j]=10+(rand()%((100-10)+1));
			cout << massiv[i][j] << " ";
		}
		cout << "\n";
	}
	
	for(int str=0; str<a; str++){
		podschet[str]=0;
	}
	
	for(int stroka=0; stroka<a; stroka++){
		for(int stolb=0; stolb<b; stolb++){
			podschet[stroka]+=massiv[stroka][stolb];
		}
		cout << "\n" << podschet[stroka] << "\n";
	}
	
	int biggest=podschet[0];
	
	for(int findmax=0; findmax<a; findmax++){
		if(podschet[findmax]>biggest){
			biggest=podschet[findmax];
			cout << "\n" << biggest << " - is biggest number that in " << findmax+1 << " row.\n";
		}
	}
	
		
  return 0;
}
  
