

#ifndef FONCTEURS_H
#define FONCTEURS_H

#include <string>
#include <unordered_map>
#include "LigneLog.h"

//Il manque sûrement des includes


class EstDansIntervalleDatesFilm
{
public:
    EstDansIntervalleDatesFilm (int anneeInferieure, int anneeSuperieure) : 
        min_(anneeInferieure), 
        max_(anneeSuperieure){};

    bool operator()(const std::unique_ptr<Film>& film)//prendre en parametrestd::unique_ptr
    {
        return (film->annee >= min_ && film->annee <= max_);
	};		  
private:
    int min_, max_;
};

class ComparateurLog
{
public:
	ComparateurLog(){};
	bool operator()(LigneLog ligneLog1, LigneLog ligneLog2)
	{
		return (ligneLog1.timestamp < ligneLog2.timestamp);
	};
};

template<class T1,class T2>
class ComparateurSecondElementPaire
{
public:
	ComparateurSecondElementPaire(){};
	bool operator()(const std::pair<T1, T2>& pair1 , const std::pair<T1, T2>& pair2)
	{
		return (pair1.second<pair2.second);
	}
};
#endif
