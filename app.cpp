#include "app.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextStream>
#include<QtAlgorithms>

App::App() { }

void App::readFromJSON(){
    //if users array is empty (i.e. potentially not read from yet), read
    if (users.size() == 0) {

        QFile loadFile(QStringLiteral("save.json"));

        if (!loadFile.open(QIODevice::ReadOnly)) {
                qWarning("Couldn't open save file.");
                return;
         }

        QByteArray saveData = loadFile.readAll();

        QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

        //get the root JSON object from the document then call read() on it
        read(loadDoc.object());
    }

}

QVector<User> App::getUsers() const {
    return users;
}

void App::setUsers(const QVector<User> &ausers) {
    users = ausers;
}

//returns a boolean indicating if login was successful or not because of invalid credentials
//or because the JSON file couldn't be loaded to be read from
bool App::login(const QString &username, const QString &password) {
    if (users.size() == 0) {
        QFile loadFile(QStringLiteral("save.json"));

        if (!loadFile.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open save file.");
            return false;
        }

        QByteArray saveData = loadFile.readAll();

        QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

        read(loadDoc.object());
    }

    for (int i=0; i<users.size(); i++) {
        User user = users[i];
        if (user.getUsername() == username && user.getPassword() == password) {
            return true;
        }
    }

    return false;
}

//returns a boolean indicating whether file was successfully open
//and written to
bool App::signup(const User &user) {
    if (users.size() == 0) {
        QFile loadFile("save.json");

        if (loadFile.open(QIODevice::ReadOnly)) {
            QByteArray saveData = loadFile.readAll();

            QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

            read(loadDoc.object());
        }
    }

    QFile saveFile(QStringLiteral("save.json"));

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;
    }

    users.append(user);
    QJsonObject appObj;
    write(appObj);
    QJsonDocument saveDoc(appObj);

    saveFile.write(saveDoc.toJson());

    return true;
}

User App::getUser(const QString &username) {
    for (int i=0; i<users.size(); i++) {
        User user = users[i];
        if (user.getUsername() == username) {
            return user;
        }
    }
    return User();
}

void App::read(const QJsonObject &json) {
    if (json.contains("users") && json["users"].isArray()) {
        QJsonArray usersArray = json["users"].toArray();
        users.clear();
        users.reserve(usersArray.size());
        for (int userInd=0; userInd<usersArray.size(); userInd++) {
            QJsonObject userObj = usersArray[userInd].toObject();
            User user;
            user.read(userObj);
            users.append(user);
        }
    }
}

void App::write(QJsonObject &json) const {
    QJsonArray usersArray;
    foreach (const User user, users) {
        QJsonObject userObj;
        user.write(userObj);
        usersArray.append(userObj);
    }
    json["users"] = usersArray;
}

QString App::getHighscore(QString currUsername){
    QVector<User> userVector = getUsers();
    int maxScore = 0;
    QString userWithHighscore = "";
    for (User user: userVector) {
        QVector<int> scoresVector = user.getScores();
        for(int score: scoresVector){
            if (score>maxScore){
                maxScore = score;
                userWithHighscore = user.getUsername();
            }
        }
    }
    bool tie = false;
    int usersWithHighscore = 0;
    for (User user: userVector) {
        QVector<int> scoresVector = user.getScores();
        for(int score: scoresVector){
            if (score==maxScore){
                usersWithHighscore++;
            }
        }
        if(usersWithHighscore>1){
            tie = true;
            break;
        }
    }
    User u = getUser(currUsername);
    QString ret;
    if (currUsername == userWithHighscore) {
        ret = "Congratulations! You have the global highscore with " + QString::number(maxScore)+ " points!";
    } else if (u.getHighscore()==maxScore and tie==true){
        ret = "Congratulations! But be aware, you are tied with other player(s) with a highscore of "+ QString::number(maxScore)+ " points!";
    } else {
        ret = "Player " + userWithHighscore + " has the global highscore with " + QString::number(maxScore)+ " points. Keep trying!";
    }
    return ret;
}




