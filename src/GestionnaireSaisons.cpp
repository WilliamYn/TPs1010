// To do
#include "GestionnaireSaisons.h"

// To do
GestionnaireSaisons::~GestionnaireSaisons()
{ // To do
    saisons_.clear();
}

// To do
GestionnaireSaisons& GestionnaireSaisons::operator+=(std::unique_ptr<Saison> saison)
{
    // To do
    int indexSaison = trouverIndexSaison(saison->getNumSaison());
    if (indexSaison != -1) // si la saison existe d�j� dans les saisons_
    {
        *this -= saison->getNumSaison(); // retire la saison
    }
    saisons_.push_back(std::move(saison));
    sort(saisons_.begin(), saisons_.end(), Saison::SortByNumSaison());
}

// To do
GestionnaireSaisons& GestionnaireSaisons::operator-=(const unsigned int numSaison)
{
    // To do
    int indexSaison = trouverIndexSaison(numSaison);
    if (indexSaison != -1)
    {
        saisons_.erase(saisons_.begin() + trouverIndexSaison(numSaison));
    }
    return *this;
}

// To do
void GestionnaireSaisons::ajouterEpisode(const unsigned int numSaison,
                                         std::unique_ptr<Episode> episode)
{   //done
    // To do
    *getSaison(numSaison) += std::move(episode);
}

// To do
void GestionnaireSaisons::retirerEpisode(const unsigned int numSaison,
                                         const unsigned int numEpisode)
{ // done
    // To do
    int indexSaison = trouverIndexSaison(numSaison);
    *saisons_[indexSaison] -= numEpisode;
}

/// To do
size_t GestionnaireSaisons::trouverIndexSaison(const unsigned int numSaison) const
{
    // To do
    // done
    for (int i = 0; i < saisons_.size(); i++)
    {
        if (numSaison == saisons_[i]->getNumSaison())
        {
            return i;
        }
    }
    return -1;
}

// To do
Saison* GestionnaireSaisons::getSaison(const unsigned int numSaison) const
{
    // done
    // todo
    int indexSaison = trouverIndexSaison(numSaison);
    return saisons_[indexSaison].get();
}

// To do
size_t GestionnaireSaisons::getNbSaisons() const
{
    // To do
    return saisons_.size();
}
