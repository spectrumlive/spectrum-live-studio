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

#include "SPTFileDownloader.hpp"
#include <QBuffer>
#include "curl/curl.h"

class AvatarWrite
{
public:
   static size_t writeData(void* ptr, size_t size, size_t nmemb, void* buffer)
   {
   Q_UNUSED(size);
   ((std::string*) buffer)->append((char*) ptr, nmemb);
   return nmemb;
   }
};

SPTFileDownloader::SPTFileDownloader(QObject *parent) : QObject(parent)
{
   connect(&m_networkManager, &QNetworkAccessManager::finished, this, &SPTFileDownloader::onImageDownloaded);
}

void SPTFileDownloader::downloadImage(const QUrl &url)
{
   CURL *curl;
   CURLcode res;
   curl = curl_easy_init();
   if (curl) {
      std::string out;
      curl_easy_setopt(curl, CURLOPT_URL, url.url().toStdString().c_str());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, AvatarWrite::writeData);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
      res = curl_easy_perform(curl);
      /* always cleanup */
      curl_easy_cleanup(curl);
      QByteArray byteArray(out.c_str(), out.length());
      QPixmap pixmap(110, 110);
      qDebug() << pixmap.loadFromData(byteArray, "JPEG");
      emit imageDownloaded(pixmap);
   }
}

void SPTFileDownloader::onImageDownloaded(QNetworkReply *reply)
{
   qDebug() << reply->error();
   qDebug() << reply->readAll();
   if (reply->error() == QNetworkReply::NoError) {
      QByteArray imageData = reply->readAll();
      QPixmap pixmap;
      pixmap.loadFromData(imageData);
      emit imageDownloaded(pixmap);
   }
   reply->deleteLater();
}

