#ifndef LOGIN_H
#define LOGIN_H

#include<QObject>
#include <QWidget>
#include<QtWidgets>
#include "app.h"
#include "user.h"

class login : public QWidget
{
    Q_OBJECT
public:
    explicit login(QWidget *parent = nullptr);

private:
    QLabel *logIn;
    QLabel *username;
    QLineEdit *usernameEdit;
    QLabel *password;
    QLineEdit *passEdit;

    QPushButton *logInButton;
    QPushButton *signUpButton;
    QPushButton *playAsGuestButton;

    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;

    App app;


signals:


public slots:
    void playAsGuestFunc();
    void loggingIn();
    void signUpInstead();

};

#endif // LOGIN_H
