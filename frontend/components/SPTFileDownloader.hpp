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

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>

class SPTFileDownloader : public QObject
{
	Q_OBJECT
   
public:
   explicit SPTFileDownloader(QObject *parent = nullptr);
   void downloadImage(const QUrl &url);
   
signals:
   void imageDownloaded(const QPixmap &pixmap);
   
private slots:
   void onImageDownloaded(QNetworkReply *reply);
   
private:
   QNetworkAccessManager m_networkManager;
};
