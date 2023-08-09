//Aleksandar Karapanchevski INKI708
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
//definiranje na struktura
struct CovidMK{
	string grad;
	int novi;
	int ozdraveni;
};
//metoda za pecatenje na pdoatocite
void pecatiCovidMK(struct CovidMK covid[],int n){
	for(int i=0;i<n;i++)
	{
		cout<<"\n "<<covid[i].grad<<"  "<<covid[i].novi<<"  "<<covid[i].ozdraveni;
	}
}
//funkcija za sortiranje napdoatocite
void sortirajOpacka(struct CovidMK covid[],int n){
	struct CovidMK pom;
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1;j++)
			if(covid[j].novi<covid[j+1].novi)
			{
				pom=covid[j];
				covid[j]=covid[j+1];
				covid[j+1]=pom;
			}	
}
//funkicja za vnesuvanje na podatocite
void vnesiCovidMK(struct CovidMK covid[],int n){
	for(int i=0;i<n;i++)
	{
		cout<<"\n Vnesete grad : ";
		cin>>covid[i].grad;
		cout<<"\n Vnesete novo zaboleni pacienti : ";
		cin>>covid[i].novi;
		cout<<"\n Vnesete ozdraveni pacienti : ";
		cin>>covid[i].ozdraveni;
	}
	sortirajOpacka(covid,n);
}
int main(){
	struct CovidMK covid[100];
	vector<CovidMK> vekCovid(100);
	vector<CovidMK>::iterator itrCovid;
	int n;
	cout<<"\n Vnesete broj na gradovi koi imaat zaboleni za 10 Juni : ";
	cin>>n;
	//povik na funkcijata za vneusvanje napodatoci
	vnesiCovidMK(covid,n);
	//pecatenje n apodatocite
	cout<<"\n Pecatenje na podatocite od struktura : "<<endl;
	pecatiCovidMK(covid,n);
	//dobivanje na vektor 
	for(int i=0;i<n;i++)
		vekCovid.push_back(covid[i]);
		//pecatenje na podatocite spored iterator
	cout<<"\n Pecatenje na podtaocite preku iterator : "<<endl;
	cout<<endl;
	cout<<"\n  GRAD \t\t NOVI \t ODRAVENI ";
	for(itrCovid=vekCovid.begin();itrCovid<vekCovid.end();itrCovid++)
	{
		if(itrCovid->novi!=0)
	cout<<"\n "<<itrCovid->grad<<"\t\t"<<itrCovid->novi<<"\t"<<itrCovid->ozdraveni;
	}
	//upis na podatocite vo datoteka
	ofstream Alex("708.Covid1006.txt");
	Alex<<"\n  GRAD \t\t NOVI \t ODRAVENI ";
	for(itrCovid=vekCovid.begin();itrCovid<vekCovid.end();itrCovid++)
	{
		if(itrCovid->novi!=0)
	Alex<<"\n "<<itrCovid->grad<<"\t\t"<<itrCovid->novi<<"\t"<<itrCovid->ozdraveni;
	}
}

