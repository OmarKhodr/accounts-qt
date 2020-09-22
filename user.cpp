#include "user.h"

//#include <QMetaEnum>

User::User() :
    gender(Female) {

}

QString User::getUsername() const {
    return username;
}
void User::setUsername(const QString &ausername) {
    username = ausername;
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

QImage User::getProfilePicture() const {
    return profilePicture;
}
void User::setProfilePicture(const QImage &aprofilePicture) {
    profilePicture = aprofilePicture;
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
        firstName = json["lastName"].toString();
    }

}
