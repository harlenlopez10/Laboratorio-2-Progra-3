#include "cframe.h"
#include "ui_cframe.h"

#include <QCoreApplication>
#include <QApplication>



cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);
}

cframe::~cframe()
{
    delete ui;
}

void cframe::on_spinBox_valueChanged(int arg1)
{
    int altura = ui->spinBox->value();

    QString piramide;
    int anchura = 2 * altura - 1;

    for (int i = 1; i <= altura; ++i) {
        int numeroAsteriscos = 2 * i - 1;

        int numeroEspacios = (anchura - numeroAsteriscos) / 2;

        piramide += QString(numeroEspacios, ' ');
        piramide += QString(numeroAsteriscos, '*');
        piramide += '\n';
    }

    ui->PanelPiramide->setText(piramide);

}


void cframe::on_btnEjercicio1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void cframe::on_btnEjercicio2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void cframe::on_btnEjercicio3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void cframe::on_RETURNMENU_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void cframe::on_RETURNMENU_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void cframe::on_RETURNMENU_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void cframe::on_pushButton_clicked()
{
    QCoreApplication::quit();
}


void cframe::on_pushButton_2_clicked()
{
    int suma = 0;
    bool control = false;
    bool validez = false;
    QString numeros = ui->NumberCard->text();
    int tamaño = numeros.length();


    for (int i = tamaño - 1; i >= 0; --i) {
        int digito = numeros[i].digitValue();

        if (control) {
            digito *= 2;
            if (digito > 9) {
                digito = (digito / 10) + (digito % 10);
            }
        }

        suma += digito;
        control = !control;
    }


    if (suma % 10 == 0) {
        validez = true;
        ui->LineValidez->setText("Su Tarjeta es Valida");
    } else {
        validez = false;
        ui->LineValidez->setText("Su Tarjeta NO es Valida");
    }

}



void cframe::on_BTNtoBinario_clicked()
{


    QChar a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    a = '97';
    b = "98";
    c="99";
    d = "100";
    e="101";
    f="102";
    g="103";
    h="104";
    i="105";
    j="106";
    k="107";
    l="108";
    m="109";
    n="110";
    o="111";
    p="112";
    q="113";
    r="114";
    s="115";
    t="116";
    u="117";
    v="118";
    w="119";
    x="120";
    y="121";
    z="122";


    QString binaryString;
    // Número máximo de bits necesario para representar números hasta 122
    const int numBits = 7;

    // Crear una máscara para el bit más significativo
    unsigned int mask = 1 << (numBits - 1);

    // Encontrar el primer bit significativo
    bool leadingZero = true;
    for (int i = numBits - 1; i >= 0; --i) {
        if ((number & mask) != 0) {
            leadingZero = false; // Hemos encontrado un bit significativo
        }
        if (!leadingZero) {
            binaryString += ((number & mask) ? '1' : '0');
        }
        mask >>= 1; // Desplazar la máscara un bit a la derecha
    }

    // En caso de que todos los bits sean cero
    if (binaryString.empty()) {
        binaryString = "0";
    }

    return binaryString;
}

