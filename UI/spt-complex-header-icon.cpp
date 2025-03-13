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

#include "spt-complex-header-icon.hpp"
#include "ui_SPTComplexHeaderIcon.h"

#include <qsvgrenderer.h>

SPTComplexHeaderIcon::SPTComplexHeaderIcon(QWidget *parent) : QLabel(parent),
	ui(new Ui::SPTComplexHeaderIcon)
{
	ui->setupUi(this);
	ui->PlatformLabel->hide();
}

SPTComplexHeaderIcon::~SPTComplexHeaderIcon()
{
}

void SPTComplexHeaderIcon::setPixmap(const QString &pix)
{
	QPixmap pixmap(pix);

	this->QLabel::setPixmap(pixmap);
}

void SPTComplexHeaderIcon::setPixmap(const QString &pix, const QSize &size)
{
	QPixmap pixmap(size * 4);
	if (pix.contains(".svg")) {
		//svg handler
		QSvgRenderer svgRenderer(pix);
		pixmap.fill(Qt::transparent);
		QPainter painter(&pixmap);
		svgRenderer.render(&painter);
	}

	pixmap = pixmap.scaled(size * 4, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	this->QLabel::setPixmap(pixmap.scaled(size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
}

void SPTComplexHeaderIcon::setPixmap(const QPixmap &pix)
{
   this->QLabel::setPixmap(pix);
}

void SPTComplexHeaderIcon::setPlatformPixmap(const QString &pix, const QSize &size)
{
	QSvgRenderer svgRenderer(pix);
	QPixmap pixmap(size);
	pixmap.fill(Qt::transparent);
	QPainter painter(&pixmap);
	svgRenderer.render(&painter);
	setPlatformPixmap(pixmap);
}

void SPTComplexHeaderIcon::setPlatformPixmap(const QPixmap &pix)
{
	ui->PlatformLabel->setPixmap(pix);
	ui->PlatformLabel->show();
}

void SPTComplexHeaderIcon::changeEvent(QEvent *e)
{
	QLabel::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}
