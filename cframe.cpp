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

    QString letra = ui->valorIngresado->text();

    if (letra.isEmpty()) {
        ui->rtConversion->setText("Esta vacio");
        return;
    }

    QChar letras[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int valor = 97;
    int numero = 0;

    for (int i = 0; i < 26; i++) {
        if (letras[i] == letra.at(0)) {
            numero = valor;
            break; //Solo para acordarme que aqui es para que termine el ciclo
        }
        valor++;
    }

    QString Binario;
    int Bits = 7;
    int mascaraBits = 1 << (Bits - 1);
    bool ceros = true;

    for (int i = Bits - 1; i >= 0; --i) {
        if ((numero & mascaraBits) != 0) {
            ceros = false;
        }
        if (!ceros) {
            Binario += ((numero & mascaraBits) ? '1' : '0');
        }
        mascaraBits >>= 1;
    }

    ui->rtConversion->setText(Binario);

}


void cframe::on_BTNtoDecimal_clicked()
{
    QString letra2 = ui->valorIngresado->text();

    if (letra2.isEmpty()) {
        ui->rtConversion->setText("Esta vacio");
        return;
    }

    QChar letras[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int valor = 97;
    int numero = 0;

    for (int i = 0; i < 26; i++) {
        if (letras[i] == letra2.at(0)) {
            numero = valor;
            break; //Solo para acordarme que aqui es para que termine el ciclo
        }
        valor++;
    }

    ui->rtConversion->setText(QString::number(valor));
}


void cframe::on_BTNtoHexa_clicked()
{

    QString letra3 = ui->valorIngresado->text();

    QChar letras[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int valor = 97;
    int numero = 0;

    for (int i = 0; i < 26; i++) {
        if (letras[i] == letra3.at(0)) {
            numero = valor;
            break; //Solo para acordarme que aqui es para que termine el ciclo
        }
        valor++;
    }


    QChar DigitosHexa[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    QString Hexadecimal;

    while (valor > 0) {
        int residuo = valor % 16; // Obtengo el residuo al dividir con 16
        Hexadecimal = DigitosHexa[residuo] + Hexadecimal; // Convierto a carácter hexadecimal
        valor /= 16; // Reducir el número dividiendo por 16
    }

    ui->rtConversion->setText(Hexadecimal);
}


void cframe::on_BTNBinarioLT_clicked()
{


    QString entrada = ui->valorIngresado->text();

    if (entrada.isEmpty() || entrada.length() != 8) {
        ui->rtConversion->setText("Ingrese un número binario de 8 bits.");

    }

    std::string binario = entrada.toStdString();
    int decimal = 0;

    for (QChar bit : binario) {
        decimal = (decimal << 1) | (bit == '1' ? 1 : 0);
    }

    QChar letra = static_cast<QChar>(decimal);

    ui->rtConversion->setText(QString("Letra: %1").arg(QString(letra)));
}


void cframe::on_BTNDecimalLt_clicked()
{

    QString valorEntrada = ui->valorIngresado->text();
    bool verificar;
    int decimal = valorEntrada.toInt(&verificar);

    if(!verificar || decimal < 0 || decimal > 255){
        ui->rtConversion->setText("Número decimal no válido. Ingrese un valor entre 0 y 255.");
    } else {
        char letra = static_cast<char>(decimal);
        ui->rtConversion->setText(QString("Letra: %1").arg(QString(letra)));
    }

}


void cframe::on_BTNHexaLt_clicked()
{
    QString entrada = ui->valorIngresado->text();
    bool verificar;
    int decimal = entrada.toInt(&verificar, 16);

    if (!verificar || decimal < 0 || decimal > 255) {
        ui->rtConversion->setText("Número hexadecimal no válido. Ingrese un valor correcto.");
    } else {
        char letra = static_cast<char>(decimal);
        ui->rtConversion->setText(QString("Letra: %1").arg(QString(letra)));
    }
}

