#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class file{

public:
	ifstream fileIn;
	ofstream fileOut;

	file();
	~file();
};

file::file(){
	fIn.open("C:\\zle.txt");
	fOut.open("C:\\wynik.txt");
}

file::~file(){
	fileIn.close();
	fileOut.close();
}

class ciagi{
	
private:
	file f;
	vector <int> ciag;
	vector <int> r;
	vector <int> zle;
		
public:
	void zaladuj();
	void wypisz();
};

void ciagi::zaladuj(){
	int dlugosc;
	int liczba;
	int dobreR;
	
while(!f.fileIn.eof()){
	f.fileIn>>dlugosc;
	for(int i=0;i<dlugosc;i++){
	f.fileIn>>liczba;
	ciag.push_back(liczba);
	}
	for(int i=0;i<4;i++){
		r.push_back(ciag[i+1]-ciag[i]);
	}
	if(r[0]==r[1]){
		dobreR=r[0];
	} 
	else if(r[1]==r[2]){
		dobreR=r[1];
	} 
	else if(r[2]==r[3]){
		dobreR=r[2];
	}
	else if(r[3]==r[0]){
		dobreR=r[3];
	}
	for(int i = 0;i<dlugosc;i++){
		if(ciag[i]+dobreR!=ciag[i+1]){
			zle.push_back(ciag[i+1]);
			break;
		}
	}
ciag.clear();
r.clear();
	}

	
}

void ciagi::wypisz(){
	for(int i=0;izle.size()-1;i++){
		f.fOut<<i+1<<":"<<zle[i]<<endl;
	}
}

int main(int argc, char** argv) {
	ciagi a;
	a.zaladuj();
	a.wypisz();
	
	return 0;
}
