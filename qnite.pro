TEMPLATE = subdirs
SUBDIRS += \
    examples \
    tests

qnite-no-tests {
    SUBDIRS -= tests
}
