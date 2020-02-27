#include "Media.h"
#include "Auteur.h"

namespace
{
    //! Fonction qui convertit le enum Media::Genre en string
    //! \param genre    Le genre à convertir
    //! \return         Le string qui représente le enum
    const std::string& getGenreString(Media::Genre genre)
    {
        static const std::string NOMS_GENRES[] = {"Action",
                                                  "Aventure",
                                                  "Comedie",
                                                  "Horreur",
                                                  "Romance"};

        auto index = enum_value(genre);
        assert(valid_as_enum<Media::Genre>(index));
        return NOMS_GENRES[index];
    }

    //! Fonction qui convertit le enum Pays en string
    //! \param pays     Le pays à convertir
    //! \return         Le string qui représente le enum
    const std::string& getPaysString(Pays pays)
    {
        static const std::string NOMS_PAYS[] = {"Bresil",
                                                "Canada",
                                                "Chine",
                                                "EtatsUnis",
                                                "France",
                                                "Japon",
                                                "RoyaumeUni",
                                                "Russie",
                                                "Mexique"};
        auto index = enum_value(pays);
        assert(valid_as_enum<Pays>(index));
        return NOMS_PAYS[index];
    }
} // namespace

// To do
Media::Media(Auteur* auteur, Media::TypeMedia typeMedia)
    : auteur_(auteur)
    , typeMedia_(typeMedia)//iciiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii

// To do
{
}

// To do
Media::Media(const std::string& nom, unsigned int anneeDeSortie, Genre genre, Pays pays,
             bool estRestreintParAge, Auteur* auteur, Media::TypeMedia typeMedia)
    : nom_(nom)
    , anneeDeSortie_(anneeDeSortie)
    , genre_(genre)
    , pays_(pays)
    , estRestreintParAge_(estRestreintParAge)
    , auteur_(auteur)
    , typeMedia_(typeMedia)
// To do
{
}

// To do
// Constructeur par copie
Media::Media(const Media& serie)
{
    // To do
    nom_ = serie.nom_;
    anneeDeSortie_ = serie.anneeDeSortie_;
    genre_ = serie.genre_;
    pays_ = serie.pays_;
    estRestreintParAge_ = serie.estRestreintParAge_;
    auteur_ = serie.auteur_;
    typeMedia_ = serie.typeMedia_;
    for (int i = 0; i < serie.paysRestreints_.size(); i++)
    {
        paysRestreints_.push_back(serie.paysRestreints_[i]);
    }
}

// To do
Media::~Media()
{ // destructeur virttuellllllllllllllllllllllllllllllllllllllllllllllllllllllll
  // To do
}

// To do
void Media::ajouterPaysRestreint(Pays pays)
{
    // To do
    paysRestreints_.push_back(pays);
}

// To do
void Media::supprimerPaysRestreints()
{
    // To do
    paysRestreints_.clear();
}

// To do
// Regarde si le pays passé en paramètre est dans paysRestreints
bool Media::estRestreintDansPays(Pays pays) const
{
    // To do
    for (int i = 0; i < paysRestreints_.size(); i++)
    {
        if (paysRestreints_[i] == pays)
        {
            return true;
        }
    }
    return false;
}

// To do
bool Media::estRestreintParAge() const
{
    // To do
    // done
    return estRestreintParAge_;
}

// To do
std::ostream& Media::afficher(std::ostream& os) const
{
    // To do
    os << nom_ << std::endl;
    os << "\tDate de anneeDeSortie_:" << anneeDeSortie_ << std::endl;
    os << "\tGenre: " << getGenreString(genre_) << std::endl;
    os << "\tAuteur: " << auteur_ << std::endl;
    os << "\tPays: " << getPaysString(pays_) << std::endl;
    if (paysRestreints_.size() == 0)
    {
        os << "\tAucun pays restreints." << std::endl;
    }
    else
    {
        for (int i = 0; i < paysRestreints_.size(); i++)
        {
            os << "\t\t" << getPaysString(paysRestreints_[i]);
        }
    }
    return os;
}

// To do
std::ostream& operator<<(std::ostream& os, const Media& media)
{ // To do
    return media.afficher(os);
}

// To do
Media::Genre Media::getGenre() const
{
    // To do
    return genre_;
}

// To do
const std::string& Media::getNom() const
{
    // To do
    return nom_;
}

// To do
Media::TypeMedia Media::getTypeMedia() const
{
    // To do
    return typeMedia_;
}

// To do
std::istream& Media::lire(std::istream& is)
{
    // To do
    //On a enlevé type et auteur
    int valeurNumeriqueGenre, valeurNumeriquePays;
    is >> std::quoted(nom_) >> anneeDeSortie_ >> valeurNumeriqueGenre >>
        valeurNumeriquePays >> estRestreintParAge_;
    genre_ = static_cast<Genre>(valeurNumeriqueGenre);
    pays_ = static_cast<Pays>(valeurNumeriquePays);
    return is;
}

// To do
std::istream& operator>>(std::istream& is, Media& media)
{
    return media.lire(is);
}

// To do
std::unique_ptr<Media> Media::clone() const
{
    // To do
    return std::make_unique<Media>(*this);
}