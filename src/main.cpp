

#include <QApplication>
#include "MyUuidWidget.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("");
    app.setApplicationName("qtUuidFactory");
    app.setApplicationVersion("1.0.0");

    MyUuidWidget w;
    w.show();

    return app.exec();
}

