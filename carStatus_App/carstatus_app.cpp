#include "carstatus_app.h"
#include "ui_carstatus_app.h"

carStatus_App::carStatus_App(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::carStatus_App)
{
    ui->setupUi(this);
}

carStatus_App::~carStatus_App()
{
    delete ui;
}

