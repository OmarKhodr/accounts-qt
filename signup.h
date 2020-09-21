#ifndef SIGNUP_H
#define SIGNUP_H

#include<QObject>
#include <QWidget>
#include<QtWidgets>

class signUp : public QWidget
{
    Q_OBJECT
public:
    explicit signUp(QWidget *parent = nullptr);


private:
    QLabel* sign_up;
    QLabel* first_name;
    QLabel* last_name;
    QLabel* username;
    QLabel* password;
    QLabel* confirm_password;
    QLabel* date_of_birth;
    QLabel* gender;
    QLabel* profile_pic;

    QLineEdit* firstName_edit;
    QLineEdit* lastName_edit;
    QLineEdit* username_edit;
    QLineEdit* password_edit;
    QLineEdit* confirm_edit;

    QCalendarWidget* date_birth_calendar;

    QPushButton* submit_btn;
    QPushButton* back_to_login;

    QVBoxLayout* vertical_layout;
    QGridLayout* grid_layout;


signals:

};

#endif // SIGNUP_H
