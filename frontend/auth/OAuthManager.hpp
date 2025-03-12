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

#pragma once

#include <QtCore>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QDesktopServices>
#include <QTcpServer>
#include <QTcpSocket>
#include <util/util.hpp>

namespace OAuthProvider
{
   Q_NAMESPACE
   
   enum Provider
   {
      GOOGLE,
      APPLE
   };
   Q_ENUM_NS(Provider);
}

template <typename QEnum>
QString QtEnumToQString(const QEnum value)
{
   return QString(QMetaEnum::fromType<QEnum>().valueToKey((int)value)); // or c++23 version .valueToKey(std::to_underlying(value))
}

class OAuthManager : public QObject {
	Q_OBJECT
   
public:
	explicit OAuthManager(QObject *parent = nullptr);
   void InitUserConfig();
   void startLogin(QString strProvider);
   void saveUserInfo(const QString &strToken, const QString &strDonationSlug,
                     const QString &strLiveSlug, const QString &strWallet);
   QJsonObject logout();
   void clearUserInfo();

signals:
   void loginSuccess(const QString &accessToken);
	void loginFailed(const QString &error);
   
protected:
   QJsonObject ObjectFromString(const QString& in);

private slots:
   void handleNewConnection();
	void fetchUserInfo();
   
private:
	QNetworkAccessManager networkManager;
	QTcpServer server;
	QString accessToken;
   ConfigFile userConfig;
   const QString SPECTRUMLIVE_URL = "https://wqpfdqfjmtohaernictc.supabase.co";
	const QString REDIRECT_URI = "https://beta.spectrumlive.xyz/proxy-handler";
   const QString SPECTRUMLIVE_LOGOUT = "https://beta.spectrumlive.xyz/api/auth/logout";
};

