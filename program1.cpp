#include <iostream> 
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

const int N = 14;// broi na elementite namasiva

enum occupation {ARTIST=1, PHARMACIST, TEACHER, CHEMIST, LAWYER,TECHNICIAN,PHOTOGRAPHER,SELLER,ASTRONAUT,TRANSLATOR};
enum education{ primary=1,secondary,college,bachelor,master};


struct  citizents {
	char names  [50];
	int ages;
	double income ;
	education edu;
	occupation  job;

};

void printOneCitizen (citizents* ps);
char printMenu();
void printAllCitizens (citizents *p);
void computeBestJob (citizents *p);
void FindTheOldestPerson (citizents *p);

char printMenu(){
	 char c;
	 do {
		system("cls");
		cout <<"1. Print all citizents\n";
		cout <<"2. The oldest person\n";
		cout <<"3. Show all ages\n";
		cout <<"4. Find the best job\n";
		cout <<"5. Choose education\n";
		cout <<"0. End of the program\n\n";
		cout <<"Your choice: ";
		cin >> c;
	 }while (c<'0' || c > '5');
	 cout << endl;
	 return c;
 } // printMenu
 
static int comp1(const void *pArg1, const void *pArg2) {

  if (((citizents*)pArg1)->ages < ((citizents*)pArg2)->ages){
	return -1;
  }
  else{
	 if (((citizents*)pArg1)->ages > ((citizents*)pArg2)->ages){
		return 1;
	 }
	 else{
		return 0;
	 }
  }

} 
int main (){
 	char ch;
	citizents *p2;
	citizents cittadini[N] = {
	                      {"Spas Spasov",18,500,primary,TECHNICIAN},
						  {"Hristo Dakashev",24,3000,master,TRANSLATOR},
						  {"Simeon Parashkevov",23,2300,bachelor,PHOTOGRAPHER},
						  {"Chavdar Vetov",45,2189,bachelor,TEACHER},
						  {"Georgi Ivanov",56,1800,master,ASTRONAUT},
						  {"Nadia Georgieva",134,1000,college,SELLER},
						  {"Elena Petrova",30,1500,bachelor,ARTIST},
						  {"Ivana Georgieva",27,4500,master,PHARMACIST},
						  {"Kalina Georgakieva",43,560,primary,SELLER},
						  {"Veronika Borisova",50,400,college,ARTIST},
						  {"Ivanka Lazarova",54,2340,college,TEACHER},
						  {"Julia Mitova",32,3000,collegeADVOKAT},
						  {"Aleksandur Stefanov",39,4567,college,CHEMIST},
						  {"Konstantin Hristov",67,1234,college,TRANSLATOR}
						  };
						  
						  
						

 
 	do {
		p2 = cittadini;
		ch = printMenu();
		switch (ch) {
		case '1': printAllCitizens (cittadini) ;
				  break;//pokazva
		case '2': FindTheOldestPerson (p2) ;
				  break;
		case '3': //qsort(p2,N, sizeof(citizents), comp1);
				  break;// podrejda po  vuzrast
		case '4':// computeBestJob (p2, N) ;
				  //qsort(p2, N, sizeof(citizents), comp2);
				  break;
		case '5': //chooseEducation(p2, N);
				  break;
		
		}  // end switch
	} while (ch !='0');
	return 0;
}

void printAllCitizens (citizents *p) {
	cout << flush;
	for (int i=0;i<N;++i){
//		if ((p+i)->ime[0]){
			printOneCitizen (p+i);
		 	cin.sync();
			getchar();
//			system("Pause");
//		}
	}
}

void FindTheOldestPerson (citizents *p) {
	cout << flush;
	int i, maxInd = 0;
	for (int i=1;i<N;++i){
		if ((p+i)->ages > (p+maxInd)->ages){
			maxInd = i;
		}
	}
	cout << "Nai-dyrtia e:\n";
			printOneCitizen (p+maxInd);
		 	cin.sync();
			getchar();	
}


void printOneCitizen (citizents* ps){
	cout << "Citizen: " <<ps->names<<"\tAge: "<<ps->ages<<"\nIncome: "<< ps->income ;
	cout << "Education: " ;
	switch (ps->edu) {
		case primary: cout << "primary\t  ";
		  break;
		case secondary : cout << "secondary\t  ";
		  break;
		case college:  cout << "college\t  ";
  		  break;
		case bachelor: cout << "bachelor\t  ";
 		  break;
		case master: cout << "master\t";break;
 		default:    cout << "Unknown";
		  break;
	}
	cout << endl;
	cout << "Education: " ;
	switch (ps->edu) {
		case ARTIST: cout << "ARTIST\t  ";
		  break;
		case PHARMACIST : cout << "PHARMACIST\t  ";
		  break;
		case TEACHER:  cout << "TEACHER\t  ";
  		  break;
		case TRANSLATOR: cout << "TRANSLATOR\t  ";
 		  break;
		case CHEMIST: cout << "CHEMIST\t";break;
 		default:    cout << "Unknown";
		  break;
	}
	cout << endl;
	return;
} // printOneStudent
/*
void TheOldestPerson (citizents *p);
			if ((p+i)->ages(p=max)->age{
			printOldestPerson (p+max);
		 	cin.sync();
			getchar();
*/	



			


