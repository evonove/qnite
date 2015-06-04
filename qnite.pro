TEMPLATE = subdirs
SUBDIRS = modules

!no-examples {
    SUBDIRS += examples
    examples.depends = modules
}

!no-tests {
    SUBDIRS += tests
    tests.depends = modules
}
