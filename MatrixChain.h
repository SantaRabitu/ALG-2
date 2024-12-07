#pragma once
#include<iostream>

#include<vector>
#include<climits>
#include<string>

using std::vector, std::cout,std::string,std::ostringstream;
using std::numeric_limits;
using std::string;
using std::to_string;


/**
 * @brief Trieda MatrixChain implementuje algoritmus dynamického programovania špeciálne pre prípad môjho projektu.
 * Táto trieda poskytuje metódy na výpočet minimálneho počtu násobení potrebných na vynásobenie reťazca matíc a na určenie optimálneho uzátvorkovania.
 * Trieda využíva dve hlavné tabuľky:
 * - `min_naklady`: Ukladá minimálne náklady na násobenie podreťazcov.
 * - `body_rozdelenia`: Ukladá indexy optimálnych bodov rozdelenia.
 *  Dynamic programming is a technique for solving problems with overlapping
 subproblems.Typically,thesesubproblemsarisefromarecurrencerelatingagiven
 problem’s solution to solutions of its smaller subproblems. Rather than solving
 overlappingsubproblemsagainandagain,dynamicprogrammingsuggestssolving
 eachofthesmallersubproblemsonlyonceandrecordingtheresultsinatablefrom
 which a solution to the original problem can then be obtained. - Levitin 283. st.

 *reťazec matic som reprezentoval triedou v OOP štýle, sú tu konštruktory, privátne a verejné funkcie, dynamické objekty, mazanie objektov, inicializácia cez this.
 */



class MatrixChain
{

private:
	vector<vector<int>> min_naklady; ///<reprezentuje tabulku min. nákladov
	vector<vector<int>> body_rozdelenia; ///< tabulka optimálnych bodov rozdelenia
	vector<int> rozmery; ///<retazec, postupnosť matic, rozmery


	/**
	 * @brief Pomocná metóda na výpočet nákladov pre podreťazec.
	 *
	 * @param zaciatok Index začiatku podreťazca.
	 * @param koniec Index konca podreťazca.
	 */

	void vypocet_nakladov(size_t zaciatok, size_t koniec);

public:

	/**
	 * @brief Konštruktor inicializuje tabuľky a ukladá rozmery matíc.
	 *
	 * @param rozmery Vektor obsahujúci rozmery matíc.
	 */
	MatrixChain(const vector<int> rozmery);

	/**
 * @brief Vypočíta minimálny počet násobení pre celý reťazec.
 *
 * @param rozmery Vektor obsahujúci rozmery matíc.
 * @return Minimálny počet násobení.
 */

 /**
  * @brief Vráti minimálny počet násobení pre celý reťazec.
  *
  * @return Minimálny počet násobení.
  */

	int vypocet_poctu_nasobenia(const vector<int>&rozmery);




	/**
	* @brief Vráti minimálny počet násobení pre celý reťazec.
	*
	* @return Minimálny počet násobení.
	*/
	int minimalny_pocet_nasobeni() const;

	/**
	 * @brief Funkcia rekonštruuje optimálne uzátvorkovanie.
	 *
	 * @param zaciatok Index začiatku podreťazca.
	 * @param koniec Index konca podreťazca.
	 * @return Funkcia vráti reťazec reprezentujúci optimálne uzátvorkovanie.
	 */

	string uzatvorkuj(size_t zaciatok, size_t koniec);


};

