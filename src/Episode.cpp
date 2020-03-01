// To do
#include "Episode.h"

// To do
//Constructeur par defaut
Episode::Episode():nom_(""), duree_(""), numEpisode_(0)
// To do
{
}

// To do
//Constructeur par paramètres
Episode::Episode(unsigned int numEpisode, const std::string& nom, const std::string& duree):
    nom_(nom), duree_(duree), numEpisode_(numEpisode)
// To do
{
}

// To do
bool Episode::operator==(unsigned int numEpisode)
{
    // To do
    if(numEpisode_ == numEpisode){
        return true;
    }
    return false;
}


// To do
std::ostream& operator<<(std::ostream& os, const Episode& episode)
{
    // To do
    os << "\t\tEpisode" << std::setw(2) << std::setfill('0') << episode.numEpisode_ << ":" << episode.nom_
       << "|Duree: " << episode.duree_;  
    //revoir l'affichage
    return os;
}

// To do
std::istream& operator>>(std::istream& is, Episode& episode)
{
    // To do
    is >> episode.numEpisode_ >> std::quoted(episode.nom_) >> std::quoted(episode.duree_);
    return is;
}

// To do
unsigned int Episode::getNumEpisode() const
{
    // To do
    return numEpisode_;
}
