// To do
#include "Saison.h"

// To do
// Constructeur par défaut
Saison::Saison()
    : numSaison_(0)
    , nbEpisodesmax_(0) // maybe not 0. maybe vector
                        // To do
{
}

// To do
// Constructeur par paramètres
Saison::Saison(unsigned int numSaison, unsigned int nbEpisodemax)
    : numSaison_(numSaison)
    , nbEpisodesmax_(nbEpisodemax)
// To do
{
}

// To do
// Constructeur par copie
Saison::Saison(const Saison& saison)
{
    // To do
    for (int i = 0; i < saison.getNbEpisodes(); i++)
    {
        Episode episode = *saison.episodes_[i];
        episodes_.push_back(std::make_unique<Episode>(episode));
    }
}

// To do
Saison::~Saison()
{
    // To do
    episodes_.clear();
}

// To do
// L'opérateur ajoute un épisode aux épisodes de la saison
Saison& Saison::operator+=(std::unique_ptr<Episode> episode)
{
    // To do
    int indexEpisode = trouverIndexEpisode(episode->getNumEpisode());
    if (indexEpisode != -1)
    {
        *this -= episode->getNumEpisode();
    }
    episodes_.push_back(std::make_unique<Episode>(*episode));
    sort(episodes_.begin(), episodes_.end(), Episode::SortByNumEpisode()); 
    return *this;
}

// To do
Saison& Saison::operator-=(unsigned int numEpisode)
{
    // To do
    if (trouverIndexEpisode(numEpisode) != -1)
    {
        episodes_.erase(episodes_.begin() + trouverIndexEpisode(numEpisode));
    }
    return *this;
}

// To do
bool Saison::operator==(unsigned int numSaison)
{
    // To do
    if (numSaison == this->numSaison_)
    {
        return true;
    }
    return false;
}

// To do
std::ostream& operator<<(std::ostream& os, const Saison& saison)
{
    // To do
    os << "Saison " << saison.numSaison_ << ": " << saison.episodes_.size() << "/"
       << saison.nbEpisodesmax_; // TERMINER, EN COURS
                                 // ???????????????????????????????????????????????????????
    for (int i = 0; i < saison.episodes_.size(); i++)
    {
        os << saison.episodes_[i];
    }
    return os;
}
// To do
std::istream& operator>>(std::istream& is, Saison& saison)
{
    // To do
    is >> saison.numSaison_ >> saison.nbEpisodesmax_;
    return is;
    //Question: Est-ce qu'il faut initialiser le nom de la saison aussi? Et les épisodes?
}

// To do
unsigned int Saison::getNumSaison() const
{
    // To do
    return numSaison_;
}

// To do
size_t Saison::getNbEpisodes() const
{
    // To do
    return episodes_.size();
}

// To do
size_t Saison::trouverIndexEpisode(unsigned int numEpisode)
{
    // To do
    for (int i = 0; i < episodes_.size(); i++)
    {
        if (episodes_[i]->getNumEpisode() == numEpisode)
        {
            return i;
        }
    }
    return EPISODE_INEXSISTANTE;
}