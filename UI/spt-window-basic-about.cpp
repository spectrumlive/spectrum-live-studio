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

#include "spt-window-basic-about.hpp"

SPTAbout::SPTAbout(QWidget *parent) : QDialog(parent), ui(new Ui::SPTAbout), about(nullptr)
{
	setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
	ui->setupUi(this);
	this->setWindowTitle("About SPECTRUM Live Studio");
	auto showOBSAbout = [this]() {
		if (this->about)
			this->about->close();
		this->about = new OBSAbout(this);
		this->about->show();
		this->about->setAttribute(Qt::WA_DeleteOnClose, true);
	};
	connect(ui->btnAboutOBS, &QPushButton::clicked, this, showOBSAbout);
}

SPTAbout::~SPTAbout()
{
   delete about;
}
