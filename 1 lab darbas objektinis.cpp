//Aurimas Liubauskas ISF-19/2 20195177	"projektai"



/*
Laboratorinis darbas NR.1
Bendri užduoties reikalavimai– pagal individualia užduoti parašyti programa, kuri turetu:
. Konstruktoriu be parametru ir konstruktoriu su parametrais (1 balas);
. Metodus objekto savybiu keitimui (set) ir nuskaitymui (get) (1 balas);
. Irašu papildyma ir šalinima duomenu faile. (1 balas);
. Duomenu nuskaityma iš failo i objektu masyva ir peržiura ekrane (1 balas);
. Suprogramuota paieškos funkciju perkrovima (1 balas);
. Išsamu dialoga su vartotoju (1 balas);
. Išsamius programos komentarus (1 balas);
Klasese duomenys turi buti inkapsuliuojami t.y. private arba protected, o funkcijos – public.
Likusia pažymio dali (3 balus) sudarys privalomas laboratorinio darbo gynimas.
******************************************************************************************
[14] Parašyti programa „projektai“. Kiekviena iraša sudaro laukai: projekto pavadinimas,
projekto vadovo pavarde, projekto komandos nariu skaicius, projekto biudžetas, trukme
(menesiais). Turi buti realizuota:
1. Projektu vidutines trukmes ir biudžetu vidurkio skaiciavimas;
2. Paieška nurodžius projekto pavadinima ir vadovo pavarde;
3. Paieška nurodžius projekto pavadinima, vadovo pavarde, komandos nariu skaiciu;
4. Rikiavimas pagal projekto komandos nariu skaiciu ir biudžeta ir trukme;
******************************************************************************************
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std; // standartine vardu sritis

class projektai{
	private: // kintamieji
		string ProjektoPavadinimas, VadovoPavarde;
		int nariai,nr;//nariu skaicius ir nario numeris
		double biudzetas,trukme;
		
	public:  // metodai
	projektai(int,string, string,int,double,double);//konstruktorius su reiksmem
	projektai();//konstruktorius be reiksmiu
	~projektai(){};
	
	int SetNr(int nr){this -> nr = nr;}
	int GetNr(){return nr;}
	void Setpav(string Projekto_Pavadinimas){this -> ProjektoPavadinimas=Projekto_Pavadinimas;};	//pavadinimo nustatymas
	string Getpav(){if (ProjektoPavadinimas.length()>0) return ProjektoPavadinimas;else return "be pavadinimo";};	//pavadinimo grazinimas	
	void Setvard(string Vadovo_Pavarde){this -> VadovoPavarde=Vadovo_Pavarde;};					//vardo nustatymas
	string Getvard(){if (VadovoPavarde.length()>0) return VadovoPavarde;else return "be vadovo";};		//vardo grazinimas
	double SetBiudzetas(double Biudzetas){this -> biudzetas=Biudzetas;}		//biudzeto nustatymas
	double GetBiudzetas(){return biudzetas;}		// biudzeto grazinimas
	int SetNarSk(double Nariu_skaicius){this -> nariai=Nariu_skaicius;}		//nariu skaiciaus nustatymas
	int GetNarSk(){return nariai;}		//nariu skaiciaus grazinimas
	double SetTrukme(double Trukme){this -> trukme=Trukme;}		//trukmes nustatymas
	double GetTrukme(){return trukme;}		//trukmes grazinimas
	bool SetProjektas(int,string,string,int,double,double);		//viso projekto reiksmiu nustatymas
	};
	
	//projekto reiksmiu priskyrimo/keitimo metodas
	bool projektai::SetProjektas(int nr,string Projekto_Pavadinimas, string Vadovo_Pavarde,int Nariu_skaicius,double biudzetas,double Trukme){
		if(Projekto_Pavadinimas.length() >0&&Vadovo_Pavarde.length()>0&&Nariu_skaicius>0&&biudzetas>0&&Trukme>0){
				ProjektoPavadinimas=Projekto_Pavadinimas; VadovoPavarde= Vadovo_Pavarde;
				this -> nariai=Nariu_skaicius;this-> biudzetas=biudzetas; this -> trukme=Trukme;
				this ->nr=nr;
		return true;
		}
		else {
			ProjektoPavadinimas="";	VadovoPavarde="";
			nariai=0; trukme=0,biudzetas=0;
		return false;
	}
	}
	
	//konstruktorius su reiksmemis
	projektai::projektai(int nr,string Projekto_Pavadinimas, string Vadovo_Pavarde,int Nariu_skaicius,double biudzetas,double Trukme){
		if(Projekto_Pavadinimas.length() >0&&Vadovo_Pavarde.length()>0&&Nariu_skaicius>0&&biudzetas>0&&Trukme>0){
				ProjektoPavadinimas=Projekto_Pavadinimas; VadovoPavarde= Vadovo_Pavarde;
				this->nariai=Nariu_skaicius; this->trukme=Trukme,this->biudzetas=biudzetas;
				this ->nr=nr;
		}
		else {
			ProjektoPavadinimas="";	VadovoPavarde="";
			nariai=0; trukme=0;biudzetas=0;
	}
	}
	//konstruktorius be reiksmiu
	projektai::projektai(){
		ProjektoPavadinimas="";	VadovoPavarde="";
		nariai=0;biudzetas=0; trukme=0;
	}
	
	//PROTOTIPAI
	void skaito(projektai P[],int &k);// k=projektu kiekis
	void spausdina (projektai P[],int k);// atspausdina visus prohektus
	void pasirinkimai(projektai P[],int &k);//vartotojo pasirinkimai
	void rikiuoja(projektai P[],int k);//rikiavimas ir isvedimas
	double GetAverageBiudzetas(projektai P[], int k);// vidutinis biudzetas
	double GetAverageLaikas(projektai P[], int k);//vidutinis laikas
	//
	
int main(){
	
	
	projektai P[15];  //klases masyvas
	int k=0;//projektu kiekis
	skaito (P,k); // nuskaito duomenis
	spausdina(P,k);// atspausdina nuskaitytus duomenis
	pasirinkimai(P,k);// kreipiasi i pasirinkimus
	

}


//nuskaitymas
	void skaito(projektai P[],int &k){

ifstream is ("projektai.txt");  // failo nuskaitymas

if(is.fail()){  // tikrinimas ar pavyko
	cout<<"failo nuskaityti nepavyko"<<endl;
	exit; // baigti programa
}
	//nuskaitomi dalykai
	string pavadinimas,pavarde;
	int nariu_Sk,nr=1;
	double biudzetas,trukme;
	
	
while (!is.eof()){ // iki failo galo
	is>>pavadinimas>>pavarde>>nariu_Sk>>biudzetas>>trukme; // nuskaitymas is failo
	P[k]=projektai(k+1,pavadinimas,pavarde,nariu_Sk,biudzetas,trukme);//k+1, kad numeris butu varotoju kalba , veliau ta numeri naudosiu rikiavimui
	k++;
}
is.close();
	}
	
	//
	
	
	//spausdinimas
void spausdina (projektai P[],int k){
	cout<<setw(65)<<right<<"Projektai:"<<endl; //isvedu ka nuskaiciau
cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
for (int j=0;j<k;j++){//isvedimo ciklas
	cout<<right<<setw(3)<<j+1<<"."<<left<<"projekto pavadinimas: "<<setw(10)<<P[j].Getpav()<<" vadovo pavarde: "<<setw(15)<<P[j].Getvard()<<" nariu sk: "<<setw(5)<<P[j].GetNarSk()
	<<" biudzetas: "<<setw(5)<<P[j].GetBiudzetas()<<" trukme: "<<setw(5)<<P[j].GetTrukme()<<endl;
}
//1. 
cout<<"\n\n"<<"Projektu vidutinis biudzetas: "<<GetAverageBiudzetas(P,k)<<endl; // biudzetu vidurkis
cout<<"Projektu vidutine trukme: "<<GetAverageLaikas(P,k)<<endl; // trukmes vidurkis
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	
}

//


//pasirinkimu funkcija
	void pasirinkimai(projektai P[],int &k){
		
		//vidiniai prototipai, kuriu reikia tik siai funkcijai
bool paieska(projektai P[], string Projekto_Pavadinimas,string Vadovo_Pavarde,int Nariu_skaicius,int k);// paieska pagal projekto pavadinima,vadovo pavarde ir nariu skaiciu
bool paieska(projektai P[], string Projekto_Pavadinimas,string Vadovo_Pavarde, int k);	// paieska pagal projekto pavadinima ir vadovo pavarde
void salina(projektai P[],int &k);//salinimo funkcija
void prideda(projektai P[],int &k);//projekto pridejimo funkcija
void iraso(projektai P[],int k);// irasimo i faila funkcija

char n;//veiksmas

while (true){ 	//prasys ivesti tol kol nebus ivestas 0
cout<<"Galimi veiksmai:\n1.Paieska nurodant Projekto pavadinima ir vadovo pavarde\n2.Paieska nurodant Projekto pavadinima, vadovo pavarde ir nariu skaiciu\n";
cout<<"3.Atspausdinti projektu sarasa\n4.atspausdinti projektu sarasa surikiuota pagal projekto komandos nariu skaiciu ir biudžeta ir trukme;\n";
cout<<"5.pasalinti projekta nurodant indeksa\n6.prideti projekta\n";
cout<<"0.baigti programa\n";	
cout<<"\n Pasirinkite veiksma\n";
cin>>n;//ivedu pasirinkima
if(n!='0'&&n!='1'&& n!='2'&&n!='3'&&n!='4'&&n!='5'&&n!='6')cout<<"veiksmas "<< n << " yra negalimas, pasirinkite is nurodytu veiksmu"<<endl;//jei neaprasytas veiksmas

//jei pasirinktas 1 variantas
if(n=='1'){
cout<<"Jus pasirinkote 1.Paieska nurodant Projekto pavadinima ir vadovo pavarde\n";
cout<<"Iveskite Projekto pavadinima: ";
string pavadinimas;cin>>pavadinimas;
cout<<"Iveskite projekto vadovo pavarde: ";
string pavarde; cin>>pavarde;
cout<<"\n "<<setw(70)<<right<<"paieskos rezultatai: "<<endl;
cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
if(paieska(P,pavadinimas,pavarde,k));//vykdoma paieskos funkcija
else cout<<"rezultatu nerasta\n";
cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
}
//

//jei pasirinktas 2 variantas
if(n=='2'){
cout<<"Jus pasirinkote 2.Paieska nurodant Projekto pavadinima, vadovo pavarde ir nariu skaiciu\n";
cout<<"Iveskite Projekto pavadinima: ";
string pavadinimas;cin>>pavadinimas;
cout<<"Iveskite projekto vadovo pavarde: ";
string pavarde;cin>>pavarde;
cout<<"Iveskite Nariu skaiciu: ";
int nariu_Sk;cin>>nariu_Sk;
cout<<"\n "<<setw(70)<<right<<"paieskos rezultatai: "<<endl;
cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
if(paieska(P,pavadinimas,pavarde,nariu_Sk,k));// vykdoma paieskos funkcija
else cout<<"rezultatu nerasta\n";
cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
}


if(n=='3')//atspausdinimas
spausdina(P,k);

if (n=='4')// rikiavimas ir atspausdinimas
rikiuoja(P,k);

if(n=='5')//eilutes salinimas
salina(P,k);

if (n=='6')//eilutes pridejimas
prideda(P,k);

if(n=='0'){// programos baigimas ir rezultatu irasymas
iraso(P,k);
break;}
}


	}


	//2 pavadinimas ir pavarde
		bool paieska(projektai P[], string Projekto_Pavadinimas,string Vadovo_Pavarde,int k){
		bool yra=0;//naudoju tam kad veliau galeciau patikrinti ar yra
		int nr=1;// rastos eilutes numeris
		for (int i=0;i<k;i++){//ciklas per visasd reiksmes
			if(P[i].Getpav()==Projekto_Pavadinimas&&P[i].Getvard()==Vadovo_Pavarde){
			cout<<setw(3)<<right<<nr<<"."<<"projekto pavadinimas: "<<left<<setw(10)<<P[i].Getpav()<<" vadovo pavarde: "<<setw(15)<<P[i].Getvard()<<" nariu sk: "
			<<setw(5)<<P[i].GetNarSk()<<" biudzetas: "<<setw(5)<<P[i].GetBiudzetas()<<" trukme: "<<setw(5)<<P[i].GetTrukme()<<endl;
			yra=1;// rasta rezultatu
			nr++;// numeris padidinamas
			}
		}
		return yra;
	}
//3 pavadinimas pavarde ir nariu skaicius
	bool paieska(projektai P[], string Projekto_Pavadinimas,string Vadovo_Pavarde,int Nariu_skaicius,int k){
		bool yra=0;// ar yra rezultatu
		int nr=1; // rastos eilutes numeris
		for (int i=0;i<k;i++){
			if(P[i].Getpav()==Projekto_Pavadinimas&&P[i].Getvard()==Vadovo_Pavarde&&P[i].GetNarSk()==Nariu_skaicius){
			cout<<setw(3)<<right<<nr<<"."<<"projekto pavadinimas: "<<left<<setw(10)<<P[i].Getpav()<<" vadovo pavarde: "<<setw(15)<<P[i].Getvard()<<" nariu sk: "
			<<setw(5)<<P[i].GetNarSk()<<" biudzetas: "<<setw(5)<<P[i].GetBiudzetas()<<" trukme: "<<setw(5)<<P[i].GetTrukme()<<endl;
			yra=1;//yra rezultatu
			nr++;// numeris padiidinamas
			}
		}
		return yra;// grazinama ar yra rezultatu
	}
	
//4. Rikiavimas pagal projekto komandos nariu skaiciu ir biudžeta ir trukme;
void rikiuoja(projektai P[],int k){
	int pnr;//pagalbinis numeris
	
	//rikiavimo logika
for(int i=0;i<k-1;i++) //vienas ciklas sukasi iki viso projektu kiekio -1, nes nera prasmes tikrint paskutinio su paskutiniu
for (int j=i+1;j<k;j++){//tikrinu sekanti skaiciu iki paskutinio
	if(P[P[i].GetNr()-1].GetNarSk()<P[P[j].GetNr()-1].GetNarSk())
//naudodamasis nariu numeriais tikrinu nariu skaicius ir keiciu tik numerius, nes pagal juos viska ir isvesiu, kad nereiktu keisti visu 5 duomenu
//visada sukasi ciklo skaiciai i ir j ir pagal juos nustatau nario numerio skaiciu ir taip kreipiuosi i teisinga klase 					
	{
		pnr=P[i].GetNr();
		P[i].SetNr(P[j].GetNr());
		P[j].SetNr(pnr);
	}
	//2 lygis pagal biudzeta
	if(P[P[i].GetNr()-1].GetNarSk()==P[P[j].GetNr()-1].GetNarSk()&&P[P[i].GetNr()-1].GetBiudzetas()<P[P[j].GetNr()-1].GetBiudzetas())
		{
		pnr=P[i].GetNr();
		P[i].SetNr(P[j].GetNr());
		P[j].SetNr(pnr);
	}
	//3 lygis pagal trukme
		if(P[P[i].GetNr()-1].GetNarSk()==P[P[j].GetNr()-1].GetNarSk()&&P[P[i].GetNr()-1].GetBiudzetas()==P[P[j].GetNr()-1].GetBiudzetas()&&P[P[i].GetNr()-1].GetTrukme()<P[P[j].GetNr()-1].GetTrukme())
		{
		pnr=P[i].GetNr();
		P[i].SetNr(P[j].GetNr());
		P[j].SetNr(pnr);
	}
}

// surikiuoto atspausdinimas
	cout<<setw(75)<<right<<"Surikiuoti pagal nariu skaiciu, biudzeta ir trukme projektai:"<<endl;
cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
for (int j=0;j<k;j++){
	cout<<right<<setw(3)<<j+1<<"."<<left<<"projekto pavadinimas: "<<setw(10)<<P[P[j].GetNr()-1].Getpav()<<" vadovo pavarde: "<<setw(15)<<P[P[j].GetNr()-1].Getvard()<<" nariu sk: "<<setw(5)<<P[P[j].GetNr()-1].GetNarSk()
	<<" biudzetas: "<<setw(5)<<P[P[j].GetNr()-1].GetBiudzetas()<<" trukme: "<<setw(5)<<P[P[j].GetNr()-1].GetTrukme()<<endl;
}
cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	
}

salina(projektai P[], int &k){
	int x ;// salinamasis skaicius
	cout<<"iveskite indeksa projekto kuri norite pasalinti\n";cin>>x;// ivedama ka pasalinti
	k--; // kiekis pamazinamas
P[x-1].SetProjektas(P[k].GetNr(),P[k].Getpav(),P[k].Getvard(),P[k].GetNarSk(),P[k].GetBiudzetas(),P[k].GetTrukme());
	spausdina(P,k);// priskiriamas paskutinis projektas i ivesta (x) vieta
}

void prideda(projektai P[],int &k){ //pridedama projektu eilute
	string pavadinimas, pavarde;
	int nariai;
	double biudzetas, trukme;
	cout<<"iveskite projekto duomenis\n";
	cout<<"pavadinimas: ";cin>>pavadinimas;//ivedami visi duomenys
	cout<<"vadovo pavarde: ";cin>>pavarde;
	cout<<"nariu skaicius: ";cin>>nariai;
	cout<<"biudzetas: "; cin>>biudzetas;
	cout<<"trukme: ";cin>>trukme;
	P[k]=projektai(k+1,pavadinimas,pavarde,nariai,biudzetas,trukme);// visi duomenys priskiriami ir pridedami i projektu saraso gala
	k++; 
	spausdina(P,k);
}

void iraso(projektai P[],int k){// irasimas i faila
	ofstream rf("projektai.txt");
	
	for (int j=0;j<k;j++){// ciklas per visus projektus
	rf<<" "<<P[j].Getpav()<<" "<<P[j].Getvard()<<" "<<P[j].GetNarSk()<<" "<<P[j].GetBiudzetas()<<" "<<P[j].GetTrukme()<<endl;//irasymas
}
	
	rf.close();
}


	double GetAverageBiudzetas(projektai P[], int k)// vidutinis biudzetas
{
	double biudzetas =0;
	for (int i=0;i<k;i++){
		biudzetas+=P[i].GetBiudzetas();// suskaiciuoju visa biudzeta
	}
	double average=0;
	average=biudzetas/double(k);// apskaiciuoju vidutini biudzeta
	return average;
	}
	
	
		double GetAverageLaikas(projektai P[], int k)//vidutinis laikas
{
	double laikas =0;
	for (int i=0;i<k;i++){
		laikas+=P[i].GetTrukme();// suskaiciuoju visa laika
	}
	double average=0;
	average=laikas/double(k);// apskaiciuoju vidutini laika
	return average;
	}


