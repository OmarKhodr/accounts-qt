#include "signup.h"
#include "login.h"
#include"successwindow.h"
#include"errorwindows.h"

signUp::signUp(QWidget *parent) : QWidget(parent)
{

    sign_up = new QLabel("Sign Up");
//    sign_up->setStyleSheet("font: 80px;");
    sign_up->setAlignment(Qt::AlignCenter);

    first_name = new QLabel("First Name");
//    first_name->setStyleSheet("font: 40px;");

    last_name = new QLabel("Last Name");
//    last_name->setStyleSheet("font: 40px;");

    username = new QLabel("Username");
//    username->setStyleSheet("font: 40px;");

    password = new QLabel("Password");
//    password->setStyleSheet("font: 40px;");

    confirm_password = new QLabel("Confirm Password");
//    confirm_password->setStyleSheet("font: 40px;");

    date_of_birth = new QLabel("Date Of Birth");
//    date_of_birth->setStyleSheet("font: 40px");

    profile_pic = new QLabel("Profile Picture");
//    profile_pic->setStyleSheet("font: 40px;");

    gender = new QLabel("Gender");
//    gender->setStyleSheet("font: 40px;");

    browse_pic = new QLabel();
//    browse_pic->setFixedSize(300, 200);

    date_birth_calendar = new QCalendarWidget();
//    date_birth_calendar->setMaximumHeight(440);
//    date_birth_calendar->setMinimumWidth(140);

    gender_male = new QRadioButton("Male");
    gender_female = new QRadioButton("Female");
    gender_other = new QRadioButton("Other");

    buttons_vertical_layout = new QVBoxLayout();
    buttons_vertical_layout->addWidget(gender_male);
    buttons_vertical_layout->addWidget(gender_female);
    buttons_vertical_layout->addWidget(gender_other);
    gender_radio_buttons_box = new QGroupBox();
    gender_radio_buttons_box->setLayout(buttons_vertical_layout);
//    gender_radio_buttons_box->setStyleSheet("Font: 20px;");

    firstName_edit = new QLineEdit();
//    firstName_edit->setStyleSheet("font: 40px;");
    lastName_edit = new QLineEdit();
//    lastName_edit->setStyleSheet("font: 40px;");
    username_edit = new QLineEdit();
//    username_edit->setStyleSheet("font: 40px;");
    password_edit = new QLineEdit();
//    password_edit->setStyleSheet("font: 40px;");
    password_edit->setEchoMode(QLineEdit::Password);
    confirm_edit = new QLineEdit();
//    confirm_edit->setStyleSheet("font: 40px;");
    confirm_edit->setEchoMode(QLineEdit::Password);


    back_to_login = new QPushButton("Back to Log In");
//    back_to_login->setStyleSheet("font: 30px;"
//                                 "height: 40px;");
    submit_btn = new QPushButton("Submit");
//    submit_btn->setStyleSheet("font: 30px;"
//                              "height: 40px;");

    browse_button = new QPushButton("Browse For Picture");
//    browse_button->setStyleSheet("font: 20px;"
//                                 "height: 30px;");

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


    // loading the users
    app.readFromJSON();

    // connect the login button
    QObject::connect(back_to_login, SIGNAL(clicked(bool)), this, SLOT(login_instead()));
    // Let's user browse for his/her own picture to add
    QObject::connect(browse_button, SIGNAL(clicked(bool)), this, SLOT(upload_picture()));
    //sign up
    QObject::connect(submit_btn, SIGNAL(clicked(bool)), this, SLOT(signup()));
    // check if username already exists
    QObject::connect(username_edit, SIGNAL(editingFinished()), this, SLOT(validate_Username()));
    // check if both passwords are equal
    QObject::connect(confirm_edit, SIGNAL(editingFinished()), this, SLOT(check_Both_Passwords()));
    // check if password has requirements
    QObject::connect(password_edit, SIGNAL(editingFinished()), this, SLOT(validate_password()));

}

