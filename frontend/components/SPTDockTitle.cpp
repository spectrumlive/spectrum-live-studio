
#include "SPTDockTitle.hpp"
#include "docks/OBSDock.hpp"

#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QDockWidget>

SPTDockTitle::SPTDockTitle(OBSDock *parent): dock(parent), title("") {
   titleHLayout = new QHBoxLayout(this);
   titleHLayout->setContentsMargins(4, 2, 4, 2);
   titleHLayout->setSpacing(2);
   titleHLayout->setStretch(0, 0);
   
   lbTitle = new QLabel("", this);
   titleHLayout->addWidget(lbTitle);
   
   closeButton = new QToolButton();
   closeButton->setObjectName("closeButton");
   closeButton->setIcon(QIcon(":/res/images/close.svg"));
   connect(closeButton, &QToolButton::clicked, [this]() {
      dock->setProperty("vis", false);
      dock->setVisible(false);
   });
   titleHLayout->addWidget(closeButton);
   
   setLayout(titleHLayout);
   dock->setTitleBarWidget(this);
}

void SPTDockTitle::setTitle(const QString &strTitle)
{
   title = strTitle;
   if (lbTitle) {
      lbTitle->setText(title);
   }
}
