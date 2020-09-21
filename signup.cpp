#include "signup.h"

signUp::signUp(QWidget *parent) : QWidget(parent)
{
    sign_up = new QLabel("Sign Up");
    sign_up->setStyleSheet("font: 80px;");
    sign_up->setAlignment(Qt::AlignCenter);

    first_name = new QLabel("First Name");
    first_name->setStyleSheet("font: 40px;");

    last_name = new QLabel("Last Name");
    last_name->setStyleSheet("font: 40px;");

    username = new QLabel("Username");
    username->setStyleSheet("font: 40px;");

    password = new QLabel("Password");
    password->setStyleSheet("font: 40px;");

    confirm_password = new QLabel("Confirm Password");
    confirm_password->setStyleSheet("font: 40px;");

    date_of_birth = new QLabel("Date Of Birth");
    date_of_birth->setStyleSheet("font: 40px");

    profile_pic = new QLabel("Profile Picture");
    profile_pic->setStyleSheet("font: 40px;");

    gender = new QLabel("Gender");
    gender->setStyleSheet("font: 40px;");

    date_birth_calendar = new QCalendarWidget();
    date_birth_calendar->setMaximumHeight(440);
    date_birth_calendar->setMinimumWidth(140);


    firstName_edit = new QLineEdit();
    firstName_edit->setStyleSheet("font: 40px;");
    lastName_edit = new QLineEdit();
    lastName_edit->setStyleSheet("font: 40px;");
    username_edit = new QLineEdit();
    username_edit->setStyleSheet("font: 40px;");
    password_edit = new QLineEdit();
    password_edit->setStyleSheet("font: 40px;");
    password_edit->setEchoMode(QLineEdit::Password);
    confirm_edit = new QLineEdit();
    confirm_edit->setStyleSheet("font: 40px;");
    confirm_edit->setEchoMode(QLineEdit::Password);


    back_to_login = new QPushButton("Back to Log In");
    back_to_login->setStyleSheet("font: 30px;"
                                 "height: 40px;");
    submit_btn = new QPushButton("Submit");
    submit_btn->setStyleSheet("font: 30px;"
                              "height: 40px;");

    // grid layout
    grid_layout = new QGridLayout();
    grid_layout->addWidget(sign_up, 0, 0, 1, 3);
    grid_layout->addWidget(first_name, 1, 0);
    grid_layout->addWidget(firstName_edit, 1, 1);
    grid_layout->addWidget(last_name, 2, 0);
    grid_layout->addWidget(lastName_edit, 2, 1);
    grid_layout->addWidget(username, 3, 0);
    grid_layout->addWidget(username_edit, 3, 1);
    grid_layout->addWidget(password, 4, 0);
    grid_layout->addWidget(password_edit, 4, 1);
    grid_layout->addWidget(confirm_password, 5, 0);
    grid_layout->addWidget(confirm_edit, 5, 1);
    grid_layout->addWidget(date_of_birth, 6, 0);
    grid_layout->addWidget(date_birth_calendar, 6, 1);
    grid_layout->addWidget(gender, 7, 0);
    grid_layout->addWidget(profile_pic, 8, 0);
    grid_layout->addWidget(submit_btn, 9, 0, 9, 2);



    // vertical layout
    vertical_layout =new QVBoxLayout();
    vertical_layout->addItem(grid_layout);
    vertical_layout->addWidget(back_to_login);
    vertical_layout->setMargin(20);


    // set overall layout
    setLayout(vertical_layout);


}

