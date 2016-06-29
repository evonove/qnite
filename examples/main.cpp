#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.addImportPath(QStringLiteral("qrc:/qml"));
  engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

  return app.exec();
}
