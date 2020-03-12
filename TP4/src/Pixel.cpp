#include "Pixel.h"

/**
 * @brief constructeur par défaut de la classe
 */
Pixel::Pixel() : rouge_(0), vert_(0), bleu_(0) {}
/**
 * @brief constructeur par paramètres de la classe
 * @param rouge, l'élément R du pixel, entre 0 -> 255
 * @param vert, l'élément G du pixel, entre 0 -> 255
 * @param bleu, l'élément B du pixel, entre 0 -> 255
 */
Pixel::Pixel(uint8_t rouge, uint8_t vert, uint8_t bleu)
    : rouge_(rouge), vert_(vert), bleu_(bleu) {}

void Pixel::operator=(const Pixel &pixel) {
  // TO DO
    if (this != &pixel)
    {
        this->bleu_ = pixel.bleu_;
        this->rouge_ = pixel.rouge_;
        this->vert_ = pixel.vert_;
    }
}

void Pixel::setRouge(int rouge) {
  // TO DO
    rouge_ = (rouge < 0) ? 0 : rouge;
    rouge_ = (rouge_ > 255) ? 255 : rouge_;
}

void Pixel::setVert(int vert) {
  // TO DO
    vert_ = (vert < 0) ? 0 : vert;
    vert_ = (vert_ > 255) ? 255 : vert_;
}

void Pixel::setBleu(int bleu) {
  // TO DO
    bleu_ = (bleu < 0) ? 0 : bleu;
    bleu_ = (bleu_ > 255) ? 255 : bleu_;
}
/**
 * @brief retourn l'attribut rouge_ du pixel
 * @return rouge_ du type uint8_t
 */
uint8_t Pixel::getRouge() const { return rouge_; }
/**
 * @brief retourn l'attribut vert_ du pixel
 * @return vert_ du type uint8_t
 */
uint8_t Pixel::getVert() const { return vert_; }
/**
 * @brief retourn l'attribut bleu_ du pixel
 * @return bleu_ du type uint8_t
 */
uint8_t Pixel::getBleu() const { return bleu_; }

std::ostream &operator<<(std::ostream &os, Pixel pixel) {
  // TO DO
    
    os << "#" << std::setfill(0)<<std::hex <<std::setw(2) << pixel.getRouge() << " " << pixel.getVert() << " " << pixel.getBleu() << " ";
    return os;
}

std::istream &operator>>(std::istream &is, Pixel &pixel) {
  // TO DO
    //bluuu = pixel.getBleu();
    //ruuug = pixel.setBleu();
    //verrrrr = pixel.getVert();
    uint8_t bleu, rouge, vert;
    is >> rouge, vert, bleu;
    pixel.setRouge(rouge);
    pixel.setVert(vert);
    pixel.setBleu(bleu);
    return is;

}