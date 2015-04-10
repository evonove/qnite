#ifndef QNITE_PLUGIN_H
#define QNITE_PLUGIN_H

#include <QQmlExtensionPlugin>

class QnitePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

  public:
    void registerTypes(const char *uri);
};

#endif // QNITE_PLUGIN_H

