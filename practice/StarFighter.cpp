/** 
 * @file StarFighter.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "StarFighter.h"

int StarFighter::_numStarFighters = 0;

StarFighter::StarFighter() : _marca(""), _modelo(""), _numPlazas(1), nPiezas(0) {
    _numStarFighters++;
    _idSF = _numStarFighters;
}

StarFighter::StarFighter(string marca, string modelo, int numPlazas) :
        _marca(marca), _modelo(modelo), _numPlazas(numPlazas), nPiezas(0) {
    if (numPlazas <= 0) {
        throw std::invalid_argument("StarFighter::StarFighter: el número de"
                                            " plazas no puede ser negativo");
    }

    _numStarFighters++;
    _idSF = _numStarFighters;
}

StarFighter::StarFighter(const StarFighter &orig) : _marca(orig._marca),
                                                    _modelo(orig._modelo),
                                                    _numPlazas(orig._numPlazas) {
    _numStarFighters++;
    _idSF = _numStarFighters;
}



/**
 * @todo Aquí hay que añadir la comprobación del parámetro y lanzar la excepción
 *       correspondiente. El número de plazas no puede ser <= 0
 */
void StarFighter::setNumPlazas(int numPlazas) {
    this->_numPlazas = numPlazas;
}
int StarFighter::getNumPlazas() const {
    return _numPlazas;
}

void StarFighter::setModelo(string modelo) {
    this->_modelo = modelo;
}
string StarFighter::getModelo() const {
    return _modelo;
}

void StarFighter::setMarca(string marca) {
    this->_marca = marca;
}
string StarFighter::getMarca() const {
    return _marca;
}

int StarFighter::getIdSF() const {
    return _idSF;
}


string StarFighter::toCSV() {
    std::stringstream aux;

    aux << _marca << " ; "
        << _modelo << " ; "
        << _numPlazas;

    return (aux.str());
}

StarFighter &StarFighter::operator=(const StarFighter &otro) {
    if (this != &otro) {
        _marca = otro._marca;
        _modelo = otro._modelo;
        _numPlazas = otro._numPlazas;
    }

    return (*this);
}

void StarFighter::fromCSV(string &datos) {
    std::stringstream aux;

    aux << datos;

    getline(aux, _marca, ';');
    getline(aux, _modelo, ';');
    aux >> _numPlazas;
}

void StarFighter::addPieza(Pieza &pieza) {

    this->piezas[this->nPiezas] = pieza;
}



StarFighter::~StarFighter() {
}