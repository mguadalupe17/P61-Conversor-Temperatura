#include "conversor.h"
#include "ui_conversor.h"

Conversor::Conversor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Conversor)
{
    ui->setupUi(this);
    // Conectar el dial de Centigrados con el slot de ESTA clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2all(int)));
    connect(ui->inFahr, SIGNAL(valueChanged(int)),
            this, SLOT (fahr2all(int)));
    connect(ui->inKel, SIGNAL(valueChanged(int)),
            this, SLOT(kel2all(int)));
}

Conversor::~Conversor()
{
    delete ui;
}

void Conversor::cent2all(int grados)
{
    if (ui->inCent->hasFocus()){
        int f = (grados * 9.0/5) + 32;
        ui->inFahr->setValue(f);
        int k = (grados + 273.15);
        ui->inKel->setValue(k);
    }

}

void Conversor::fahr2all(int grados)
{
    if (ui->inFahr->hasFocus()){
        int c = (grados - 32) * 5.0/9;
        ui->inCent->setValue(c);
        int k = (grados - 32)*(5.0/9)+273.15;
        ui->inKel->setValue(k);
    }
}
void Conversor:: kel2all(int grados)
{
    if (ui->inKel->hasFocus()){
        int c = (grados-273.15);
        ui->inCent->setValue(c);
        int f = (grados - 273.15)*(9.0/5)+32;
        ui->inFahr->setValue(f);
    }
}
