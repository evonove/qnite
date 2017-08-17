#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "qnite.h"


int main(int argc, char *argv[])
{
  Q_INIT_RESOURCE(qnite);

  #ifdef Q_OS_WIN
    QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
  #endif

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.addImportPath(QStringLiteral("qrc:/qml"));
  engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

  return app.exec();
}
