#pragma once

#include <QFrame>
#include <QLabel>
#include <QBitmap>
#include <QPainter>

/* this is a complex UI for user profile header */

namespace Ui {
class SPTComplexHeaderIcon;
}

class SPTComplexHeaderIcon : public QLabel {
	Q_OBJECT

public:
	explicit SPTComplexHeaderIcon(QWidget *parent = nullptr);
	~SPTComplexHeaderIcon() override;

	void setPixmap(const QString &pix);
   void setPixmap(const QString &pix, const QSize &size);
   void setPixmap(const QPixmap &pix);
   void setPlatformPixmap(const QString &pix, const QSize &size);
   void setPlatformPixmap(const QPixmap &pix);

protected:
	void changeEvent(QEvent *e) override;

private:
	Ui::SPTComplexHeaderIcon *ui;
};
