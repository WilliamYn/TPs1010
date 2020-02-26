#include "Librairie.h"

// To do
//Constructeur par copie
Librairie::Librairie(const Librairie& librairie)
{
    // To do
    for(int i=0; i<librairie.medias_.size(); i++){
        medias_.push_back(std::move(librairie.medias_[i])); //j'ai mis move mais jsp
    }
    /*Revoir. Selon Jango: 
    *this = librairie;
    Selon PDF:
    La méthode doit être modifiée pour prendre en considération le polymorphisme.
    La méthode utilise la méthode clone() de la classe Media.
    */
}

// To do
Librairie& Librairie::operator=(const Librairie& librairie)
{
    // To do
    if(this != &librairie){
        medias_.clear();
        for(int i=0; i<librairie.medias_.size(); i++){
            medias_[i] = std::make_unique<Media>(librairie.medias_[i].get()); //pas sur
        }
    }
}

//! Destructeur de la classe Librairie
Librairie::~Librairie()
{
    medias_.clear();
}

// To do
Film* Librairie::chercherFilm(const std::string& nomFilm)
{
    // To do
    Media* media = chercherMedia(nomFilm, Media::TypeMedia::Film);
    return dynamic_cast<Film*>(media);
}


// To do
Serie* Librairie::chercherSerie(const std::string& nomSerie)
{
    // To do
    Media* media = chercherMedia(nomSerie, Media::TypeMedia::Serie);
    return dynamic_cast<Serie*>(media);
}

// To do
void Librairie::ajouterSaison(const std::string& nomSerie, std::unique_ptr<Saison> saison)
{
    // To do
    *chercherSerie(nomSerie) += std::move(saison);
}

// To do
void Librairie::retirerSaison(const std::string& nomSerie, unsigned int numSaison)
{
    // To do
    *chercherSerie(nomSerie) -= numSaison;
}

// To do
void Librairie::ajouterEpisode(const std::string& nomSerie, unsigned int numSaison,
                               std::unique_ptr<Episode> episode)
{
    // To do
    *(chercherSerie(nomSerie)->getSaison) += episode;
    
}


void Librairie::retirerEpisode(const std::string& nomSerie, unsigned int numSaison,
                               unsigned int numEpisode)
{
    // To do
    *(chercherSerie(nomSerie)->getSaison) -= numEpisode;
}

//! Méthode qui charge les series à partir d'un fichier.
//! \param nomFichier           Le nom du fichier à lire.
//! \param gestionnaireAuteurs  Le gestionnaire des auteurs. Nécessaire pour associer une serie à un
//! auteur.
//! \return                     Un bool représentant si le chargement a été un succès.
bool Librairie::chargerMediasDepuisFichier(const std::string& nomFichier,
                                           GestionnaireAuteurs& gestionnaireAuteurs)
{
    // To do
    std::ifstream fichier(nomFichier);
    if(fichier){
        std::string ligne;
        while(getline(fichier, ligne)){
            if(!lireLigneMedia(ligne, gestionnaireAuteurs)){
                return false;
            }
        }
        return true;
    }
    return false;
}

//! Méthode qui charge les restrictions des series à partir d'un fichier.
//! \param nomFichier           Le nom du fichier à lire.
//! \return                     Un bool représentant si le chargement a été un succès.
bool Librairie::chargerRestrictionsDepuisFichiers(const std::string& nomFichier)
{
    std::ifstream fichier(nomFichier);
    if (fichier)
    {
        for (size_t i = 0; i < medias_.size(); i++)
            medias_[i]->supprimerPaysRestreints();

        std::string ligne;
        while (getline(fichier, ligne))
            if (!lireLigneRestrictions(ligne))
                return false;

        return true;
    }
    std::cerr << "Le fichier " << nomFichier
              << " n'existe pas. Assurez vous de le mettre au bon endroit.\n";
    return false;
}

// To do
size_t Librairie::getNbMedias() const
{
    // To do
    return medias_.size();
}

// To do
std::ostream& operator<<(std::ostream& os, const Librairie& librairie)
{
    // To do
}

