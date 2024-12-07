#include "MatrixChain.h"

/**
 * @brief Konštruktor
 *
 * Použil som tabuľky `min_naklady` a `body_rozdelenia` na dynamické programovanie.
 * Tabuľka `min_naklady` uchováva minimálne náklady na násobenie podreťazcov,
 * zatiaľ čo tabuľka `body_rozdelenia` slúži na rekonštrukciu optimálneho uzátvorkovania.
 * Používam tu inicializáciu cez `this`.
 *
 * @param rozmery Vektor rozmerov matíc.
 */



MatrixChain::MatrixChain(const vector<int>rozmery) {

	this->rozmery = rozmery;
	this->min_naklady = vector<vector<int>>(rozmery.size(), vector<int>(rozmery.size(), 0));
	this->body_rozdelenia = vector<vector<int>>(rozmery.size(), vector<int>(rozmery.size(), -1));
}
	

/**
 * @brief Vypočíta minimálne náklady na násobenie podreťazca matíc.
 *
 * Táto funkcia iteratívne prechádza všetky možné body rozdelenia podreťazca a aktualizuje
 * tabuľku `min_naklady`, ak nájde menšie náklady.
 * - Pre každý bod rozdelenia \( k \) sa vypočítajú celkové náklady ako:
 *   \( \text{min\_naklady}[zaciatok][k] + \text{min\_naklady}[k][koniec] + \text{rozmery}[zaciatok] \cdot \text{rozmery}[k] \cdot \text{rozmery}[koniec] \).
 *
 * @param zaciatok Index začiatku podreťazca.
 * @param koniec Index konca podreťazca.
 */
 


void MatrixChain::vypocet_nakladov(size_t zaciatok, size_t koniec) {
	
		for (size_t index = zaciatok + 1; index < koniec;index++)
		{
			int naklady = min_naklady[zaciatok][index] + min_naklady[index][koniec] + rozmery[zaciatok] * rozmery[index] * rozmery[koniec];

			if (naklady<min_naklady[zaciatok][koniec])
			{
				min_naklady[zaciatok][koniec] = naklady;
				body_rozdelenia[zaciatok][koniec] = index;

			}

		}
	
	
	}






/**
 * @brief Implementuje dynamické programovanie na výpočet minimálnych nákladov.
 *
 * Použil som túto funkciu na postupné vypĺňanie tabuľky `min_naklady` od najkratších podreťazcov po celý reťazec.
 * Hodnota `std::numeric_limits<int>::max()` slúži na inicializáciu najhoršieho prípadu (nekonečno). Použil som ju, aby som mal istotu,
 * že každá hodnota importovaná pri porovnávaní nákladov bude vždy menšia.
 *
 * @param rozmery Vektor rozmerov matíc.
 * @return Minimálne náklady na násobenie celého reťazca.
 */

int MatrixChain::vypocet_poctu_nasobenia(const vector<int>& rozmery) {

	

	size_t n = rozmery.size(); 
	size_t min_pocet_matic = 2; 	
	for (size_t dlzka = min_pocet_matic; dlzka < n; dlzka++)
	{
		for (size_t zaciatok = 0; zaciatok < n - dlzka; zaciatok++) 
		{
			size_t koniec = zaciatok + dlzka;

			min_naklady[zaciatok][koniec] = numeric_limits<int>::max();

			vypocet_nakladov(zaciatok, koniec);
		
		}

	}

	return min_naklady[0][n - 1];
}

/**
 * @brief Získava minimálny počet násobení pre celý reťazec matíc.
 *
 * Použil som túto funkciu na jednoduchý prístup k výsledku uloženému v tabuľke `min_naklady`.
 * Funkcia vracia hodnotu uloženú v ľavom hornom rohu tabuľky (prvok [0][size-1]),
 * ktorá reprezentuje minimálne náklady na násobenie celého reťazca od prvej po poslednú maticu.
 *
 * @return Minimálny počet násobení potrebných na vynásobenie celého reťazca matíc.
 */



int MatrixChain::minimalny_pocet_nasobeni() const {

	size_t size = rozmery.size() - 1;

	return min_naklady[0][size];

}


/**
 * @brief Funkcia rekonštruuje optimálne uzátvorkovanie reťazca matíc.
 *
 * Táto funkcia je rekurzívna a využíva tabuľku `body_rozdelenia` na určenie
 * optimálneho bodu rozdelenia pre podreťazec. Na základe tohto bodu rozdelenia
 * sa funkcia volá rekurzívne pre ľavú a pravú časť podreťazca.
 *
 * Použil som túto funkciu na vytvorenie reťazca reprezentujúceho optimálne uzátvorkovanie,
 * napríklad: \(((A_0 A_1) A_2) A_3\).
 *
 * Vysvetlenie logiky:
 * - Ak je podreťazec \( A_{zaciatok} \) až \( A_{koniec} \) len jedna matica, nie je potrebné ďalšie uzátvorkovanie.
 * - Ak je podreťazec dlhší, optimálny bod rozdelenia sa získava z tabuľky `body_rozdelenia`.
 *
 * @param zaciatok Index začiatku podreťazca.
 * @param koniec Index konca podreťazca.
 * @return Reťazec reprezentujúci optimálne uzátvorkovanie podreťazca.
 */

string MatrixChain::uzatvorkuj(size_t zaciatok,size_t koniec) {


	if (zaciatok + 1 == koniec) {

		return "A_" + to_string(zaciatok);
	}

	size_t bod_rozdelenia = body_rozdelenia[zaciatok][koniec];

	string left = uzatvorkuj(zaciatok, bod_rozdelenia);
	string right = uzatvorkuj(bod_rozdelenia, koniec);


	return "(" + left + " " + right + ")";

}