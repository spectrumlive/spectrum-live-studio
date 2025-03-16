/******************************************************************************
 Copyright (C) 2025 by Nanusorn Photpipat (nanusorn@photpipat.com)
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 2 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/

#include "SPTAuthenticate.hpp"
#include "auth/OAuthManager.hpp"
#include "auth/SPTAPIServices.hpp"
#include <QWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

SPTAuthenticate::SPTAuthenticate(QWidget *parent) : QWidget(parent), ui(new Ui::SPTAuthenticate), mpAuthManager(new OAuthManager())
{
   ui->setupUi(this);
   initUi();
   
   QObject::connect(mpAuthManager, &OAuthManager::loginSuccess, [this](const QString &token) {
      SPTAPIServices services(token);
      QJsonObject result = services.getUserInfo();
      
      // Save incoming user's slug
      this->mpAuthManager->saveUserInfo(token, result["donationSlug"].toString(),
                                      result["liveSlug"].toString(), result["walletAddress"].toString());

      this->mpMainWindow->show();
      this->close();
   });
   
   QObject::connect(mpAuthManager, &OAuthManager::loginFailed, [](const QString &error) {
      qDebug() << "Login failed:" << error;
   });
}

SPTAuthenticate::~SPTAuthenticate() {
   if (mpAuthManager)
      delete mpAuthManager;
}

void SPTAuthenticate::initUi()
{
   this->setFixedSize(size());
   ui->btnAppleID->setDisabled(true);
   connect(ui->btnGoogleMail, &QPushButton::clicked, this, [this](){
      this->mpAuthManager->startLogin(QtEnumToQString<OAuthProvider::Provider>(OAuthProvider::GOOGLE));
   });
   connect(ui->btnAppleID, &QPushButton::clicked, this, [this]() {
      this->mpAuthManager->startLogin(QtEnumToQString<OAuthProvider::Provider>(OAuthProvider::APPLE));
   });
   connect(ui->btnSkipAuthen, &QPushButton::clicked, this, [this]() {
      this->hide();
      this->mpMainWindow->show();
   });
}

