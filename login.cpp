#include "login.h"
#include <QSizePolicy>
#include "signup.h"
#include<errorwindows.h>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QRandomGenerator>
#include <QTextStream>


login::login(QWidget *parent) : QWidget(parent)
{


    logIn = new QLabel("Log In");
    logIn->setStyleSheet("font: 25px;");
    logIn->setAlignment(Qt::AlignCenter);

    username = new QLabel("Username");
    password = new QLabel("Password");

    usernameEdit = new QLineEdit();

    passEdit = new QLineEdit();
    passEdit->setEchoMode(QLineEdit::Password);   // this will hide when inputing the password


    logInButton = new QPushButton("Log In");

    signUpButton = new QPushButton("Sign Up");
    playAsGuestButton = new QPushButton("Play as Guest");

    // Grid Layout
    gridLayout = new QGridLayout();

    gridLayout->addWidget(logIn, 0,0);
    gridLayout->addWidget(username, 1, 0);
    gridLayout->addWidget(usernameEdit, 2, 0);
    gridLayout->addWidget(password, 3,0);
    gridLayout->addWidget(passEdit, 4, 0);
    gridLayout->addWidget(logInButton, 5, 0);

    // Vertical Layout
    verticalLayout = new QVBoxLayout();
    verticalLayout->addItem(gridLayout);
    verticalLayout->addItem(new QSpacerItem(50,50));
    verticalLayout->addWidget(signUpButton);
    verticalLayout->addWidget(playAsGuestButton);

    verticalLayout->setSpacing(20); // spacing between vertical entries in box
    verticalLayout->setMargin(40);

    setLayout(verticalLayout);
    //slots connection

    // when we press the play as guest button
    QObject::connect(playAsGuestButton, SIGNAL(clicked(bool)), this, SLOT(playAsGuestFunc()));
    // when we press the log in button
    QObject::connect(logInButton, SIGNAL(clicked(bool)), this, SLOT(loggingIn()));
    // when we press the sign up button instead
    QObject::connect(signUpButton, SIGNAL(clicked(bool)), this, SLOT(signUpInstead()));

}

void login::playAsGuestFunc(){
    usernameEdit->setText("Guest");
    passEdit->setText("GuestPassword1");
    User* u = new User();
    login::highscoresPage(0, *u );
}

void login::loggingIn(){
    QString username = usernameEdit->text();
    QString password = passEdit->text();

    if (app.login(username, password)) {
        User user = app.getUser(username);
        usernameEdit->setText(user.getUsername());
        login::highscoresPage(1, user);
    } else {
        usernameEdit->setText("FAILURE");
        login::openErrorWindow();

    }


}

void login::signUpInstead(){

    signUp* signUpWindow = new signUp();
    signUpWindow->show();
    this->close();
}

void login::highscoresPage(int code, User user){
    // if code is zero, thn log in as guest
    highscoresWindow* highWindow = new highscoresWindow(app, code, user);
    highWindow->show();
    this->close();
}

void login::openErrorWindow(){
    errorWindows* errorW = new errorWindows();
    errorW->setErrorLabel("Username or Password is incorrect!");
    errorW->show();

}

