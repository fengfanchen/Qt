#include "loginweb.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoginWeb w;
	w.show();
	return a.exec();
}
