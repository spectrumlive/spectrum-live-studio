#pragma once

#include <PLSDock.h>

class OBSDock : public PLSDock {
	Q_OBJECT

public:
	inline OBSDock(QWidget *parent = nullptr) : PLSDock(parent) {}
	inline OBSDock(const QString &title, QWidget *parent = nullptr)
		: PLSDock(parent)
	{
		setWindowTitle(title);
	}

	virtual void closeEvent(QCloseEvent *event);
	virtual void showEvent(QShowEvent *event);
};