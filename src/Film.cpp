// To do
// done
#include "Film.h"
#include "Media.h"

// To do
Film::Film(Auteur* auteur)
    : Media(auteur, TypeMedia::Film)
    , duree_("")
// To do
{
}

// To do
Film::Film(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
           bool estRestreintParAge, Auteur* auteur, const std::string& duree)
    : Media(nom, anneeDeSortie, genre, pays, estRestreintParAge, auteur, TypeMedia::Film)
    , duree_(duree)
// To do
{
}

// To do
std::ostream& Film::afficher(std::ostream& os) const
{
    // To do
    Media::afficher(os) << "\tDuree:" << duree_ << std::endl << std::endl;
    return os;
}

// To do
std::istream& Film::lire(std::istream& is)
{ // To do

    Media::lire(is) >> std::quoted(duree_);
    return is;
}

// To do
std::unique_ptr<Media> Film::clone() const
{
    // To do
    return std::make_unique<Film>(*this);
}
