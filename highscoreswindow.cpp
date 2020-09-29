#include "highscoreswindow.h"


highscoresWindow::highscoresWindow(User user, QWidget *parent) : QWidget(parent)
{
    // getting the user info
    QString username = user.getUsername();
    QString firstName = user.getFirstName();
    QString lastName = user.getLastName();

    QPixmap profilePic = user.getProfilePicture();
    profilePicLabel = new QLabel();
    profilePicLabel->setPixmap(profilePic);

    welcomeLabel = new QLabel("Welcome back " + firstName +" "+ lastName + "!");
    usernameLabel = new QLabel(username);
    usernameLabel->setStyleSheet("font: 45px;");
    usernameLabel->setAlignment(Qt::AlignCenter);

    gridLayout = new QGridLayout();

    groupBoxLeft = new QGroupBox();
    groupBoxRight = new QGroupBox();

    // setting the vertical layout on the left
    verticalLayoutLeft = new QVBoxLayout();
    verticalLayoutLeft->addWidget(profilePicLabel);
    verticalLayoutLeft->addWidget(usernameLabel);
    verticalLayoutLeft->addWidget(welcomeLabel);

    // setting the vertical layout on the right
    verticalLayoutRight = new QVBoxLayout();

    groupBoxLeft->setLayout(verticalLayoutLeft);
    groupBoxRight->setLayout(verticalLayoutRight);


    // setting the grid layout
    gridLayout->addWidget(groupBoxLeft, 0, 0);
    gridLayout->addWidget(groupBoxRight, 0, 1);

    setLayout(gridLayout);
}

