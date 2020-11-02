#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <sstream>
#include "bst.h"

using namespace std;

const int MAX=50; //definition of maximum

//Definir la estructura del objeto principal
struct Book{
	string Tittle;
	string Author;
	float Rating;
	int o;
};

//Metodo Swap para las funciones Sort
void swap(Book* *a, Book* *b){
	Book* temp= *a;
	*a=*b;
	*b=temp;
}

//Metodo Selection Sort en base al título
void tittleSort(Book* b[], int n){
	int index;
	string small;
	
	for(int i=0; i<n-1; i++){
		index=i;
		small=b[index]->Tittle;
		
		for(int j=i+1; j<n; j++){
			if(b[j]->Tittle.compare(small)<0){
				index=j;
				small=b[index]->Tittle;
			}
		}
		if (index != i){
			swap(&b[index], &b[i]);;
		}
	}
}

//Metodo selection sort por Autor
void authorSort(Book* b[], int n){
	int index;
	string small;
	
	for(int i=0; i<n-1; i++){
		index=i;
		small=b[index]->Author;
		
		for(int j=i+1; j<n; j++){
			if(b[j]->Author.compare(small)<0){
				index=j;
				small=b[index]->Author;
			}
		}
		if (index != i){
			swap(&b[index], &b[i]);;
		}
	}
}

//Metodo de busqueda simple por autor
void searchA(){
	string search;
	cout<<"If the program does not show a result"<<endl;
	cout<<"means there was no Author Found"<<endl;
	cout<<"Be careful to use Initial Capitals"<<endl;
	cout<<"Like - 'Rowling'"<<endl;
	cout<<"Enter First or Last mame of Author to find: "<<endl;
	cin>>search;
	ifstream s("books.txt");
	if(!s.is_open())
		cout<<"Not possible to open file"<<endl;
	
	string word;
	while(getline(s,word)){
		if(word.find(search) != string::npos){
			cout<<word<<endl;
		}
	}
}

//Metodo de busqueda simple por Titulo
void searchName(){
	string search;
	cout<<"If the program does not show a result"<<endl;
	cout<<"means there was no Book Found"<<endl;
	cout<<"Write with initial capital"<<endl;
	cout<<"Like 'Wonder'"<<endl;
	cout<<"Name of book to find or Key Word: "<<endl;
	
	cin>>search;
	ifstream s("books.txt");
	if(!s.is_open())
		cout<<"Not possible to open file"<<endl;
	
	string word;
	while(getline(s,word)){
		if(word.find(search) != string::npos){
			cout<<word<<endl;
		}
	}
}

//Metodo para leer el archivo
void readF(){
	ifstream file("books.txt");
	string Tittle;
	string Author;
	float Rating;
			
	if(file.is_open()){
		cout<<"Tittle"<<"      "<<"Author"<<"   "<<"Rating"<<endl;
		while(file >> Tittle >> Author >> Rating){
		cout<<Tittle<<"   "<<Author<< "  " << Rating <<"  "<<endl;
		}
		file.close();
	}
}

