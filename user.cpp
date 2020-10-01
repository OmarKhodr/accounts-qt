#include "user.h"

#include <QBuffer>

User::User() :
    gender(Female) {

}

QString User::getUsername() const {
    return username;
}
void User::setUsername(const QString &ausername) {
    username = ausername;
}

QString User::getPassword() const {
    return password;
}
void User::setPassword(const QString &apassword) {
    password = apassword;
}

QString User::getFirstName() const {
    return firstName;
}
void User::setFirstName(const QString &afirstName) {
    firstName = afirstName;
}

QString User::getLastName() const {
    return lastName;
}
void User::setLastName(const QString &alastName) {
    lastName = alastName;
}

QDate User::getDateOfBirth() const {
    return dateOfBirth;
}
void User::setDateOfBirth(const QDate &adateOfBirth) {
    dateOfBirth = adateOfBirth;
}

User::Gender User::getGender() const {
    return gender;
}
void User::setGender(User::Gender agender) {
    gender = agender;
}

QPixmap User::getProfilePicture() const {
    return profilePicture;
}
void User::setProfilePicture(const QPixmap &aprofilePicture) {
    profilePicture = aprofilePicture;
}

QVector<int> User::getScores() const {
    return scores;
}
void User::setScores(const QVector<int> &ascores) {
    scores = ascores;
}

QJsonValue jsonValFromPixmap(const QPixmap &p) {
  QBuffer buffer;
  buffer.open(QIODevice::WriteOnly);
  p.save(&buffer, "PNG");
  auto const encoded = buffer.data().toBase64();
  return {QLatin1String(encoded)};
}

QPixmap pixmapFrom(const QJsonValue &val) {
  auto const encoded = val.toString().toLatin1();
  QPixmap p;
  p.loadFromData(QByteArray::fromBase64(encoded), "PNG");
  return p;
}

void User::read(const QJsonObject &json) {
    if (json.contains("username") && json["username"].isString()) {
        username = json["username"].toString();
    }
    if (json.contains("password") && json["password"].isString()) {
        password = json["password"].toString();
    }
    if (json.contains("firstName") && json["firstName"].isString()) {
        firstName = json["firstName"].toString();
    }
    if (json.contains("lastName") && json["lastName"].isString()) {
        lastName = json["lastName"].toString();
    }
    if (json.contains("dateOfBirth") && json["dateOfBirth"].isString()) {
        QString s = json["dateOfBirth"].toString();
        QStringList parts = s.split(QString("/"));
        int year = parts.at(0).toInt(), month = parts.at(1).toInt(), day = parts.at(2).toInt();
        dateOfBirth = QDate(year, month, day);
    }
    if (json.contains("gender") && json["gender"].isDouble()) {
        gender = Gender(json["gender"].toInt());
    }
    if (json.contains("profilePicture")) {
        QJsonValue val = json.value("profilePicture");
        profilePicture = pixmapFrom(val);
    }
    if (json.contains("scores") && json["scores"].isArray()) {
        QJsonArray arr = json["scores"].toArray();
        scores.clear();
        scores.reserve(arr.size());
        for (int ind=0; ind<arr.size(); ind++) {
            int score = arr[ind].toInt();
            scores.append(score);
        }
    }
}

void User::write(QJsonObject &json) const {
    json["username"] = username;
    json["password"] = password;
    json["firstName"] = firstName;
    json["lastName"] = lastName;
    QString date = "";
    date.append(QString::number(dateOfBirth.year() ));
    date.append("/");
    date.append(QString::number(dateOfBirth.month() ));
    date.append("/");
    date.append(QString::number(dateOfBirth.day()));
    date.append("/");
    json["dateOfBirth"] = date;
    json["gender"] = gender;
    json["profilePicture"] = jsonValFromPixmap(profilePicture);
    QJsonArray scoresArray;
    foreach (const int score, scores) {
        scoresArray.append(score);
    }
    json["scores"] = scoresArray;
}


QString User::getUserScores(){
    QVector<int> userScores = getScores();
    qSort(userScores);
    QString scoresStr = "Scores: \n";
    // we will only show the 10 highest scores of the user
    for (int i = userScores.size()-1; i>=userScores.size()-10 and i>=0 ; i--){
        scoresStr = scoresStr + QString::number(userScores[i]) + "pts\n";
    }
    return scoresStr;
}

int User::getHighscore(){
    QVector<int> userScores = getScores();
    qSort(userScores);
    return userScores[userScores.size()-1];
}
