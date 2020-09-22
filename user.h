#ifndef USER_H
#define USER_H

#include <QJsonObject>
#include <QString>
#include <QDate>
#include <QImage>

class User {

    Q_GADGET;

public:
    enum Gender {
        Male, Female
    };
    Q_ENUM(Gender)

    User();

    QString getUsername() const;
    void setUsername(const QString &ausername);

    void setPassword(const QString &apassword);

    QString getFirstName() const;
    void setFirstName(const QString &afirstName);

    QString getLastName() const;
    void setLastName(const QString &alastName);

    QDate getDateOfBirth() const;
    void setDateOfBirth(const QDate &adateOfBirth);

    Gender getGender() const;
    void setGender(Gender agender);

    QImage getProfilePicture() const;
    void setProfilePicture(const QImage &aprofilePicture);

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

private:
    QString username;
    QString password;
    QString firstName;
    QString lastName;
    QDate dateOfBirth;
    Gender gender;
    QImage profilePicture;
};

#endif // USER_H
