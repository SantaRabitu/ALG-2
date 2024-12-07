#include"FileTools.h"
#include"iostream"

queue<string>vysledna_fronta;

/**
*@brief Hlavná funkcia main kde sa vykonávajú všetky operácie potrebné k výpočtu minimalneho počtu násobenia reťazca rozmerov matic, optimalne uzátvorkovanie na násobenie a samozrejme,
* aj výpis priamo na štandardný výstup. vytvára sa tu aj objekt z triedy FileHandler zo súboru FileTools, ktorý aj po použití zaniká.
* @return Funkcia main() vracia po úspešnom skončení 0
*/

int main() {

	FileHandler* fh = new FileHandler;
	//const string meno_suboru_txt;
	const string meno_suboru_txt = "Matrices.txt";



	if (!fh->nacitaj_subor(meno_suboru_txt, vysledna_fronta)) {

		std::cerr << "Nenacitalo sa" << endl;
		exit(-1);
		
	}
	vypis_frontu_stdout(vysledna_fronta);
//	fh->zapis_do_suboru("Porovnanie.txt", vysledna_fronta);
	delete(fh);

	return 0;


	
}
