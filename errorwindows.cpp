#include "errorwindows.h"

errorWindows::errorWindows(QWidget *parent) : QWidget(parent)
{

    errorTitle = new QLabel("ERROR!");
    errorTitle->setStyleSheet("font: 35px;"
                              "color: red;");

    errorMessage = new QLabel();


    verticalLayout = new QVBoxLayout();
    verticalLayout->addWidget(errorTitle);
    verticalLayout->addWidget(errorMessage);

    setLayout(verticalLayout);
}

void errorWindows::setErrorLabel(QString error){
    errorMessage->setText(error);
}
