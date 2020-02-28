// To do
#include "Serie.h"

// To do              Pointeur vers l'auteur du serie
Serie::Serie(Auteur* auteur)
    : Media(auteur, Media::TypeMedia::Serie)
    , GestionnaireSaisons()
    // To do
{
}

// To do
Serie::Serie(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
             bool estRestreintParAge, Auteur* auteur)
    : Media(nom, anneeDeSortie, genre, pays, estRestreintParAge, auteur, Media::TypeMedia::Serie)
    , GestionnaireSaisons()
    // To do
{
}

// To do
//Constructeur par copie de serie
Serie::Serie(const Serie& serie)
    : Media(serie)
    // To do
{
    // To do
    for (int i = 0; i < serie.saisons_.size(); i++)
    {
        saisons_.push_back(std::make_unique<Saison>(*(serie.saisons_[i])));
    }
}

// To do
std::ostream& Serie::afficher(std::ostream& os) const
{
    // To do
    Media::afficher(os);
    //GestionnaireSaisons::afficher(os); //pas suuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuur. Car classe abstraite????????????????????
    //Il ne faut pas appeler afficher de GestionnaireSaison car celui ci est =0
    return os;
}

// To do
std::unique_ptr<Media> Serie::clone() const
{
    // To do
    return std::make_unique<Media>(*this);
    //make_unique prend l'objet entre parenthèses, le copie et retourne un unique_ptr qui y pointe

}