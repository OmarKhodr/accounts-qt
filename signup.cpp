#include "signup.h"
#include "login.h"

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

    browse_pic = new QLabel();
    browse_pic->setFixedSize(300, 200);

    date_birth_calendar = new QCalendarWidget();
    date_birth_calendar->setMaximumHeight(440);
    date_birth_calendar->setMinimumWidth(140);

    gender_male = new QRadioButton("Male");
    gender_female = new QRadioButton("Female");
    gender_other = new QRadioButton("Other");

    buttons_vertical_layout = new QVBoxLayout();
    buttons_vertical_layout->addWidget(gender_male);
    buttons_vertical_layout->addWidget(gender_female);
    buttons_vertical_layout->addWidget(gender_other);
    gender_radio_buttons_box = new QGroupBox();
    gender_radio_buttons_box->setLayout(buttons_vertical_layout);
    gender_radio_buttons_box->setStyleSheet("Font: 20px;");

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

    browse_button = new QPushButton("Browse For Picture");
    browse_button->setStyleSheet("font: 20px;"
                                 "height: 30px;");

    picture_vertical_layout = new QVBoxLayout();
    picture_vertical_layout->addWidget(browse_pic);
    picture_vertical_layout->addWidget(browse_button);
    picture_box = new QGroupBox();
    picture_box->setLayout(picture_vertical_layout);

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
    grid_layout->addWidget(gender_radio_buttons_box, 7, 1);
    grid_layout->addWidget(profile_pic, 8, 0);
    grid_layout->addWidget(picture_box, 8, 1);
    grid_layout->addWidget(submit_btn, 9, 0, 9, 2);



    // vertical layout
    vertical_layout =new QVBoxLayout();
    vertical_layout->addItem(grid_layout);
    vertical_layout->addWidget(back_to_login);
    vertical_layout->setMargin(20);


    // set overall layout
    setLayout(vertical_layout);

    // connect the login button
    QObject::connect(back_to_login, SIGNAL(clicked(bool)), this, SLOT(login_instead()));
    // Let's user browse for his/her own picture to add
    QObject::connect(browse_button, SIGNAL(clicked(bool)), this, SLOT(upload_picture() ) );

}

void signUp::login_instead(){
    login* log_window = new login();
    log_window->show();
    this->close();
}


void signUp::upload_picture(){

    // filename variable will hold the name of the file the user chooses
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose a picture"),
                                                    "", tr("Images (*.png *.jpg *.jpeg *.bmp)"));
    // check if file name is valid

    if(QString::compare(filename, QString()) != 0 ){

        QImage image;
        bool valid = image.load(filename);  // if what is loaded is a valid image it's true

        if (valid){

            image = image.scaledToWidth(browse_pic->width(), Qt::SmoothTransformation);
            browse_pic->setPixmap(QPixmap::fromImage(image));

        } else{
            // We can add some kind of error handling
        }

    }

}

