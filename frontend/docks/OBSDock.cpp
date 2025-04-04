#include "OBSDock.hpp"

#include <widgets/OBSBasic.hpp>

#include <QCheckBox>
#include <QMessageBox>

#include "moc_OBSDock.cpp"

OBSDock::OBSDock(QWidget *parent) : QDockWidget(parent) {
   QObject::connect(this, &QDockWidget::topLevelChanged, this, &OBSDock::onTopLevelChanged);
}

void OBSDock::closeEvent(QCloseEvent *event)
{
	auto msgBox = []() {
		QMessageBox msgbox(App()->GetMainWindow());
		msgbox.setWindowTitle(QTStr("DockCloseWarning.Title"));
		msgbox.setText(QTStr("DockCloseWarning.Text"));
		msgbox.setIcon(QMessageBox::Icon::Information);
		msgbox.addButton(QMessageBox::Ok);

		QCheckBox *cb = new QCheckBox(QTStr("DoNotShowAgain"));
		msgbox.setCheckBox(cb);

		msgbox.exec();

		if (cb->isChecked()) {
			config_set_bool(App()->GetUserConfig(), "General", "WarnedAboutClosingDocks", true);
			config_save_safe(App()->GetUserConfig(), "tmp", nullptr);
		}
	};

	bool warned = config_get_bool(App()->GetUserConfig(), "General", "WarnedAboutClosingDocks");
	if (!OBSBasic::Get()->Closing() && !warned) {
		QMetaObject::invokeMethod(App(), "Exec", Qt::QueuedConnection, Q_ARG(VoidFunc, msgBox));
	}

	QDockWidget::closeEvent(event);

	if (widget() && event->isAccepted()) {
		QEvent widgetEvent(QEvent::Type(QEvent::User + QEvent::Close));
		qApp->sendEvent(widget(), &widgetEvent);
	}
   
}

void OBSDock::showEvent(QShowEvent *event)
{
	QDockWidget::showEvent(event);
}

void OBSDock::onTopLevelChanged(bool floating)
{
   if (floating) {
         // Manually set custom title bar in floating mode
      setTitleBarWidget(nullptr);  // Remove first to avoid layout issues
      setTitleBarWidget(dockTitle);
   } else {
      setTitleBarWidget(dockTitle);
   }
}

void OBSDock::setWindowTitle(const QString &title)
{
   QDockWidget::setWindowTitle(title);
   if (dockTitle)
      dockTitle->setTitle(title);
}

