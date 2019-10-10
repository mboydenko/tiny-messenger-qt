#include "chatlist.h"
#include <QApplication>

#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	ChatList w;
	w.resize(400, 300);
	w.show();

	w.appendDialog("Макс Бойденко", "Здарова андрюха это очень длинный текст");
	w.appendDialog("Димитрий", "Вы: Привет :)");
	w.appendDialog("Миссис Попенс", "Вы: добрый вечер я диспетчер");
	w.appendDialog("Олежа", "Бабки гони");
	w.appendDialog("Лешкус (Алексей Бабкин)", "андрюша, ты в иркутске???");

	// Изменяем текст и поднимаем
	w.changeTitle("Олежа", "Олег Волков любов моя");
	w.changeText("Олежа", "Лан не надо бабок"); // error: не изменит т.к. был сменяно имя пользователя
	w.changeText("Олег Волков любов моя", "Лан не надо бабок"); // work
	w.upDialog("Олежа"); // error: не поднимет т.к. был сменяно имя пользователя
	w.upDialog("Олег Волков любов моя");

	// Поднимаем изменяя текст
	w.upDialog("Димитрий", "Привет Андрей");

	w.deleteDialog("Олег Волков любов моя");

	w.hideDialog("Димитрий");				// work
	w.showDialog("Димитрий");				// work

	w.hideDialog("Димитрий");				// work
	w.hideDialog("Миссис Попенс");			// work
	w.upDialog("Миссис Попенс", "Test");	// work
	w.showDialogs();						// work

	w.setBackgroundColor(QColor(23, 33, 43));
	w.setBackgroundHoverColor(QColor(32, 43, 54));
	w.setBackgroundReleaseColor(QColor(43, 82, 120));
	w.setTitleColor(QColor(250, 250, 250));
	w.setTextColor(QColor(200, 180, 200));

	w.setTitleFont(QFont("Times New Roman", 14, QFont::Bold));
	w.setTextFont(QFont("Arial", 12, QFont::Normal));

	QList<Chat::Dialog> list = w.dialogs();
	foreach (const Chat::Dialog &d, list)
	{
		qDebug() << d.title << " " << d.text;
	}

	return a.exec();
}
