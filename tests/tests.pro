TEMPLATE = subdirs
SUBDIRS +=\
  setup \
  qml \
  plugin

setup.depends += plugin
