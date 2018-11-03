#include<QtGui>

#include<math.h>
#include <QLineEdit>
#include"Bouton.h"
#include"Calculatrice.h"
#include"Erreur.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>


Calculatrice::Calculatrice(QWidget *parent): QWidget(parent)
{

    sumInMemory = 0.0;
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    waitingForOperand = true;
	//creation d'un objet de type QLineEdit avec par défaut la chaine de caractère 0
	//cette objet représente une zone de texte qui sera utilisé comme afficheur de la calculatrice
    display = new QLineEdit("0");
	
	// la zone de texte est paramétrée en lecture seule
    display->setReadOnly(true);
	
	// l'affichage se fera de la droite vers la gauche
    display->setAlignment(Qt::AlignRight);
	
	// définition de la largeur de la zone de texte à 15
    display->setMaxLength(15);

    //Creation objet pour le style de lecriture
    QFont font = display->font();

    //Definition de la taille de lecriture
    font.setPointSize(font.pointSize() + 8);

    //Definition du style decriture de la zone de texte
    display->setFont(font);

    //Creation des boutons des chiffres 1 a 9 gere par la methode digitClicked()
    for(int i=0; i<NumDigitButtons; ++i)
    {
        digitButtons[i] = createButton(QString::number(i), SLOT(digitClicked()));
    }

    //Creation du bouton "." gere par la methode pointCliked()
    Bouton *pointButton = createButton(tr("."), SLOT(pointClicked()));
    
    //Creation du bouton "+/-" gere par la methode changeSignCliked()
    Bouton *changeSignButton = createButton(tr("+/-"), SLOT(changeSignClicked()));
    
    //Creation du bouton "Backspace" gere par la methode backspaceClicked()
    Bouton *backspaceButton = createButton(tr("Backspace"), SLOT(backspaceClicked()));
    
    //Creation du bouton "Clear" gere par la methode clear()
    Bouton *clearButton = createButton(tr("Clear"), SLOT(clear()));
    
    //Creation du bouton "Clear All" gere par la methode clearAll()
    Bouton *clearAllButton = createButton(tr("Clear All"), SLOT(clearAll()));
	
    //Creation du bouton "MC" gere par la methode clearMemory()
    Bouton *clearMemoryButton = createButton(tr("MC"), SLOT(clearMemory()));
    
    //Creation du bouton "MR" gere par la methode readMemory()
    Bouton *readMemoryButton = createButton(tr("MR"), SLOT(readMemory()));

    //Creation du bouton "MS" gere par la methode setMemory()
    Bouton *setMemoryButton = createButton(tr("MS"), SLOT(setMemory()));

    //Creation du bouton "M+" gere par la methode addToMemory()
    Bouton *addToMemoryButton = createButton(tr("M+"), SLOT(addToMemory()));

    //Creation du bouton "/" gere par la methode multiplicativeOperatorClicked()
    Bouton *divisionButton = createButton(tr("/"), SLOT(multiplicativeOperatorClicked()));

    //Creation du bouton "*" gere par la methode multiplicativeOperatorClicked()
    Bouton *timesButton = createButton(tr("*"), SLOT(multiplicativeOperatorClicked()));

    //Creation du bouton "-" gere par la methode additiveOperatorClicked()
    Bouton *minusButton = createButton(tr("-"), SLOT(additiveOperatorClicked()));

    //Creation du bouton "+" gere par la methode additiveOperatorClicked()
    Bouton *plusButton = createButton(tr("+"), SLOT(additiveOperatorClicked()));

    //Creation du bouton "Sqrt" gere par la methode unaryOperatorClicked()
    Bouton *squareRootButton = createButton(tr("Sqrt"), SLOT(unaryOperatorClicked()));

    //Creation du bouton "x^2" gere par la methode unaryOperatorClicked()
    Bouton *powerButton = createButton(tr("x^2"), SLOT(unaryOperatorClicked()));

    //Creation du bouton "1/x" gere par la methode unaryOperatorClicked()
    Bouton *reciprocalButton = createButton(tr("1/x"), SLOT(unaryOperatorClicked()));

    //Creation du bouton "=" gere par la methode equalClicked()
    Bouton *equalButton = createButton(tr("="), SLOT(equalClicked()));

    //Construction de la calculatrice ligne par ligne en ajoutant les elements appropries
    
    //Declaration et allocation de memoire du pointeur line1 de type QHBoxLayout(pour layout horizontal)
    //Ajout des boutons(widgets) avec la methode addWidget(Bouton *button)
    //Meme procedure pour line2, line3, line4, line5
    QHBoxLayout* line1 = new QHBoxLayout;
    line1->addWidget(backspaceButton);
    line1->addWidget(clearButton);
    line1->addWidget(clearAllButton);

    QHBoxLayout* line2 = new QHBoxLayout;
    line2->addWidget(clearMemoryButton);
    line2->addWidget(digitButtons[7]);
    line2->addWidget(digitButtons[8]);
    line2->addWidget(digitButtons[9]);
    line2->addWidget(divisionButton);
    line2->addWidget(squareRootButton);

    QHBoxLayout* line3 = new QHBoxLayout;
    line3->addWidget(readMemoryButton);
    line3->addWidget(digitButtons[4]);
    line3->addWidget(digitButtons[5]);
    line3->addWidget(digitButtons[6]);
    line3->addWidget(timesButton);
    line3->addWidget(powerButton);

    QHBoxLayout* line4 = new QHBoxLayout;
    line4->addWidget(setMemoryButton);
    line4->addWidget(digitButtons[1]);
    line4->addWidget(digitButtons[2]);
    line4->addWidget(digitButtons[3]);
    line4->addWidget(minusButton);
    line4->addWidget(reciprocalButton);

    QHBoxLayout* line5 = new QHBoxLayout;
    line5->addWidget(addToMemoryButton);
    line5->addWidget(digitButtons[0]);
    line5->addWidget(pointButton);
    line5->addWidget(changeSignButton);
    line5->addWidget(plusButton);
    line5->addWidget(equalButton);

    //Tous les lignes de la calcultrice crees
    //Combine les 5 lignes dans un layout vertical
    //Declaration du pointeur mainLayout de type QVBoxLayout(pour layout vertical)
    //Utiliser addWidget pour des widgets et addLayout pour des layouts
    //Les 5 lignes sont des layouts et la zone de texte est un widget

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(display);
    mainLayout->addLayout(line1);
    mainLayout->addLayout(line2);
    mainLayout->addLayout(line3);
    mainLayout->addLayout(line4);
    mainLayout->addLayout(line5);

    // Ajout du layout à la fenetre principale
    setLayout(mainLayout);
    
    // Ajout du titre de la  fenetre
    setWindowTitle(tr("Calculatrice"));
}

