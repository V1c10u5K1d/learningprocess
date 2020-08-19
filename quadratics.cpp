#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class Equation{
	private:
	double A,B,C;
	
	public:
	double Disc, X1, X2;
	Equation(double a, double b, double c){
		A=a;
		B=b;
		C=c;
		Disc=0;
		X1=0;
		X2=0;
	}
		
	void CalculationDiscriminant(){
		Disc=pow(B,2)-4*A*C;
	}
	
	void CalculationRoots(){
		X1=(-B+sqrt(Disc))/2*A;
		X2=(-B-sqrt(Disc))/2*A;
	}
	
	void CalculationRoot(){
		X1=X2=-(B/2*A);
	}
	
	void IncompleteB(){
		X1=-sqrt(-(C/A));
		X2=sqrt(-(C/A));
	}
	
	void IncompleteC(){
		X1=0;
		X2=-(B/A);
	}
	
	void IncompleteBoth(){
		X1=X2=0;
	}

	~Equation(){}
};	
	
int main(){
	
	string choise;
	bool enoof;
	bool loop;
	do{
		
		double a,b,c;
		do{
			cout << "enter a, it cannot be equaled to 0\n";
			cin >> a;
			if(a==0){
				cout << "the first argument cannot be equaled to 0\n";
			}
		}while(a==0);
		cout << "enter b\n";
		cin >> b;
		cout << "enter c\n";
		cin >> c;
		cout << "eqation is:\n";
		if(b==0){
			printf("%gx^2%c%g=0\n", a,c<0?'-':'+', abs(c));
		}
		else if(c==0){
			printf("%gx^2%c%gx=0\n", a,b<0?'-':'+', abs(b));
		}
		else if(b==0&&c==0){
			printf("%gx^2=0\n", a);
		}		
		else{
			printf("%gx^2%c%gx%c%g=0\n", a,b<0?'-':'+', abs(b), c<0?'-':'+', abs(c));
		}
		
		Equation equation(a,b,c);	
		
		if(b==0){
			if(-(c/a)>0){
				equation.IncompleteB();
				cout << "the roots are: " << equation.X1 << " and " << equation.X2 << endl;
			}
			else{
				cout << "the equation has no roots.\n";
			}
		}
		
		else if(c==0){
			equation.IncompleteC();
			cout << "the roots are: " << equation.X1 << " and " << equation.X2 << endl;
		}
		
		else if(b==0&&c==0){
			equation.IncompleteBoth();
			cout << "the roots are: " << equation.X1 << " and " << equation.X2 << endl;
		}
		
		else{
			equation.CalculationDiscriminant();
			
			if(equation.Disc>0){
				equation.CalculationRoots();
				cout << "the roots are: " << equation.X1 << " and " << equation.X2 << endl;
			}
			else if(equation.Disc==0){
				equation.CalculationRoot();
				cout << "root is: " << equation.X1 << endl;
			}
			else if(equation.Disc<0){
				cout << "equation has no roots.\n";
			}
			else{
				cout << "Something's wrong...\n";
			}
		}
		
		do{	
			cout << endl << "Wanna do more?\n" << "1.Yes \n2.No" << endl;
			cin >> choise;
			if(choise=="1"){
				enoof=true;
				loop=false;
			}
			else if(choise=="2"){
				enoof=false;
				loop=false;
			}
			else{
				enoof=true;
				loop=true;
			}
		}while(loop);
	}while(enoof);
			
	return 0;
}
