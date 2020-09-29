#include "app.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextStream>

App::App() { }

void App::readFromJSON(){
    if (users.size() == 0) {

        QFile loadFile(QStringLiteral("save.json"));

        if (!loadFile.open(QIODevice::ReadOnly)) {
                qWarning("Couldn't open save file.");
         }

        QByteArray saveData = loadFile.readAll();

        QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

        read(loadDoc.object());
    }

}

QVector<User> App::getUsers() const {
    return users;
}

void App::setUsers(const QVector<User> &ausers) {
    users = ausers;
}

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



