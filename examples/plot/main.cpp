#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QQmlApplicationEngine engine;
  engine.addImportPath(QApplication::applicationDirPath() + QStringLiteral("/../../modules"));
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  return app.exec();
}
