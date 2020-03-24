/*
 * Titre : PivoterMatrice.h - Travail Pratique #4 - Programmation Orient�e Objet
 * Date : 27 F�vrier 2020
 * Auteur : Nabil Dabouz
 */

#ifndef PIVOTER_MATRICE_H
#define PIVOTER_MATRICE_H

#include "def.h"

template <class M> class PivoterMatrice {
public:
  // Constructeurs
  PivoterMatrice();
  PivoterMatrice(M *matrice);
  // Destructeur
  ~PivoterMatrice() = default;
  void pivoterMatrice(Direction direction);

private:
  Coordonnees changerCoordonneesCentreMatrice(Coordonnees coords) const;
  Coordonnees recupererCoordonnees(Coordonnees coords) const;
  M *matrice_;
};

/**
 * @brief constructeur par défaut de la classe
 */
template <class M> inline PivoterMatrice<M>::PivoterMatrice() : matrice_(nullptr) {
  // TO DO
}

/**
 * @brief constructeur par paramètre de la classe
 */
template <class M>
inline PivoterMatrice<M>::PivoterMatrice(M *matrice) : matrice_(matrice) {
    //TODO
}


/**
 * @brief trouver les coordonnées du point par rapport au centre de la matrice
 * @param coords les coordonnées du point originales
 */
template <class M>
inline Coordonnees
PivoterMatrice<M>::changerCoordonneesCentreMatrice(Coordonnees coords) const {
  // TO DO
    int width = matrice_->getWidth();
    int milieu = (int)(width / 2.0);
    Coordonnees nouvellesCoordonnees{ coords.x - milieu, coords.y - milieu };
    return nouvellesCoordonnees;
}
/**
 * @brief revenir au système précédent, trouver les coordonnées du point par
 * rapport au premier élément de la matrice
 * @param coords les coordonnées du point originales
 */
template <class M>
inline Coordonnees
PivoterMatrice<M>::recupererCoordonnees(Coordonnees coords) const {
  // TO DO
    int width = matrice_->getWidth();
    int milieu = (int)(width / 2.0);
    Coordonnees anciennesCoordonnees{ coords.x + milieu, coords.y + milieu };
    return anciennesCoordonnees;
}

//Todo
//Pivoter matrice
template<class M>
inline void PivoterMatrice<M>::pivoterMatrice(Direction direction)
{
    std::unique_ptr<M> copieMatrice = matrice_->clone();
    for(int y=0; y<matrice_->getHeight(); y++){
        for(int x=0; x<matrice_->getWidth(); x++){
            Coordonnees coordonnees{ x, y };
            Coordonnees nouvellesCoordonnees = changerCoordonneesCentreMatrice(coordonnees);
            Coordonnees copieCoordonnees = nouvellesCoordonnees;

            //si on choise la direction 0 donc on va faire une rotation centree en 0.0 et vers la droite
            if (direction == Direction::Right) {
                //      [x, y] --> [y, -x]

                copieCoordonnees.x = nouvellesCoordonnees.y;
                copieCoordonnees.y = -nouvellesCoordonnees.x;
            }
            //si on choise la direction 0 donc on va faire une rotation centree en 0.0 et vers la gauche
            else if (direction == Direction::Left) {
                //      [x, y] --> [-y, x]

                copieCoordonnees.x = -nouvellesCoordonnees.y;
                copieCoordonnees.y = nouvellesCoordonnees.x;
            }
            
            nouvellesCoordonnees.x = copieCoordonnees.x;
            nouvellesCoordonnees.y = copieCoordonnees.y;
            recupererCoordonnees(nouvellesCoordonnees);
		}
	}
    

          
}

#endif
