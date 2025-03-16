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

#include <QWidget>
#include <QMetaEnum>
#include "SPTFileDownloader.hpp"

namespace Ui {
class SPTSettingAccountView;
}

class SPTSettingAccountView: public QWidget {
	Q_OBJECT
public:
   enum EnumProvider {
      GOOGLE,
      APPLE,
      FACEBOOK
   };
   Q_ENUM(EnumProvider)

   explicit SPTSettingAccountView(QWidget *parent = nullptr);
	~SPTSettingAccountView() override;
	void initUi();
	void setEnable(bool enable);
	
protected:
   QString getProviderImage(const QString &provider) const;
   
private slots:
   void onManagerFinished(QNetworkReply *reply);

private:
	Ui::SPTSettingAccountView *ui;
   SPTFileDownloader *m_pImgCtrl;
   QMetaObject mProviderMetaObject;
   QMetaEnum mProviderMetaEnum;
   QNetworkAccessManager manager;
};
