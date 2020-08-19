//Преобразовать строки двумерного массива в столбцы. 
//Класс будет содержать два метода: один заполнит массив значениями, второй произведет замену значений строк на значения столбцов.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Perevertos{
	int** mainarray;
	int** swapper;
	public:
	int r, c;
	Perevertos(int rows, int columns){
		r=rows;
		c=columns;
	}
	void alocatingmainmemory(){
		mainarray=new int*[r];
		for(int i=0; i<r; i++){
			mainarray[i]=new int[c];
		}
	}
	
	void filling(){
		cout << endl;
		for(int x=0; x<r; x++){
			for(int y=0; y<c; y++){
				mainarray[x][y]=0+(rand()%((100-10)+1));
				cout <<  mainarray[x][y] << " ";
			}
			cout << endl;
		}
	}
	
	void alocatingswappermemory(){
		swapper=new int*[c];
		for(int j=0; j<c; j++){
			swapper[j]=new int[r];
		}
	}
	
	void copystuff(){
		for(int a=0; a<c; a++){
			for(int b=0; b<r; b++){
				swapper[a][b]=mainarray[b][a];
			}
		}
	}
	
	void deletedis(){
		for(int n=0; n<r; n++){
			delete[] mainarray[n];
		}
		delete[] mainarray;
	}		
	
	void allocatingmainagain(){
		mainarray=new int*[c];
		for(int m=0; m<c; m++){
			mainarray[m]=new int[r];
		}
	}		
	
	void pastestuff(){
		cout << "\nswapped array: \n";
		for(int q=0; q<c; q++){
			for(int w=0; w<r; w++){
				mainarray[q][w]=swapper[q][w];
				cout << mainarray[q][w] << " ";
			}
			cout << endl;
		}
	}
	
	void deleteswapper(){
		for(int e=0; e<c; e++){
			delete[] swapper[e];
		}
		delete[] swapper;
	}
	
};

int main(){
 	srand(time(0));
	int r,c;
	cout << "rows" << endl;
	cin >> r;
	cout << "columns" << endl;
	cin >> c;
	Perevertos BigSwap(r,c);
	
	BigSwap.alocatingmainmemory();
	BigSwap.filling();
	BigSwap.alocatingswappermemory();
	BigSwap.copystuff();
	BigSwap.deletedis();
	BigSwap.allocatingmainagain();
	BigSwap.pastestuff();
	BigSwap.deleteswapper();
	
	
	 return 0;
}
