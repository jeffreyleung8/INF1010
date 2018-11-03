#ifndef BOUTON_H
#define BOUTON_H

#include<QToolButton>


class Bouton : public QToolButton
{
    //Indique qu'un objet de type bouton est widget(gui element)
    Q_OBJECT
public:
    //Constructeur par parametre
    Bouton(const QString &text, QWidget *parent = 0);
    
    //Methode
    QSize sizeHint() const;
};

#endif // BOUTON_H
