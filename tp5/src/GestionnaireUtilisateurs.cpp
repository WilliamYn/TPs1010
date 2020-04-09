/// Gestionnaire d'utilisateurs.
/// \author Misha Krieger-Raynauld
/// \date 2020-01-12

#include "GestionnaireUtilisateurs.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

/// Affiche les informations des utilisateurs gérés par le gestionnaire d'utilisateurs à la sortie du stream donné.
/// \param outputStream         Le stream auquel écrire les informations des utilisateurs.
/// \param gestionnaireFilms    Le gestionnaire d'utilisateurs à afficher au stream.
/// \return                     Une référence au stream.
std::ostream& operator<<(std::ostream& outputStream, const GestionnaireUtilisateurs& gestionnaireUtilisateurs)
{
    // TODO: Uncomment une fois que la fonction getNombreUtilisateurs est écrite
    outputStream << "Le gestionnaire d'utilisateurs contient " << gestionnaireUtilisateurs.getNombreUtilisateurs()
                 << " utilisateurs:\n";

    // TODO: Réécrire l'implémentation avec des range-based for et structured bindings (voir énoncé du TP)
    for (const auto& [id, utilisateur] : gestionnaireUtilisateurs.utilisateurs_) {
        outputStream<< id << '\t' << utilisateur << '\n';       //vérifier l'affichage
    }
    return outputStream;

    //Boucle au départ:
    /*
    for (auto it = gestionnaireUtilisateurs.utilisateurs_.cbegin();
         it != gestionnaireUtilisateurs.utilisateurs_.cend();
         ++it)
    {
        outputStream << '\t' << it->second << '\n';
    }
    return outputStream;
    */
}

/// Ajoute les utilisateurs à partir d'un fichier de données d'utilisateurs.
/// \param nomFichier   Le fichier à partir duquel lire les informations des utilisateurs.
/// \return             True si tout le chargement s'est effectué avec succès, false sinon.
bool GestionnaireUtilisateurs::chargerDepuisFichier(const std::string& nomFichier)
{
    std::ifstream fichier(nomFichier);
    if (fichier)
    {
        utilisateurs_.clear();

        bool succesParsing = true;

        std::string ligne;
        while (std::getline(fichier, ligne))
        {
            std::istringstream stream(ligne);

            std::string id;
            std::string nom;
            int age;
            int pays;

            if (stream >> id >> std::quoted(nom) >> age >> pays)
            {
                // TODO: Uncomment une fois que la fonction ajouterUtilisateur est écrite
                ajouterUtilisateur(Utilisateur{id, nom, age, static_cast<Pays>(pays)});
            }
            else
            {
                std::cerr << "Erreur GestionnaireUtilisateurs: la ligne " << ligne
                          << " n'a pas pu être interprétée correctement\n";
                succesParsing = false;
            }
        }
        return succesParsing;
    }
    std::cerr << "Erreur GestionnaireUtilisateurs: le fichier " << nomFichier << " n'a pas pu être ouvert\n";
    return false;
}

//TODO
bool GestionnaireUtilisateurs::ajouterUtilisateur(const Utilisateur& utilisateur)
//"prénom.nom.1@email.com", "Prénom Nom", 20, Pays::Canada
{
    return utilisateurs_.std::unordered_map<std::string, Utilisateur>::emplace(utilisateur.id, utilisateur).second;
}

//TODO
bool GestionnaireUtilisateurs::supprimerUtilisateur(const std::string& idUtilisateur)
{
	return  utilisateurs_.unordered_map<std::string, Utilisateur>::erase(idUtilisateur);
}

//TODO
std::size_t GestionnaireUtilisateurs::getNombreUtilisateurs() const
{
    return utilisateurs_.size();
}

//TODO
const Utilisateur* GestionnaireUtilisateurs::getUtilisateurParId(const std::string& id) const
{
	auto it = utilisateurs_.find(id);
    if(it!=utilisateurs_.end())
       return &(it->second);
    return nullptr;
}