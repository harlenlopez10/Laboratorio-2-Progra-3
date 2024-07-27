#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class cframe;
}
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();

private slots:
    void on_spinBox_valueChanged(int arg1);


    void on_btnEjercicio1_clicked();

    void on_btnEjercicio2_clicked();

    void on_btnEjercicio3_clicked();

    void on_RETURNMENU_clicked();

    void on_RETURNMENU_3_clicked();

    void on_RETURNMENU_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_BTNtoBinario_clicked();

    void on_BTNtoDecimal_clicked();

    void on_BTNtoHexa_clicked();

    void on_BTNBinarioLT_clicked();

    void on_BTNDecimalLt_clicked();

    void on_BTNHexaLt_clicked();

private:
    Ui::cframe *ui;
};
#endif // CFRAME_H
