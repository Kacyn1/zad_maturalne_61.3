#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class ciagi {
public:	
ifstream filein;
ofstream fileout;

	vector<int> liczby;

	int ilosc_c, max_r, roznica, liczba, dl_ciagu;

	bool js_arytmetyczny;

	ciagi(){
		filein.open("ciagi.txt");
		fileout.open("wynik1.txt");
	}
	
	~ciagi(){
		filein.close();
		fileout.close();
	}

	void dow(){
	
	while(!filein.eof()){
		
		filein>>dl_ciagu;
			
			for(int i=0; i<dl_ciagu; i++){
				filein>>liczba;
				liczby.push_back(liczba);
			}
			
		roznica=liczby[1]-liczby[0];
		
		js_arytmetyczny=true;
		
			for(int i=0; i+1<dl_ciagu; i++){
				if(roznica!= liczby[i+1]-liczby[i]){
					js_arytmetyczny=false;
				}
				
			}
		if(js_arytmetyczny){
			ilosc_c++;
				if(max_r<roznica){
					max_r=roznica;
			}
	
		}
		
		liczby.clear();
		
		
	}
	
	cout<<ilosc_c<<endl;
	cout<<max_r;
	
		
	}
	
};

int main(int argc, char** argv) {
	
ciagi c1;
c1.dow();	
	
	return 0;
}
