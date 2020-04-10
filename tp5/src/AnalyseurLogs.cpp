/// Analyseur de statistiques grâce aux logs.
/// \author Misha Krieger-Raynauld
/// \date 2020-01-12

#include "AnalyseurLogs.h"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include "Foncteurs.h"

/// Ajoute les lignes de log en ordre chronologique à partir d'un fichier de logs.
/// \param nomFichier               Le fichier à partir duquel lire les logs.
/// \param gestionnaireUtilisateurs Référence au gestionnaire des utilisateurs pour lier un utilisateur à un log.
/// \param gestionnaireFilms        Référence au gestionnaire des films pour pour lier un film à un log.
/// \return                         True si tout le chargement s'est effectué avec succès, false sinon.
bool AnalyseurLogs::chargerDepuisFichier(const std::string& nomFichier,
                                         GestionnaireUtilisateurs& gestionnaireUtilisateurs,
                                         GestionnaireFilms& gestionnaireFilms)
{
    std::ifstream fichier(nomFichier);
    if (fichier)
    {
        logs_.clear();
        vuesFilms_.clear();

        bool succesParsing = true;

        std::string ligne;
        while (std::getline(fichier, ligne))
        {
            std::istringstream stream(ligne);

            std::string timestamp;
            std::string idUtilisateur;
            std::string nomFilm;

            if (stream >> timestamp >> idUtilisateur >> std::quoted(nomFilm))
            {
                // TODO: Uncomment une fois que la fonction creerLigneLog est écrite
                // creerLigneLog(timestamp, idUtilisateur, nomFilm, gestionnaireUtilisateurs, gestionnaireFilms);
            }
            else
            {
                std::cerr << "Erreur AnalyseurLogs: la ligne " << ligne
                          << " n'a pas pu être interprétée correctement\n";
                succesParsing = false;
            }
        }
        return succesParsing;
    }
    std::cerr << "Erreur AnalyseurLogs: le fichier " << nomFichier << " n'a pas pu être ouvert\n";
    return false;
}

//TODO
bool AnalyseurLogs::creerLigneLog(const std::string& timestamp, const std::string& idUtilisateur, const std::string& nomFilm,
                       GestionnaireUtilisateurs& gestionnaireUtilisateurs, GestionnaireFilms& gestionnaireFilms)
{
    //Nombre de lignes???
    LigneLog lignelog = {timestamp, gestionnaireUtilisateurs.getUtilisateurParId(idUtilisateur), gestionnaireFilms.getFilmParNom(nomFilm)};
    if(lignelog.film != nullptr && lignelog.utilisateur != nullptr)
    {
        ajouterLigneLog(lignelog);
        return true;
    }
    return false;
}

//TODO
void AnalyseurLogs::ajouterLigneLog(const LigneLog& ligneLog)
{

}

//TODO
int AnalyseurLogs::getNombreVuesFilm(const Film* film) const
{
    //Nombre de lignes 4???
    return vuesFilms_.at(film);
    //Une autre méthode serait: return vuesFilms_.find(film)->second; mais c'est plus lent,
    //parce qu'il faut itérer à travers le unordered_map pour trouver un itérateur
}

// const Film* AnalyseurLogs::getFilmPlusPopulaire() const
// {

// }