//Definir main
int main(int argc, char* argv[]){
	int option;
	Book b1;
	Book bo[17];
	//Definir menu
	cout<<"----- MENU ------"<<endl;
	cout<<"1. Print File"<<endl;
	cout<<"2. Sort by Tittle"<<endl;
	cout<<"3. Sort by Author"<<endl;
	cout<<"4. Search by Author"<<endl;
	cout<<"5. Search by Book Tittle"<<endl;
	cout<<"6. Find repited characters"<<endl;
	cout<< "Enter option: "<<endl;; 
	cin >> option;
	switch(option){
		case 1:{
		// MAndar a llamar la función de lectura
		readF();		
					
		}
		
		break;
		
		case 2:{
		//Abrir el archivo y usar apuntadores para crear una nueva
		//estructura y logragr una escritura correcta
		ifstream File;
		File.open("Books.txt");
		
		if(File){
			Book* Pointer[MAX];
			string T,A;
			float R;
			int o=0;
			
			while(!File.eof()){
				File>>T>>A>>R;
				
				Pointer[o]=new Book;
				
				Pointer[o]->Tittle=T;
				
				(*Pointer[o]).Author=A;
				
				Pointer[o]->Rating=R;
				
				Pointer[o]->o=o+1;
				
				o++;
			}
		
		--o;
		
		//Menu para imprimir o crear un nuevo archivo
		cout<<"Select an option: "<<endl;
		cout<<"Print Result - P"<<endl;
		cout<<"Save to File - S"<<endl;
		char choice;
		cin>>choice;
		
		if(choice=='P'){
				
			tittleSort(Pointer, o);
			cout<<"BN:"<< " "<<"Tittle A-Z"<<"  	"<<"Author"<<" 	 "<<"Rating "<< "  "<<endl;
				for(int i=0; i<o; i++)
					//Metodo de escritura por apuntadores
					cout<<Pointer[i]->o<<" "<<Pointer[i]->Tittle<<"		"<<Pointer[i]->Author<<"   "<<Pointer[i]->Rating<<"   "<<endl;
		}
		else if (choice=='S'){		
			//Crear nuevo archivo y definir la estructura de lectura
			ofstream ts("SortedT.txt");
			cout<<"Sorted data in file SortedT.txt"<<endl;
				
			tittleSort(Pointer, o);
			ts<<"BN:"<< "  "<<"Tittle A-Z"<<"  "<<"Author "<<" 	 "<<"Rating "<< "  "<<endl;
				for(int i=0; i<o; i++)
					ts<<Pointer[i]->o<<" "<<Pointer[i]->Tittle<<"		"<<Pointer[i]->Author<<"   "<<Pointer[i]->Rating<<"   "<<endl;
			
		}
		else{
			cout<<"Exit Invalid Option"<<endl;
		}
		}
		}
		
		break;
		
		case 3:{
		//Caso similar al anterior
		//Abrir el archivo y leerlo por medio de pointers
		ifstream File;
		File.open("Books.txt");
		
		if(File){
			Book* Pointer[MAX];
			string T,A;
			float R;
			int o=0;
			
			while(!File.eof()){
				File>>T>>A>>R;
				
				Pointer[o]=new Book;
				
				Pointer[o]->Tittle=T;
				
				(*Pointer[o]).Author=A;
				
				Pointer[o]->Rating=R;
				
				Pointer[o]->o=o+1;
				
				o++;
			}
			
		--o;
		
		//Menu para imprimir o guardar en archivo
		cout<<"Select an option: "<<endl;
		cout<<"Print Result - 1"<<endl;
		cout<<"Save to File - 2"<<endl;
		int choice;
		cin>>choice;
		
		if(choice==1){
				
			authorSort(Pointer, o);
			cout<<"BN:"<< " "<<"Tittle"<<"  "<<"Author A-Z "<<" 	 "<<"Rating "<< "  "<<endl;
				for(int i=0; i<o; i++)
					cout<<Pointer[i]->o<<"	 "<<Pointer[i]->Tittle<<"		"<<Pointer[i]->Author<<"   "<<Pointer[i]->Rating<<"   "<<endl;
		}
		else if(choice==2){		
		
			ofstream file("SortedA.txt");
			cout<<"Sorted data in file SortedA.txt"<<endl;
				
			authorSort(Pointer, o);
			file<<"BN:"<< "  "<<"Tittle"<<"  "<<"Author A-Z "<<" 	 "<<"Rating "<< "  "<<endl;
				for(int i=0; i<o; i++)
					file<<Pointer[i]->o<<" "<<Pointer[i]->Tittle<<"		"<<Pointer[i]->Author<<"   "<<Pointer[i]->Rating<<"   "<<endl;
			
		}
		
		else{
			cout<<"Exit, Inavlid Option"<<endl;
		}
		
		}
		}
		
		break;	
		case 4:{
		//Mandar a llamar la función
		searchA();	
		
		}
		
		break;
		
		case 5:{
		//Mandar a llamar la función
		searchName();
		
		}
		
		break;
		
		case 6:{
			//Definir varibles necesairas y abrir el nuevo sorteado
			string data;
			string a,b;
			int num;
			BST bst;
			fstream sb;
			sb.open("SortedA.txt", ios::in);

			if (!sb){
				
				cout << "Not possible to open file";
			}

			else{
				
				num=1;
				
			}

			while (getline(sb, a)) {
				
				data += a;
				
			}
			
			//Eliminar datos del archivo para evitar sobreescritura
			data.erase(remove(data.begin(),data.end(),' '),data.end());
			
			//Metodo para agregar cada registro al bst
			for (unsigned int i = 0; i < data.size(); i++) {
				
				if (data[i] != ' '){
					string a(1, data[i]);
					bst.insertN(a);
				}
			}

		
			sb.close();
			cout<<"Repetition of characters"<<endl;
			//Metodo de impresion del BST
			bst.inorder();

			return 0;
			}
		}
}
		
	