void signUp::validate_Username(){
    // check if username already taken
    bool taken = false;
    QVector<User> users = app.getUsers();
    for (User user: users ){
        QString userName = user.getUsername();
        if(QString::compare(userName, username_edit->text())==0 ){
            taken = true;
        }
    }
    if(taken == true ){
        signUp::invalid(username, 1);
    }

}


void signUp::validate_password(){
    bool valid_size = true;
    bool valid_numbers = false;
    bool valid_upper = false;
    bool valid_lower = false;
    QString pass = password_edit->text();
    if (pass.size()<8){
        valid_size = false;
    }
    for (int i = 0 ; i<pass.size(); i++){
        if ( pass[i]>='0' and pass[i]<='9'){
            valid_numbers = true;
        }
        else if (pass[i]>='a' and pass[i]<='z'){
            valid_lower = true;
        }
        else if (pass[i]>='A' and pass[i]<='Z'){
            valid_upper = true;
        }

        if (valid_lower and valid_upper and valid_numbers){
            break;
        }
    }

    if ( (!valid_size) or (!valid_lower) or (!valid_upper) or (!valid_numbers) ){
        invalid(password, 2);
    }

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

void signUp::invalid(QLabel* label, int errorCode) {
    errorWindows* errW = new errorWindows();
    if (label->text()=="Username"){
        if(errorCode==1){
            errW->setErrorLabel("Username already taken!");
        }else{
            errW->setErrorLabel("Username field is empty!");
        }
        username_edit->setStyleSheet("border: 1px solid red;");
    } else if(label->text()=="First Name"){
        errW->setErrorLabel("First name field is empty!");
        firstName_edit->setStyleSheet("border: 1px solid red;");
    } else if(label->text()=="Last Name"){
        errW->setErrorLabel("Last Name field is empty!");
        lastName_edit->setStyleSheet("border: 1px solid red;");
    } else if(label->text()=="Gender"){
        errW->setErrorLabel("Gender field is empty!");
    } else if(label->text()=="Password"){
        if(errorCode==0){
            errW->setErrorLabel("Password field is empty!");
            password_edit->setStyleSheet("border: 1px solid red;");
        }
        else if (errorCode==1){
            errW->setErrorLabel("Password field and confirm password are not holding the same password!");
            confirm_edit->setStyleSheet("border: 1px solid red;");
        }
        else if(errorCode==2){
            errW->setErrorLabel("Password must contain at least 8 letters, one uppercase, one lowercase and a number!");
            password_edit->setStyleSheet("border: 1px solid red;");
        }
    }
    errW->show();
}

void signUp::signup() {
    User user;
    if (QString::compare(username_edit->text(), QString()) == 0) {
        invalid(username, 0);
    } else if (QString::compare(firstName_edit->text(), QString()) == 0) {
        invalid(first_name, 0);
    } else if (QString::compare(lastName_edit->text(), QString()) == 0) {
        invalid(last_name, 0);
    } else if (QString::compare(password_edit->text(), QString()) == 0) {
        invalid(password, 0);
    } else if (QString::compare(confirm_edit->text(), QString()) == 0 ) {
        invalid(confirm_password,0);
    } else if (QString::compare(confirm_edit->text(), password_edit->text()) != 0){
        invalid(password, 1);
    } else if (!gender_male->isChecked() && !gender_female->isChecked() && !gender_other->isChecked()) {
        invalid(gender, 0);
    }
    user.setUsername(username_edit->text());
    user.setPassword(password_edit->text());
    user.setFirstName(firstName_edit->text());
    user.setLastName(lastName_edit->text());
    user.setDateOfBirth(date_birth_calendar->selectedDate());
    user.setProfilePicture(*(browse_pic->pixmap() ));
    if (gender_male->isChecked()) {
        user.setGender(User::Male);
    } else if (gender_female->isChecked()) {
        user.setGender(User::Female);
    } else {
        user.setGender(User::Other);
    }
    app.signup(user);
    // display success window
    successWindow* sW = new successWindow();
    sW->setSuccessLabel("User successfully created! You can now head back to Log In!");
    sW->show();
    username_edit->setText("");
    password_edit->setText("");
    confirm_edit->setText("");
    firstName_edit->setText("");
    lastName_edit->setText("");

}

