#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <sstream>
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

class FromFile{
	public:
	string type;
	string roots;
	string disc;
	FromFile(string t, string r, string d){
		type=t;
		roots=r;
		disc=d;
	}
	double buff[3];
	ifstream file;
	ofstream filew;
	 void choiseFile(){
		 file.open("/home/sid/Рабочий стол/progs/quadratics/numbersfile.txt");
		 if(file.is_open()){
			cout << "file is opened\n";
		}
		else{
			cout << "file is not found\n\n";
			exit(-1);
		}
	}
	
	void readingFile(){
		file >> buff[0] >> buff[1] >> buff[2];
	}
	
	void writeLog(){
		filew.open("/home/sid/Рабочий стол/progs/quadratics/log.txt", ios_base::app);
		filew << type << disc << roots;
		filew.close();
	}
	
	void writeLogIncomplete(){
		filew.open("/home/sid/Рабочий стол/progs/quadratics/log.txt", ios_base::app);
		filew << type << roots;
		filew.close();
	}
	
}; 

int main(){
	string message;
	string choise;
	stringstream type;
	stringstream roots;
	stringstream disc;
	bool enoof;
	bool loop;
	bool ent;
	double a,b,c;
	FromFile FFile(type.str(), roots.str(), disc.str());
	do{
		do{
			cout << "\033[2J\033[1;1HEntering values from:\n 1.File\n 2.Manually\n 3.Close this programm\n";
			cin >> message;
			if(message=="1"){
			FFile.choiseFile();
			FFile.readingFile();
			a=FFile.buff[0];
			b=FFile.buff[1];
			c=FFile.buff[2];
			}
			else if(message=="2"){	
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
			ent=false;
			}
			else if(message=="3"){
				exit(0);
			}
			else{
				cout << "Error, unknown choise...\n";
				ent=true;
			}
		}while(ent);
		
		if(a==0){
			cout << "a cannot be equaled to 0\n";
			exit(-1);
		}
		
		for(int calc=0; calc<3; calc++){	
			cout << "equation is:\n";
			if(b==0&&c==0){
				//printf("%gx^2=0\n", a);
				type.str("");
				type.clear();
				type << a << "^2=0" << endl;
				cout << type.str();
			}	
			else if(b==0){
				//printf("%gx^2%c%g=0\n", a,c<0?'-':'+', abs(c));
				type.str("");
				type.clear();
				type << a << "x^2" << (c<0?'-':'+') << abs(c) << "=0" << endl;
				cout << type.str();
			}
			else if(c==0){
				//printf("%gx^2%c%gx=0\n", a,b<0?'-':'+', abs(b));
				type.str("");
				type.clear();
				type << a << "x^2" << (b<0?'-':'+') << abs(b) << "x" << "=0" << endl;
				cout << type.str();
				
			}	
			else{
				//printf("%gx^2%c%gx%c%g=0\n", a,b<0?'-':'+', abs(b), c<0?'-':'+', abs(c));
				type.str("");
				type.clear();
				type << a << "x^2" << (b<0?'-':'+') << abs(b) << "x" << (c<0?'-':'+') << abs(c) << "=0" << endl;
				cout << type.str();
			}

			Equation equation(a,b,c);	
			
			if(b==0&&c==0){
				equation.IncompleteBoth();
				//cout << "the roots are: " << equation.X1 << " and " << equation.X2 << endl;
				roots.str("");
				roots.clear();
				roots << "the roots are: " << equation.X1 << " and " << equation.X2 << endl <<  endl;
				cout << roots.str();
			}
			else if(b==0){
				if(-(c/a)>0){
					equation.IncompleteB();
					//cout << "the roots are: " << equation.X1 << " and " << equation.X2 << endl;
					roots.str("");
					roots.clear();
					roots << "the roots are: " << equation.X1 << " and " << equation.X2 << endl << endl;
					cout << roots.str();
				}
				else{
					//cout << "the equation has no roots.\n";
					roots.str("");
					roots.clear();
					roots << "the equation has no roots.\n\n";
					cout << roots.str();
				}
			}
			
			else if(c==0){
				equation.IncompleteC();
				//cout << "the roots are: " << equation.X1 << " and " << equation.X2 << endl;
				roots.str("");
				roots.clear();
				roots << "the roots are: " << equation.X1 << " and " << equation.X2 << endl << endl;
				cout << roots.str();
			}
			
			else{
				equation.CalculationDiscriminant();
				
				if(equation.Disc>0){
					equation.CalculationRoots();
					//cout << "the roots are: " << equation.X1 << " and " << equation.X2 << endl;
					disc.str("");
					disc.clear();
					disc << "discriminant is bigger than 0\n";
					roots.str("");
					roots.clear();
					roots << "the roots are: " << equation.X1 << " and " << equation.X2 << endl << endl;
					cout << roots.str();
					
				}
				else if(equation.Disc==0){
					equation.CalculationRoot();
					//cout << "root is: " << equation.X1 << endl;
					disc.str("");
					disc.clear();
					disc << "discriminant is equaled 0\n";
					roots.str("");
					roots.clear();
					roots << "root is: " << equation.X1 << endl << endl;
					cout << roots.str();
				}
				else if(equation.Disc<0){
					//cout << "equation has no roots.\n";
					disc.str("");
					disc.clear();
					disc << "discriminant is less than 0\n";
					roots.str("");
					roots.clear();
					roots << "equation has no roots.\n\n";
					cout << roots.str();
				}
				else{
					cout << "Something's wrong...\n";
				}
			}
			if(message=="1"){
				FFile.readingFile();
				a=FFile.buff[0];
				b=FFile.buff[1];
				c=FFile.buff[2];
			}
			if(message=="2"){
				calc=3;
			}
			FromFile f (type.str(), roots.str(), disc.str());
			if(b!=0&&c!=0){
				f.writeLog();
			}
			else{
				f.writeLogIncomplete();
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
