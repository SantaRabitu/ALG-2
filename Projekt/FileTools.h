#include <vector>
#include <string>
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<queue>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::string;
using std::fstream;
using std::ios;
using std::get;
using std::istringstream;
using std::stringstream;
using std::ifstream;
using std::queue;
using std::ostringstream;


/**
* @brief Táto trieda má na starosť prácu so súbormi
* Obsiahnuté funkcie pekne načítajú súbor, spracujú súbor, vypíšu obsah zo súboru, či dokonca vytvoria súbor s obsiahnutou problematikou ktorej som sa venoval
* Reprezentaciu triedy som si vybral aj preto, že je vyžadované v projekte využivať vyššie štruktúry :D ale zároveň aj dovolené. Tak prečo nevyužiť možnosť jednoduchej manipulácii.
*Ďalej fajn výhoda je dynamické vytváranie objektov v triede, ktoré sa následne po použití mažú prostredníctvom delete príkazu. Dokonca je fajn tvorba inštancie objektov inej triedy v tejto.
*/

class FileHandler {


private:	

	static vector<int> string_to_vector(const string& riadok);


	
	static string vysledok(const vector<int> &retazec);

	


	static void daj_do_fronty(queue<string>& vysledna_fronta,string&hotovy_riadok);

	


	static bool spracuj_riadok(const string& riadok, queue<string>& vysledna_fronta);

	

	static void spracuj_subor(fstream&subor,queue<string>&fronta);



public:

	/**
	* @brief Načíta údaje zo súboru a spracuje ich.
	*
	* Táto funkcia otvorí súbor, načíta jeho obsah riadok po riadku, a pre každý riadok volá spracovateľské funkcie.
	*
	* @param filename Názov vstupného súboru.
	* @param fronta Fronta, do ktorej sa pridajú spracované výsledky. Berie referenciu na frontu.
	* @return True, ak sa podarilo načítať a spracovať súbor, inak False.
	*/


	static bool nacitaj_subor(const string& filename, queue<string>& fronta);

	/**
		*@brief Funkcie vytvára súbor a zapisuje údaje do súboru.
		*
		* Táto funkcia pekne zapíše obsah fronty do súboru.
		*
		* @param filename Názov výstupného súboru.
		* @param fronta Fronta, ktorá obsahuje spracované výsledky na zápis.
		* @return True, ak bol zápis úspešný, inak False, ak nie.
		*/

	static bool vytvor_subor (const string& filename, queue<string>& fronta);



	/**
	*@brief Funkcia má za úlohu frontu výsledných operácií zapísať do nami zvoleného súboru.
	* @param filename Prvý parameter funkcie odkazuje na konštantný názov súboru .txt,kte ma byť fronta vložená.
	*@param fronta Parameter je referenciou na frontu, ktorá má byť zapísaná.
	*/
	static void zapis_do_suboru(const string& filename, queue<string>& fronta);



};

/**
* @brief Táto funkcia má na starosti vypísať obsah fronty uložených riadkov na štandardný výstup. Hlavne pre overenie, a preto aby sme nemuseli stále otvárať ďalšie súbory.
*@param fronta Funkcia má parameter frontu ktorú má vypísať.
*/
void vypis_frontu_stdout(queue<string> fronta);


