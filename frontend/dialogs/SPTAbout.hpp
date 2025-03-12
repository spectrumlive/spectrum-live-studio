#pragma once

#include "ui_SPTAbout.h"
#include "OBSAbout.hpp"

#include <QDialog>
#include <QPointer>

class SPTAbout : public QDialog {
	Q_OBJECT

public:
	explicit SPTAbout(QWidget *parent = nullptr);
	
	std::unique_ptr<Ui::SPTAbout> ui;
	
private:
	QPointer<OBSAbout> about;

};

