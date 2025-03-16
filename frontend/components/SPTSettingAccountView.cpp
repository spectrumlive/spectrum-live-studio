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

#include "SPTSettingAccountView.hpp"
#include "ui_SPTSettingAccountView.h"
#include "SPTFileDownloader.hpp"
#include "util/config-file.h"
#include <OBSApp.hpp>
#include <QDebug>


SPTSettingAccountView::SPTSettingAccountView(QWidget *parent) :
   QWidget(parent),
	ui(new Ui::SPTSettingAccountView),
   mProviderMetaObject(this->staticMetaObject),
   mProviderMetaEnum(mProviderMetaObject.enumerator(mProviderMetaObject.indexOfEnumerator("EnumProvider")))
{
	ui->setupUi(this);
	initUi();
}

SPTSettingAccountView::~SPTSettingAccountView()
{
   delete(ui);
}

QString SPTSettingAccountView::getProviderImage(const QString &provider) const
{
   switch (mProviderMetaEnum.keyToValue(provider.toUpper().toLatin1())) {
      case GOOGLE:
         return QString(":/providers/images/providers/img-google-profile.svg");
      case APPLE:
         return QString(":/providers/images/providers/img-apple-profile.svg");
      case FACEBOOK:
         return QString(":/providers/images/providers/img-facebook-profile.svg");
   }   
   return QString("");
}


void SPTSettingAccountView::initUi()
{
   ui->btnLogout->hide();
	QString filePath = ":/settings/images/settings/profile.svg";
   QString avatarUrl = config_get_string(App()->GetUserConfig(), "UserInfo", "avatar_url");
   QString providerImage = getProviderImage(config_get_string(App()->GetUserConfig(), "UserInfo", "provider"));
   ui->userIconLabel->setPlatformPixmap(providerImage, QSize(18,18));

   if (avatarUrl.length()>0) {
      m_pImgCtrl = new SPTFileDownloader(this);
      QObject::connect(m_pImgCtrl, &SPTFileDownloader::imageDownloaded, [this](const QPixmap &pixmap) {
         this->ui->userIconLabel->setPixmap(pixmap);
         this->ui->userIconLabel->show();
      });
      m_pImgCtrl->downloadImage(QUrl(avatarUrl));
   } else {
      ui->userIconLabel->setPixmap(filePath, QSize(110, 110));
   }
   
   ui->nickName->setText(config_get_string(App()->GetUserConfig(), "UserInfo", "full_name"));
   ui->email->setText(config_get_string(App()->GetUserConfig(), "UserInfo", "email"));
   ui->walletID->setText(config_get_string(App()->GetUserConfig(), "UserInfo", "wallet_address"));
   
   connect(&manager, &QNetworkAccessManager::finished, this, &SPTSettingAccountView::onManagerFinished);
}

void SPTSettingAccountView::onManagerFinished(QNetworkReply *reply)
{
   qDebug()<< reply->readAll();
}
