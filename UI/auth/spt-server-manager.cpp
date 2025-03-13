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

#include "SPTServiceManager.hpp"


SPTServiceManager::SPTServiceManager(QObject *parent) : QObject(parent) {
   manager = new QNetworkAccessManager(this);
   connect(manager, &QNetworkAccessManager::finished, this, &SPTServiceManager::onReplyFinished);
}

void SPTServiceManager::sendGetRequest(const QString &url, const QString &token, Callback callback) {
   
   qDebug() << "SSL Support Available:" << QSslSocket::supportsSsl();
   qDebug() << "OpenSSL Build Version:" << QSslSocket::sslLibraryBuildVersionString();
   qDebug() << "OpenSSL Runtime Version:" << QSslSocket::sslLibraryVersionString();

   
   QNetworkRequest request((QUrl(url)));
   auto config = QSslConfiguration::defaultConfiguration();
   config.setCaCertificates(QSslCertificate::fromPath(QStringLiteral(":/sslcert/rootCA.pem")));
   config.setProtocol(QSsl::TlsV1_2);
   QSslConfiguration::setDefaultConfiguration(config);
   request.setSslConfiguration(config);
   request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
   request.setSslConfiguration(QSslConfiguration::defaultConfiguration());

   if (!token.isEmpty()) {
      request.setRawHeader("Authorization", QString("Bearer %1").arg(token).toUtf8());
   }
   
   QNetworkReply *reply = manager->get(request);
   callbacks[reply] = callback;
}

void SPTServiceManager::onReplyFinished(QNetworkReply *reply) {
   if (!callbacks.contains(reply)) {
      reply->deleteLater();
      return;
   }
   
   Callback callback = callbacks.take(reply);  // Retrieve and remove callback
   bool success = reply->error() == QNetworkReply::NoError;
   QString errorMsg = success ? "" : reply->errorString();
   QJsonObject jsonObj;
   
   if (success) {
      QByteArray responseData = reply->readAll();
      QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
      
      if (jsonDoc.isObject()) {
         jsonObj = jsonDoc.object();
      } else {
         success = false;
         errorMsg = "Invalid JSON format";
      }
   }
   
   if (callback) {
      callback(jsonObj, success, errorMsg);
   }
   
   reply->deleteLater();
}


