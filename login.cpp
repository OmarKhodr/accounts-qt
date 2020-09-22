#include "login.h"
#include<QSizePolicy>

login::login(QWidget *parent) : QWidget(parent)
{
    logIn = new QLabel("Log In");
    logIn->setStyleSheet("font: 80px;");
    logIn->setAlignment(Qt::AlignCenter);

    username = new QLabel("Username");
    username->setStyleSheet("font: 40px;");
    username->setMargin(0);
    password = new QLabel("Password");
    password->setStyleSheet("font: 40px;");
    password->setMargin(0);

    usernameEdit = new QLineEdit();
    usernameEdit->setStyleSheet("font: 40px;");


    passEdit = new QLineEdit();
    passEdit->setEchoMode(QLineEdit::Password);   // this will hide when inputing the password
    passEdit->setStyleSheet("font: 40px;");


    signUpButton = new QPushButton("Sign Up");
    signUpButton->setStyleSheet("height: 40px;"
                                "font: 30px;");
    playAsGuestButton = new QPushButton("Play as Guest");
    playAsGuestButton->setStyleSheet("height: 40px;"
                                     "font: 30px;");

    // Grid Layout
    gridLayout = new QGridLayout();

    gridLayout->addWidget(logIn, 0,0);
    gridLayout->addWidget(username, 1, 0);
    gridLayout->addWidget(usernameEdit, 2, 0);
    gridLayout->addWidget(password, 3,0);
    gridLayout->addWidget(passEdit, 4, 0);

    // Vertical Layout
    verticalLayout = new QVBoxLayout();
    verticalLayout->addItem(gridLayout);
    verticalLayout->addItem(new QSpacerItem(50,50));
    verticalLayout->addWidget(signUpButton);
    verticalLayout->addWidget(playAsGuestButton);

    verticalLayout->setSpacing(20); // spacing between vertical entries in box
    verticalLayout->setMargin(40);

    setLayout(verticalLayout);
}
