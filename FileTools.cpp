#include"FileTools.h"
#include"MatrixChain.h"

bool FileHandler::nacitaj_subor(const string& filename, queue<string>& result) {

	fstream subor;
	subor.open(filename, ios::in);
	if (!subor.is_open())
	{
        return false;
	}
    result = queue<string>();
    spracuj_subor(subor,result);
    subor.close();
    return true;
}

/**
    * @brief Táto funkcia spracuváva súbor, kým sa v cykle riadky načítajú, volá sa v nej funkcia spracuj_riadok() na každý riadok.
    * @param subor Berie referenciu na súbor použitý k operácii.
    * @param fronta Je referencia na frontu kde sa bude vkládať.
    */



void FileHandler::spracuj_subor(std::fstream& subor, std::queue<std::string>& f) {
    std::string line;

    while (getline(subor, line)) {
        spracuj_riadok(line, f);
    }
}

/**
    * @brief V tejto funkcii sa využivaju funkcie ako stringtovector(), vysledok () a dajdofronty(). Môžeme tu zazrieť kompletnu úpravu a prípravu a vklad riadku do fronty správne navrhnutých výstupov.
    * Táto funkcia urobí z nespracovaného riadku zo súboru, pekne spracovaný a ošetrený reťazec, ktorý vloží do fronty.
    * @param riadok Parameter berie referenciu na riadok určený k úprave a výpočtom.
    * @param vysledna_fronta Fronta, kde sa bude riadok vkládať.
    */

bool FileHandler::spracuj_riadok(const string& riadok, std::queue<std::string>& data) {
    vector<int> postupnost = string_to_vector(riadok);
    if (postupnost.empty())
    {
        return false;
    }

    string vysledny_riadok = vysledok(postupnost);
    daj_do_fronty(data, vysledny_riadok);
    return true;
}


/**
*@brief Funkcia má na starosti načítaný riadok previesť do vektoru čísel. Slúži tak či už pre ľahkosť operácií, tak aj pre overenie a istotu, že pracujeme skutočne s číslami, tak ako máme, a nie s nejakými znakmi, ktoré by
* ohrozili operáciu.
*@param riadok. Je referencia na riadok v načítanom súbore, ktorý sa bude spracovávať.
*@return Funkcia vráti vektor intov, s ktorými sa bude výborne prácovať na ukládanie reťazcov postupnosti matic.
*/

vector<int> FileHandler::string_to_vector(const std::string& line) {
    std::vector<int> postupnost;
    std::istringstream iss(line);
    std::string token;

    while (iss >> token) {
        int number = std::stoi(token);
        postupnost.push_back(number);
    }
    return postupnost;
}
/**
    *@brief Funkcia pripraví do výslednej fronty reťazec matic, pekne pridá zátvorky, vypiše počet násobení, optimálne uzátvorkovanie a všetko to zaobalí do reťazca reprezentujúci jeden riadok.
    * Pekne je tu vidno aj dynamicke vytváranie objektu chain, pre každý riadok špecialny.
    *@param retazec Funkcia prijma ako parameter referenciu na retazec postupnosti matic na ktorom sa prevadzali operácie.
    * @return Funkcia tak ako som spomínal vráti pekne pripravený string reprezentujúci riadok na uloženie do fronty, skládajuci sa z reťazca, počtu násobenia, optimalneho uzátvorkovania pre optimálne násobenie. Tak ako to zadanie vyžaduje.
    *
    */

string FileHandler::vysledok(const vector<int>&retazec) {
    int n = retazec.size() - 1;
    ostringstream formatovany_vysledok;
    
     
    MatrixChain* chain = new MatrixChain(retazec);
    int minimal_nasobenie = chain->vypocet_poctu_nasobenia(retazec);
    string uzatvorkovanie = chain->uzatvorkuj(0,n);
    for  (const int &r :retazec)
    {
        formatovany_vysledok << r << " ";

    }
    formatovany_vysledok << uzatvorkovanie << " " << minimal_nasobenie; 

    delete(chain);
    string hotovy_format = formatovany_vysledok.str();

    return hotovy_format;

}

/**
    *@brief Táto funkcia už priamo dáva do fronty spracovaný riadok.
    *@param vysledna_fronta Do tejto fronty sa to bude ukladať. Preto je potrebne frontu pred vkladom vyčistiť, ak budeme zadavať prvy riadok.
    *@param hotovy_riadok Tento riadok sa bude vkladať do fronty.
    */
void FileHandler::daj_do_fronty(queue<string>& vysledna_fronta, string& hotovy_riadok) {

    vysledna_fronta.push(hotovy_riadok);
}

bool FileHandler::vytvor_subor(const string& filename, queue<string>& data) {


    fstream subor;
    subor.open(filename, ios::out);
    if (!subor.is_open())
    {
        return false;
    }
    while (!data.empty())
    {
        subor << data.front() << endl << "\n";
        data.pop();
    }
    subor.close();
    return true;    
}

void FileHandler::zapis_do_suboru(const string& name, queue<string> &fronta) {

    if (vytvor_subor(name,fronta)==true)
    {
        return;

    }
    else
    {
        std::cerr << "Chyba" << endl;
        exit(-1);
    }

}
void vypis_frontu_stdout(queue<string>fronta) {

    while (!fronta.empty())
    {
        cout << fronta.front() << endl;
        cout << endl;
        fronta.pop();
    }

}