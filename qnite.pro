TEMPLATE = subdirs
SUBDIRS = modules

!no-qnite-examples {
    SUBDIRS += examples
    examples.depends = modules
}

!no-qnite-tests {
    SUBDIRS += tests
    tests.depends = modules
}
