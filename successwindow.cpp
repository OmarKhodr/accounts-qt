#include "successwindow.h"

successWindow::successWindow(QWidget *parent) : QWidget(parent)
{

    sucessLabel = new QLabel("SUCCESS!");
    sucessLabel->setStyleSheet("font: 35px;"
                               "color: green;");
    successMessage = new QLabel();

    verticalLayout = new QVBoxLayout();
    verticalLayout->addWidget(sucessLabel);
    verticalLayout->addWidget(successMessage);

    setLayout(verticalLayout);

}

void successWindow::setSuccessLabel(QString str){
    successMessage->setText(str);
}
