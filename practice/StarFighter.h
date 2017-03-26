/** 
 * @file StarFighter.h
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#ifndef STARFIGHTER_H
#define STARFIGHTER_H

#include <string>
#include "Pieza.h"

using std::string;

/**
 * @brief
 */
class StarFighter {

private:

    static int _numStarFighters;
    int _idSF;
    string _marca;
    string _modelo;
    int _numPlazas;

    int nPiezas;
    Pieza piezas[50];


public:

    StarFighter();
    StarFighter(string marca, string modelo, int numPlazas = 1);
    StarFighter(const StarFighter &orig);


    void setNumPlazas(int numPlazas);
    int getNumPlazas() const;

    void setModelo(string modelo);
    string getModelo() const;

    void setMarca(string marca);
    string getMarca() const;

    int getIdSF() const;


    string toCSV();

    StarFighter &operator=(const StarFighter &otro);

    void fromCSV(string &datos);

    void addPieza (Pieza &pieza);

    virtual ~StarFighter();
};

#endif /* STARFIGHTER_H */

