#ifndef HIGHSCORESWINDOW_H
#define HIGHSCORESWINDOW_H

#include"user.h"
#include"app.h"
#include <QWidget>
#include<QObject>
#include<QtWidgets>
#include"successwindow.h"
#include<QDateTime>

class highscoresWindow : public QWidget
{
    Q_OBJECT
public:
    explicit highscoresWindow( App app, int code, User user , QWidget *parent = nullptr);

    QLabel* welcomeLabel;
    QLabel* usernameLabel;
    QLabel* profilePicLabel;
    QLabel* highscoreLabel;
    QLabel* globalHighscorePlayerLabel;
    QLabel* compareScoresLabel;
    QLabel* userScoresLabel;

    QGridLayout* gridLayout;

    QVBoxLayout* verticalLayoutRight;
    QVBoxLayout* verticalLayoutLeft;
    QVector<QLabel*> scores;

    QGroupBox* groupBoxRight;
    QGroupBox* groupBoxLeft;

signals:

private:
    void checkIfBirthday(QString str);
    void playAsGuest();
    void playAsUser(User user);


};

#endif // HIGHSCORESWINDOW_H
