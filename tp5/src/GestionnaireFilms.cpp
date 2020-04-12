/// Gestionnaire de films.
/// \author Misha Krieger-Raynauld
/// \date 2020-01-12

#include "GestionnaireFilms.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include "Foncteurs.h"
#include "RawPointerBackInserter.h"

/// Constructeur par copie.
/// \param other    Le gestionnaire de films à partir duquel copier la classe.
GestionnaireFilms::GestionnaireFilms(const GestionnaireFilms& other)
{
    films_.reserve(other.films_.size());
    filtreNomFilms_.reserve(other.filtreNomFilms_.size());
    filtreGenreFilms_.reserve(other.filtreGenreFilms_.size());
    filtrePaysFilms_.reserve(other.filtrePaysFilms_.size());

    for (const auto& film : other.films_)
    {
        // TODO: Uncomment une fois que la fonction ajouterFilm est écrite
         ajouterFilm(*film);
    }
}

/// Opérateur d'assignation par copie utilisant le copy-and-swap idiom.
/// \param other    Le gestionnaire de films à partir duquel copier la classe.
/// \return         Référence à l'objet actuel.
GestionnaireFilms& GestionnaireFilms::operator=(GestionnaireFilms other)
{
    std::swap(films_, other.films_);
    std::swap(filtreNomFilms_, other.filtreNomFilms_);
    std::swap(filtreGenreFilms_, other.filtreGenreFilms_);
    std::swap(filtrePaysFilms_, other.filtrePaysFilms_);
    return *this;
}

/// Affiche les informations des films gérés par le gestionnaire de films à la sortie du stream donné.
/// \param outputStream         Le stream auquel écrire les informations des films.
/// \param gestionnaireFilms    Le gestionnaire de films à afficher au stream.
/// \return                     Une référence au stream.
std::ostream& operator<<(std::ostream& outputStream, const GestionnaireFilms& gestionnaireFilms)
{
    // TODO: Uncomment une fois que la fonction getNombreFilms est écrite
    outputStream << "Le gestionnaire de films contient "  << gestionnaireFilms.getNombreFilms() << " films.\n"
                 << "Affichage par catégories:\n";

    // TODO: Réécrire l'implémentation avec des range-based for et structured bindings (voir énoncé du TP)
    // for (auto it = gestionnaireFilms.filtreGenreFilms_.cbegin(); it != gestionnaireFilms.filtreGenreFilms_.cend();
    //         ++it)
    // {
    //     Film::Genre genre = it->first;
    //     std::vector<const Film*> listeFilms = it->second;
    //     outputStream << "Genre: " << getGenreString(genre) << " (" << listeFilms.size() << " films):\n";
    //     for (std::size_t i = 0; i < listeFilms.size(); i++)
    //     {
    //         outputStream << '\t' << *listeFilms[i] << '\n';
    //     }
    // }
    for(auto& [genre, films] : gestionnaireFilms.filtreGenreFilms_)
    {
        //films est un std::vector<const Film*>
        outputStream << "Genre: " << getGenreString(genre) << " (" <<  films.size() << " films):\n";
        for(auto& film : films)
            outputStream << '\t' << *film << '\n';
    }
    return outputStream;
}

/// Ajoute les films à partir d'un fichier de description des films.
/// \param nomFichier   Le fichier à partir duquel lire les informations des films.
/// \return             True si tout le chargement s'est effectué avec succès, false sinon.
bool GestionnaireFilms::chargerDepuisFichier(const std::string& nomFichier)
{
    std::ifstream fichier(nomFichier);
    if (fichier)
    {
        films_.clear();
        filtreNomFilms_.clear();
        filtreGenreFilms_.clear();
        filtrePaysFilms_.clear();

        bool succesParsing = true;

        std::string ligne;
        while (std::getline(fichier, ligne))
        {
            std::istringstream stream(ligne);

            std::string nom;
            int genre;
            int pays;
            std::string realisateur;
            int annee;

            if (stream >> std::quoted(nom) >> genre >> pays >> std::quoted(realisateur) >> annee)
            {
                // TODO: Uncomment une fois que la fonction ajouterFilm est écrite
                 ajouterFilm(Film{nom, static_cast<Film::Genre>(genre), static_cast<Pays>(pays), realisateur, annee});
            }
            else
            {
                std::cerr << "Erreur GestionnaireFilms: la ligne " << ligne
                          << " n'a pas pu être interprétée correctement\n";
                succesParsing = false;
            }
        }
        return succesParsing;
    }
    std::cerr << "Erreur GestionnaireFilms: le fichier " << nomFichier << " n'a pas pu être ouvert\n";
    return false;
}

//TODO
const Film* GestionnaireFilms::getFilmParNom(const std::string& nom) const
{
    auto it = filtreNomFilms_.find(nom);
    if(it!=filtreNomFilms_.end())
        return it->second;
    return nullptr;
}

//TODO
bool GestionnaireFilms::ajouterFilm(const Film& film)
{
    if(getFilmParNom(film.nom)==nullptr)
    {
        films_.push_back(std::make_unique<Film>(film));
        filtreNomFilms_.emplace(film.nom, films_.back().get());
        filtreGenreFilms_[film.genre].push_back(films_.back().get());
        filtrePaysFilms_[film.pays].push_back(films_.back().get());
        return true;
    }
    return false;
}

//TODO
bool GestionnaireFilms::supprimerFilm(const std::string& nomFilm)
{
    //pas sur de l'implémentation pour les filtres de genre et pays. Peut-être utiliser un remove_if?
    auto it = std::find_if(films_.begin(), films_.end(), 
                            [&nomFilm](const std::unique_ptr<Film>& film){return film->nom == nomFilm;});
    if(it != films_.end())
    {
        filtreNomFilms_.erase(nomFilm);
        std::vector<const Film*>& filmsDuGenre = filtreGenreFilms_[(*it)->genre];
        filmsDuGenre.erase(std::remove(filmsDuGenre.begin(), filmsDuGenre.end(), it->get()), filmsDuGenre.end());
        std::vector<const Film*>& filmsDuPays = filtrePaysFilms_[(*it)->pays];
        filmsDuPays.erase(std::remove(filmsDuPays.begin(), filmsDuPays.end(), it->get()), filmsDuPays.end());
        films_.erase(it);               
        return true;
    }
    return false;
}

//TODO
std::size_t GestionnaireFilms::getNombreFilms() const
{
    return films_.size();
}

//TODO
std::vector<const Film*> GestionnaireFilms::getFilmsParGenre(Film::Genre genre) const
{
    auto it = filtreGenreFilms_.find(genre);
    if(it!=filtreGenreFilms_.end()){
        return it->second;
    }
    return std::vector<const Film*>();
}

//TODO
std::vector<const Film*> GestionnaireFilms::getFilmsParPays(Pays pays) const
{
    auto it = filtrePaysFilms_.find(pays);
    if(it!=filtrePaysFilms_.end())
        return it->second;
    return std::vector<const Film*>();
}

//TODO
std::vector<const Film*> GestionnaireFilms::getFilmsEntreAnnees(int anneeDebut, int anneeFin)
{
    std::vector<const Film*> filmsAnnees;
    std::copy_if(films_.begin(), films_.end(), RawPointerBackInserter(filmsAnnees), EstDansIntervalleDatesFilm(anneeDebut, anneeFin));
    return filmsAnnees;
}