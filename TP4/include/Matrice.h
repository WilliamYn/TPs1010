/*
 * Titre : Matrice.h - Travail Pratique #4 - Programmation Orient�e Objet
 * Date : 27 F�vrier 2020
 * Auteur : Nabil Dabouz
 */

#ifndef MATRICE_H
#define MATRICE_H

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

template <typename T> class Matrice {

public:
  Matrice();
  // Destructeur
  ~Matrice() = default;
  T operator()(const size_t &posY, const size_t &posX) const;
  // Lecture du fichier
  bool chargerDepuisFichier(const std::string &nomFichier);
  bool lireElement(const std::string &elementFichier, const size_t &posY,
                   const size_t &posX);
  // Remplir un matrice
  bool ajouterElement(T element, const size_t &posY, const size_t &posX);
  // Faire une copie
  std::unique_ptr<Matrice<T>> clone() const;
  // Setters
  void setHeight(size_t height);
  void setWidth(size_t width);
  // Getters
  size_t getHeight() const;
  size_t getWidth() const;

private:
  std::vector<std::vector<T>> elements_;
  size_t height_;
  size_t width_;
};

namespace {
static constexpr int CAPACITE_MATRICE = 100;
}

/**
 * @brief constructeur par défaut de la classe
 */
template <typename T> inline Matrice<T>::Matrice() : height_(0), width_(0), elements_(CAPACITE_MATRICE) 
{ 
  // TO DO
    for(int i=0; i<CAPACITE_MATRICE; i++){
        elements_[i] = std::vector<T>(CAPACITE_MATRICE);
	}
    //Vérifier capacite_matrice
}
/**
 * @brief retourne le nombre de lignes de la matrice
 * @return l'attribut height_ de l'objet
 */
template <typename T> inline size_t Matrice<T>::getHeight() const 
{
  return height_;
}
/**
 * @brief retourne le nombre de colonnes de la matrice
 * @return l'attribut width_ de l'objet
 */
template <typename T> inline size_t Matrice<T>::getWidth() const 
{
  return width_;
}

//Todo
//Opérateur ()
template <typename T> T Matrice<T>::operator()(const size_t &posY, const size_t &posX) const
{
    if(posY < height_ && posX < width_ && posY >= 0 && posX >= 0){
        return elements_[posY][posX];
	}
    return T();
}

//Todo
//Ajoute un élément passé en paramètre dans la position correspondante
template <typename T> bool Matrice<T>::ajouterElement(T element, const size_t &posY, const size_t &posX)
{
    bool ajoutEffectue = false;
    if(posY < CAPACITE_MATRICE && posX < CAPACITE_MATRICE && posY >= 0 && posX >= 0){
        (elements_[posY]).insert(elements_[posX].begin() + posX, element);
        ajoutEffectue = true;
	}
    return ajoutEffectue;
}

//Todo
//Lit l'élément à partir de la chaine de caracteres puis lajoute dans la matrice
template <typename T> bool Matrice<T>::lireElement(const std::string &elementFichier, const size_t &posY, const size_t &posX)
{
    T element;
    std::stringstream streamElement;
    streamElement.str(elementFichier);
    streamElement >> element;
    return ajouterElement(element);
}

//Todo
//Charge la matrice à partir du fichier passe en parametre
// Peux etreee il yaura une fautee
template <typename T> bool Matrice<T>::chargerDepuisFichier(const std::string &nomFichier)
{
    std::string ligne, mot;
    ifstream fichier(nomFichier);
    if(fichier){
        int posY = -1, posX = 0;
        while(getline(fichier, ligne){ 
            if (ligne == 'L') {
                posY++;
                posX = 0;
                continue;
            }
            std::stringstream streamLigne;
            streamLigne(ligne);
            while(streamLigne >> mot){
                (lireElement(mot, posY, posX)) ? : return false;
                posX++;
			}
		}
        return true;
	}
    return false;
    //Vérifier la validité de ce code
}

//Todo
//retourne un pointeur vers une copie de la matrice
template <typename T> std::unique_ptr<Matrice<T>> Matrice<T>::clone() const
{
    return std::make_unique<T>(*this);
}

//Todo
//setter pour le height
template<typename T> inline void Matrice<T>::setHeight(size_t height)
{
    height_ = (height < CAPACITE_MATRICE) ? height : CAPACITE_MATRICE;
    height_ = (height_ > 0) ? height_ : 0;
}

//Todo
//setter pour le width
template<typename T> inline void Matrice<T>::setWidth(size_t width)
{
    width_ = (width < CAPACITE_MATRICE) ? width : CAPACITE_MATRICE; 
    width_ = (width_ > 0) ? width_ : 0;
}




#endif
