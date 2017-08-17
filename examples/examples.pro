TEMPLATE = subdirs
SUBDIRS += \
    qnitelib \
    example_include \
    example_library

example_library.depends = qnitelib

