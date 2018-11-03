#include<QtGui>

#include"Bouton.h"

/********************************************************************************
 * Description      : Constructeur par parametre d'un bouton
 * ParamËtres       : un texte(const QString &text), QWidget *parent
 * Type de retour   : void
 *******************************************************************************/
Bouton::Bouton(const QString &text, QWidget *parent): QToolButton(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setText(text);
}
/********************************************************************************
 * Description      : Retourne la dimension du bouton
 * ParamËtres       : Aucun
 * Type de retour   : QSize
 *******************************************************************************/
QSize Bouton::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 20;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}
