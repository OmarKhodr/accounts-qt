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

//QMap<QString, int> User::getHighScores() const {
//    return highScores;
//}
//void User::setHighScores(const QMap<QString, int> &ahighScores) {
//    highScores = ahighScores;
//}

/*
QJsonValue jsonValFromImage(const QImage &p) {
  QBuffer buffer;
  buffer.open(QIODevice::WriteOnly);
  p.save(&buffer, "PNG");
  auto const encoded = buffer.data().toBase64();
  return {QLatin1String(encoded)};
}

QImage imageFromJsonVal(const QJsonValue &val) {
  auto const encoded = val.toString().toLatin1();
  QImage p;
  p.loadFromData(QByteArray::fromBase64(encoded), "PNG");
  return p;
}
*/

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

}

void User::write(QJsonObject &json) const {
    json["username"] = username;
    json["password"] = password;
    json["firstName"] = firstName;
    json["lastName"] = lastName;
    QString date = "";
    date.append(dateOfBirth.year());
    date.append("/");
    date.append(dateOfBirth.month());
    date.append("/");
    date.append(dateOfBirth.day());
    date.append("/");
    json["dateOfBirth"] = date;
    json["gender"] = gender;
    json["profilePicture"] = jsonValFromPixmap(profilePicture);
}