/********************************************************************************
 * Description      : Affiche le chiffre appuye sur la zone de texte
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::digitClicked()
{
    Bouton *clickedButton = qobject_cast<Bouton* >(sender());
    int digitValue = clickedButton->text().toInt();
    if(display->text() =="0" && digitValue == 0.0)
        return;

    if(waitingForOperand)
    {
        display->clear();
        waitingForOperand = false;
    }
    display->setText(display->text() + QString::number(digitValue));

}

/********************************************************************************
 * Description      : Effectue les operations unaires(racine carre, puissance de 2, inverse) si 
                      l'operation n'est pas une exception et affiche sur le resultat. En cas
                      d'une exception, un fenetre apparaitra. Utilise le trio (try, throw, catch
                      pour la racine carre et l'inverse.
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::unaryOperatorClicked()
{
    Bouton* clickedButton = qobject_cast<Bouton*>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();
    double result = 0.0;

    try{
       if(clickedOperator == tr("Sqrt"))
         {
            if(operand < 0.0)
            {
                abortOperation();
                throw(NegativeRootException("Exception racine de negatif impossible"));
            }
        result = sqrt(operand);
        }
    }
    catch (NegativeRootException& e){
         QMessageBox messageBox;
         messageBox.critical(0, "Erreur", e.what());
         return;
    }

   if(clickedOperator == tr("x^2")){
            result = pow(operand, 2.0);
         }
    try{
         if(clickedOperator == tr("1/x")){
            if(operand == 0.0){
                abortOperation();
                 throw InverseZeroException("Exception Inverse par zero impossible");
            }
          result = 1.0 / operand;
        }
    }
    catch(InverseZeroException& e) {
        QMessageBox messageBox;
        messageBox.critical(0, "Erreur", e.what());
        return;
    }

    display->setText(QString::number(result));
    waitingForOperand = true;
}

/********************************************************************************
 * Description      : Associe le pending operator a l'addition(+) et affecte
                      waitingForOperator a vrai.
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::additiveOperatorClicked()
{
    Bouton* clickedButton = qobject_cast<Bouton*>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    sumSoFar = operand;

    pendingAdditiveOperator = clickedOperator;

    waitingForOperand = true;
}

/********************************************************************************
 * Description      : Associe le pending operator a la multiplication et affecte 
                      waitingForOperator a vrai.
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice:: multiplicativeOperatorClicked()
{
    Bouton* clickedButton = qobject_cast<Bouton*>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = display->text().toDouble();

    factorSoFar = operand;

    pendingMultiplicativeOperator = clickedOperator;

    waitingForOperand = true;
}

/********************************************************************************
 * Description      : Affiche le resultat de l'operation
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::equalClicked()
{
    double operand = display->text().toDouble();

    if(!pendingMultiplicativeOperator.isEmpty())
    {
        if(!calculate(operand, pendingMultiplicativeOperator))
        {
            abortOperation();
            
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if(!pendingAdditiveOperator.isEmpty())
    {
        if(!calculate(operand, pendingAdditiveOperator))
        {
            abortOperation();
        }
        pendingAdditiveOperator.clear();
    }
    else
    {
        sumSoFar = operand;
    }

    display->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    waitingForOperand = true;
}
/********************************************************************************
 * Description      : Affiche un point sur la zone de texte
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::pointClicked()
{
    if(waitingForOperand)
    {
        display->setText("0");
    }
    if(!display->text().contains("."))
    {
        display->setText(display->text() + tr("."));
    }
    waitingForOperand = false;
}
/********************************************************************************
 * Description      : Change le signe du chiffre sur la zone de texte
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::changeSignClicked()
{
    QString text = display->text();
    double value = text.toDouble();

    if(value > 0.0)
    {
        text.prepend(tr("-"));
    }
    else if(value < 0.0)
    {
        text.remove(0, 1);
    }
    display->setText(text);
}
/********************************************************************************
 * Description      : Efface le dernier chiffre appuye sur la zone de texte
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::backspaceClicked()
{
    if(waitingForOperand)
        return;

    QString text = display->text();
    text.chop(1);
    if(text.isEmpty())
    {
        text = "0";
        waitingForOperand = true;
    }
    display->setText(text);
}

void Calculatrice::clear()
{
    if(waitingForOperand)
        return;

    display->setText("0");
    waitingForOperand = true;
}

/********************************************************************************
 * Description      : Reinitialise toutes les valeurs et toutes les operations
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/ 
void Calculatrice::clearAll()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    display->setText("0");
    waitingForOperand = true;

}
/********************************************************************************
 * Description      : Reinitialise la memoire
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::clearMemory()
{
    sumInMemory = 0.0;
}

/********************************************************************************
 * Description      : Affiche la memoire sur la zone de texte
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::readMemory()
{
    display->setText(QString::number(sumInMemory));
    waitingForOperand = true;
}

/********************************************************************************
 * Description      : Sauvegarde la valeur dans la memoire
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::setMemory()
{
    equalClicked();
    sumInMemory = display->text().toDouble();
}
/********************************************************************************
 * Description      : Ajoute la valeur a la memoire
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::addToMemory()
{
    equalClicked();
    sumInMemory += display->text().toDouble();
}

/********************************************************************************
 * Description      : Cree un bouton
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
Bouton *Calculatrice::createButton(const QString &text, const char *member)
{
    Bouton *button = new Bouton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}
/********************************************************************************
 * Description      : Methode qui reinitialise toutes les valeurs et les operations
 * Paramètres       : Aucun
 * Type de retour   : void
 *******************************************************************************/
void Calculatrice::abortOperation()
{
    clearAll();
    return;
}

/********************************************************************************
 * Description      : Effectue les operations +,-,*,/ .Si le trio (try, throw, catch) detecte
                      une exception dans la division(division par 0), une fenetre erreur 
                      apparaitra.
 * Paramètres       : Aucun
 * Type de retour   : bool retourne vrai si le calcul est reussi sinon retourne faux
 *******************************************************************************/
bool Calculatrice::calculate(double rightOperand, const QString &pendingOperator)
{
    if(pendingOperator == tr("+"))
    {
        sumSoFar +=rightOperand;
    }
    else if(pendingOperator == tr("-"))
    {
        sumSoFar -= rightOperand;
    }
    else if(pendingOperator == tr("*"))
    {
        factorSoFar *= rightOperand;
    }
    else if(pendingOperator == tr("/"))
    {

    try
       {
          if (rightOperand == 0.0)
          {
              abortOperation();
              throw (DivisionZeroException("Exception Division par zero impossible"));
          }
            factorSoFar /= rightOperand;
        }
    catch(std::exception const& e){
           QMessageBox::critical(this, "Error", e.what());
        }
    }
    return true;

}



