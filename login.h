#ifndef LOGIN_H
#define LOGIN_H

#include<QObject>
#include <QWidget>
#include<QtWidgets>

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

    QPushButton *signUpButton;
    QPushButton *playAsGuestButton;

    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;

signals:

};

#endif // LOGIN_H
