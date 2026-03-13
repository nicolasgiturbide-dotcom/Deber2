#include <iostream>
#include <ctime>
#include <locale>
#include <memory>
#include <iomanip>
using namespace std;
struct separate_thousands : std::numpunct<char> {
    char_type do_thousands_sep() const override { return ','; }
    string_type do_grouping() const override { return "\3"; }
};
void USD_EUR(double base, long double cambio){
	time_t timestamp;
	time(&timestamp);
		double USD_EUR=base*cambio;
		//[AI-Start]
		cout << fixed << setprecision(2);
		//[AI-End]
		cout<<"==Market Snapshot=="<<endl;
		cout<<"Par: USD convertido a EUR"<<endl;
		cout<<"Monto base: "<<base<<" USD"<<endl;
		auto thousands = std::make_unique<separate_thousands>();
    	std::cout.imbue(std::locale(std::cout.getloc(), thousands.release()));
		std::cout <<"Monto convertido: "<<USD_EUR<< "EUR"<<endl;
		cout<<"Tasa de cambio: "<<cambio<<endl;
		cout <<"Timestamp: "<<ctime(&timestamp);
		cout<<"=================="<<endl;
		}
void EUR_USD(double base, long double cambio){
	time_t timestamp; 
	time(&timestamp);
		double EUR_USD=base*cambio;
		//[AI-Start]
		cout << fixed << setprecision(2);
		//[AI-End]
		cout<<"==Market Snapshot=="<<endl;
		cout<<"Par: EUR convertido a USD"<<endl;
		cout<<"Monto base: "<<base<<" EUR"<<endl;
		auto thousands = std::make_unique<separate_thousands>();
    	std::cout.imbue(std::locale(std::cout.getloc(), thousands.release()));
		std::cout <<"Monto convertido: "<<EUR_USD<< "USD"<<endl;
		cout<<"Tasa de cambio: "<<cambio<<endl;
		cout <<"Timestamp: "<<ctime(&timestamp);
		cout<<"=================="<<endl;
		}
int main(){
	string resp;
	cout<<"==============================================================================="<<endl;
	cout<<"Bienvenido al programa IndCind"<<endl<< "Aqui te ayudaremos a realizar tus conversiones a otro tipos de monedas que requieras"<<endl;
	cout<<"En este programa la coma (,) se usa para indicar numeros de base grande."<<endl<< "Mientras que el punto (.) se usa para indicar decimales."<<endl;
	cout<<"==============================================================================="<<endl;
	
	while(true){
	cout<<"Escribe las tres primeras letra de la moneda que quisieras convertir (USD/EUR):"<<endl;
	cin>>resp;
	while (resp!="USD" && resp!="usd" && resp!="Usd" && resp!="USd" && resp!="uSd" && resp!="UsD" && resp!="usD" && resp!="uSD" && resp!="EUR" && resp!="eur" && resp!="Eur" && resp!="EUr" && resp!="eUr" && resp!="EuR" && resp!="eUR" && resp!="euR") {
    cout << "Solo puedes ingresar USD o EUR"<<endl;
    cin >> resp;
}
	double base;
	cout<<"Escribe la base: ";
	while(!(cin>>base)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout<<"Debes ingresar un numero aqui:"<<endl;
		cin>>base;
	}
	while(base<=0){
		cout<<"Ingresa un numero mayor que 0"<<endl;
		cin>>base;
	}
	long double cambio;
	cout<<"Escribe la tasa de cambio: ";
	while(!(cin>>cambio)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout<<"Debes ingresar un numero aqui:"<<endl;
		cin>>cambio;
	}
	while(cambio<=0){
		cout<<"Ingresa un numero mayor que 0"<<endl;
		cin>>cambio;
	}
	if(resp=="USD" or resp=="usd" or resp=="Usd" or resp=="USd" or resp=="uSd" or resp=="UsD" or resp=="usD" or resp=="uSD" ){
		USD_EUR(base, cambio);
		cout<<"Quisieras volver a hacer el proceso?"<<endl<<"Escribe 'Si' en caso de que gustes continuar"<<endl<<"Escribe 'No' para salir del programa"<<endl;
		cin>>resp;
	}
	else{
	if(resp=="EUR" or resp=="eur" or resp=="Eur" or resp=="EUr" or resp=="eUr" or resp=="EuR" or resp=="eUR" or resp=="euR"){
		EUR_USD(base, cambio);
		cout<<"Quisieras volver a hacer el proceso?"<<endl<<"Escribe 'Si' en caso de que gustes continuar"<<endl<<"Escribe 'No' para salir del programa"<<endl;
		cin>>resp;
	}
}
	if(resp=="Si" or resp=="si" or resp=="sI" or resp=="SI"){
		true;
	}
	else{
		if(resp=="No" or resp=="no" or resp=="NO" or resp=="nO"){
			cout<<"Ok! Gracias por usar el programa!";
			break;
		}
	}
	while(resp!="Si" && resp!="si" && resp!="sI" && resp!="SI" && resp!="No" && resp!="no" && resp!="NO" && resp!="nO"){
	cout<<"No entendi tu respuesta, vuelve a ingresarla"<<endl;
	cin>>resp;
	}
}
}

