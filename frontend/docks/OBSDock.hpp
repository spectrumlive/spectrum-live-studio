#pragma once

#include <QDockWidget>
#include "components/SPTDockTitle.hpp"

class QCloseEvent;
class QShowEvent;
class QString;

class OBSDock : public QDockWidget {
	Q_OBJECT

public:
   OBSDock(QWidget *parent = nullptr);
	inline OBSDock(const QString &title, QWidget *parent = nullptr) : QDockWidget(title, parent), title(title) {      
   }
   
   void initTitle() {
      dockTitle = new SPTDockTitle(this);
   }

	virtual void closeEvent(QCloseEvent *event);
	virtual void showEvent(QShowEvent *event);
   
   void setWindowTitle(const QString &);

private slots:
   void onTopLevelChanged(bool floating);
   
private:
   SPTDockTitle *dockTitle{nullptr};
   QString title;
   
   friend class SPTDockTitle;
};
