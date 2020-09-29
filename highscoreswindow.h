#ifndef HIGHSCORESWINDOW_H
#define HIGHSCORESWINDOW_H

#include"user.h"
#include <QWidget>
#include<QObject>
#include<QtWidgets>

class highscoresWindow : public QWidget
{
    Q_OBJECT
public:
    explicit highscoresWindow( User user , QWidget *parent = nullptr);

    QLabel* welcomeLabel;
    QLabel* usernameLabel;
    QLabel* profilePicLabel;

    QGridLayout* gridLayout;

    QVBoxLayout* verticalLayoutRight;
    QVBoxLayout* verticalLayoutLeft;
    QVector<QLabel*> scores;

    QGroupBox* groupBoxRight;
    QGroupBox* groupBoxLeft;

signals:

private:
    User user;


};

#endif // HIGHSCORESWINDOW_H
