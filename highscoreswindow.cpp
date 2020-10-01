#include "highscoreswindow.h"


highscoresWindow::highscoresWindow(App app, int code, User user, QWidget *parent) : QWidget(parent)
{

    QDate userBirthday = user.getDateOfBirth();
    QString userBirthdayString = userBirthday.toString();
    checkIfBirthday(userBirthdayString);

    profilePicLabel = new QLabel();
    profilePicLabel->setAlignment(Qt::AlignCenter);

    welcomeLabel = new QLabel();
    usernameLabel = new QLabel();
    usernameLabel->setStyleSheet("font: 30px;");
    usernameLabel->setAlignment(Qt::AlignCenter);

    // these widgets will be on the right

    globalHighscorePlayerLabel = new QLabel(app.getHighscore(user.getUsername()));
    globalHighscorePlayerLabel->setAlignment(Qt::AlignCenter);
    userScoresLabel = new QLabel();
    userScoresLabel->setAlignment(Qt::AlignCenter);
    compareScoresLabel = new QLabel();
    compareScoresLabel->setAlignment(Qt::AlignCenter);


    // code==0 then play as guest
    if (code == 0){
        playAsGuest();
    }

    if(code == 1){
        playAsUser(user);
    }

    gridLayout = new QGridLayout();

    groupBoxLeft = new QGroupBox();
    groupBoxRight = new QGroupBox();

    // setting the vertical layout on the left
    verticalLayoutLeft = new QVBoxLayout();
    verticalLayoutLeft->addWidget(profilePicLabel);
    verticalLayoutLeft->addWidget(usernameLabel);
    verticalLayoutLeft->addWidget(welcomeLabel);

    // widgets that will be on the right
    highscoreLabel = new QLabel("RANKING");
    highscoreLabel->setStyleSheet("font: 20px;");
    highscoreLabel->setAlignment(Qt::AlignCenter);



    // setting the vertical layout on the right
    verticalLayoutRight = new QVBoxLayout();
    verticalLayoutRight->addWidget(highscoreLabel);
    verticalLayoutRight->addWidget(globalHighscorePlayerLabel);
    verticalLayoutRight->addWidget(userScoresLabel);
    verticalLayoutRight->addWidget(compareScoresLabel);

    // setting the layout of the group boxes
    groupBoxLeft->setLayout(verticalLayoutLeft);
    groupBoxRight->setLayout(verticalLayoutRight);


    // setting the grid layout
    gridLayout->addWidget(groupBoxLeft, 0, 0);
    gridLayout->addWidget(groupBoxRight, 0, 1);

    setLayout(gridLayout);
}

// if it's the user's birthday display a "Happy Birthday message"
void highscoresWindow::checkIfBirthday(QString birthdayStr){
    QDate currentDate = QDate::currentDate();
    QString dateString = currentDate.toString();

    if (QString::compare(dateString , birthdayStr)==0){
        successWindow* succW = new successWindow();
        succW->changeSuccessLabel("TODAY IS YOUR BIRTHDAY! ");
        succW->setSuccessLabelPicture(QPixmap(":/images/banner-happy-birthday.png"));
        succW->show();
    }

}

void highscoresWindow::playAsGuest(){
    profilePicLabel->setPixmap(QPixmap(":/images/User_icon.png").scaled(200, 200));
    usernameLabel->setText("Guest");
    welcomeLabel->setText("We welcome you as a guest! Hope you enjoy!");
    userScoresLabel->setText("Scores: \n Sign up to play and see your scores!");

}

void highscoresWindow::playAsUser(User user){
    // getting the user info
    QString username = user.getUsername();
    QString firstName = user.getFirstName();
    QString lastName = user.getLastName();

    QPixmap profilePic = user.getProfilePicture();

    welcomeLabel->setText( "Welcome back, " + firstName +" "+ lastName + "!");
    usernameLabel->setText(username);
    profilePicLabel->setPixmap(profilePic);
    userScoresLabel->setText(user.getUserScores());


}

