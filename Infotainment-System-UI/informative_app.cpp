#include "informative_app.h"
#include "./ui_informative_app.h"

Informative_APP::Informative_APP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Informative_APP)
{
    ui->setupUi(this);
}

Informative_APP::~Informative_APP()
{
    delete ui;
}
