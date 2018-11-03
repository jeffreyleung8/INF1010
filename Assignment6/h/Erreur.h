#ifndef ERREUR_H
#define ERREUR_H
#include <stdexcept>
#include<QException>
#include<QWidget>
#include<QMessageBox>
#include<QPushButton>
#include"Bouton.h"
#include <string>
using namespace std;

/*-----------------------------------------------------------------------*/
//Definition de DivisionZeroException*/

class DivisionZeroException: public logic_error {
public:
    DivisionZeroException(string message="");
    /*="Exception Division par zero impossible"*/
};

/*Implementation de DivisionZeroException*/

DivisionZeroException::DivisionZeroException(string message)
    :logic_error(message)
{}

/*-----------------------------------------------------------------------*/

/*Definition de InverseZeroException*/

class InverseZeroException: public logic_error{
public:
    InverseZeroException(string message="");
    /*Exception Inverse par zero impossible*/

};

/*Implementation de InverseZeroException*/

InverseZeroException::InverseZeroException(string message)
    :logic_error(message)
{}

/*-----------------------------------------------------------------------*/

/*Definition de NegativeRootException*/

class NegativeRootException: public logic_error{
public:
    NegativeRootException(string message="");
    /*Exception racine de zero impossible*/
};

/*Implementation de NegativeRootException*/

NegativeRootException::NegativeRootException(string message)
    :logic_error(message)
{}

/*-----------------------------------------------------------------------*/


#endif // ERREUR_H
