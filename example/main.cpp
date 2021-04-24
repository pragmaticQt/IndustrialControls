#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "register_types.h"

int main(int argc, char* argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    registerTypes();

    const QUrl url(QStringLiteral("qrc:/qml/Main.qml"));
    engine.addImportPath(QStringLiteral("qrc:/"));

    engine.load(url);
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
