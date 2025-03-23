#pragma once

#include <QWidget>
#include <QString>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolButton>

class OBSDock;

class SPTDockTitle: public QWidget {
   Q_OBJECT

public:
   explicit SPTDockTitle(OBSDock *parent = nullptr);
   
public:
   void setTitle(const QString &title);

private:
   QWidget *titleBar;  // Store the title bar to prevent memory leaks
   QString title;
   OBSDock *dock;
   QLabel *lbTitle{nullptr};
   QToolButton *closeButton{nullptr};
   QHBoxLayout *titleHLayout{nullptr};
};