// To do
size_t Librairie::trouverIndexMedia(const std::string& nomMedia) const
{
    // To do
    for(int i=0; i<medias_.size(); i++){
        if(medias_[i]->getNom == nomMedia){
            return i;
        }
    }
    return MEDIA_INEXSISTANT;
}

// To do
Librairie& Librairie::operator+=(std::unique_ptr<Media> media)
{
    // To do
    medias_.push_back(std::move(media));
}

// To do
Librairie& Librairie::operator-=(const std::string& nomMedia)
{
    // To do
    int indexMedia = trouverIndexMedia(nomMedia);
    if(indexMedia != MEDIA_INEXSISTANT){
        medias_.erase(medias_.begin() + indexMedia);
    }
    
}

// To do
Media* Librairie::chercherMedia(const std::string& nomMedia, Media::TypeMedia typeMedia)
{
    // To do
    int indexMedia = trouverIndexMedia(nomMedia);
    if(indexMedia==MEDIA_INEXSISTANT){
        return nullptr;
    }
    return medias_[indexMedia].get();
    //not using typeMedia??????????????????????????????????????
}

// To do
bool Librairie::lireLigneRestrictions(const std::string& ligne)
{
    // To do
    
}

// To do
bool Librairie::lireLigneMedia(const std::string& ligne, GestionnaireAuteurs& gestionnaireAuteurs)
{
    lireLigneMediaFunction fonctionLireligne[] = {&Librairie::lireLigneFilm,
                                                  &Librairie::lireLigneSerie,
                                                  &Librairie::lireLigneSaison,
                                                  &Librairie::lireLigneEpisode};
    std::istringstream stream(ligne);
    int typeMediaValeurEnum;

    if (stream >> typeMediaValeurEnum)
        return invoke(fonctionLireligne[typeMediaValeurEnum], *this, stream, gestionnaireAuteurs);

    return false;
}

// To do
const std::vector<std::unique_ptr<Media>>& Librairie::getMedias() const
{
    // To do
    return medias_;
}

// To do
bool Librairie::lireLigneEpisode(std::istream& is, GestionnaireAuteurs&)
{
    // To do
}

// To do
bool Librairie::lireLigneSaison(std::istream& is, GestionnaireAuteurs&)
{
    // To do
}

// To do
bool Librairie::lireLigneSerie(std::istream& is, GestionnaireAuteurs& gestionnaireAuteurs)
{
    // To do
}

// To do
bool Librairie::lireLigneFilm(std::istream& is, GestionnaireAuteurs& gestionnaireAuteurs)
{
    // To do

    std::string nomAuteur, duree;
    Auteur* auteur;

    if(!(is >> nomAuteur)){
        return false;
    }
    auteur = gestionnaireAuteurs.chercherAuteur(nomAuteur);
    Film film(auteur);
    if(!(is>>film>>duree)){
        return false;
    }
    *this += std::make_unique<Film>(film);

    //on n'a pas utilisé set et getNbMedias de la classe Auteur
    //UNFINISHED FUNCTION: il faut set lire la duree et le mettre dans le film
    
}

// To do
size_t Librairie::getNbFilms() const
{
    // To do
    uint nbFilms = 0;
    for(int i=0; i<medias_.size(); i++){
        if(medias_[i]->getTypeMedia() == Media::TypeMedia::Film){
            nbFilms++;
        }
    }
}

// To do
size_t Librairie::getNbSeries() const
{
    // To do
    uint nbSeries = 0;
    for(int i=0; i<medias_.size(); i++){
        if(medias_[i]->getTypeMedia() == Media::TypeMedia::Serie){
            nbSeries++;
        }
    }
}

// To do
size_t Librairie::getNbSaisons(const std::string& nomSerie) const
{
    // To do
    int indexSerie = trouverIndexMedia(nomSerie);
    return dynamic_cast<Serie*>((medias_[indexSerie]).get())->getNbSaisons();
    //je n'utilise pas chercherSerie

}

// To do
size_t Librairie::getNbEpisodes(const std::string& nomSerie, const unsigned int numSaison) const
{
    // To do
    int indexSerie = trouverIndexMedia(nomSerie);
    return dynamic_cast<Serie*>((medias_[indexSerie]).get())->getSaison(numSaison)->getNbEpisodes();
}
