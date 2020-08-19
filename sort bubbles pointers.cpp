//Напишите сортировку массива указателей.
//Т.е. чтоб ptrArr содержал адреса, которые сначала указывают на минимальные элементы arr, а потом на все больше и больше
#include <iostream>
#include <utility>
using namespace std;

int main(){
	int arr[10]{1,9,8,6,7,2,4,5,3,10};
	int* ptrArr[10];
	
	for(int run=0; run<10; run++){						//run - кол-во проходов проверок
		bool sorted=true;								//проверка сортировки
		for(int num=0; num<10-(run+1); num++){			//num выбирает позицию числа в массиве
			if(arr[num]>arr[num+1]){
				sorted=false;							//если проверка на сортировка провалена, числа в не верном порядке
				swap(arr[num], arr[num+1]);				//свап местами
				
			}
		}
		if(sorted){										//остановка цикла при верной сортировке
			break;
		}
	}
	
	for(int ptrrun=0; ptrrun<10; ptrrun++){				
		ptrArr[ptrrun]=&arr[ptrrun];
		cout << arr[ptrrun] << "\t" << ptrArr[ptrrun] << endl;		//вывод элементов массива и их адресов
	}
}
