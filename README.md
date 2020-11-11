# qnite

*qnite* is a charting library that provides a really high level API (via QML) to customize and render **interactive** charts in
your Qt applications.

## Building and Testing

There are currently two supported build systems, Qbs and CMake.

### Qbs

To use Qbs you must have configured it previously with `qbs setup-toolchains` and `qbs setup-qt`, see the official docs for more information.

Assuming you have setup a Qt profile named `qt-5-9-8` you can start a build with:

```
mkdir build
cd build
qbs build profile:qt-5-9-8 -f ..
```

This will also build tests and examples.

To only build the library you need to specify the product `qnite`:

```
qbs build -p qnite profile:qt-5-9-8 -f ..
```

To run tests or examples you need to specify the product:

```
qbs run -p plots
qbs run -p tst_qniteartist
```

To know the list of runnable products:

```
qbs list-products profile:qt-5-9-8 -f ..
```

### CMake

To use CMake:

```
mkdir build
cd build
cmake ..
cmake --build .
```

This will build only the library, examples are not built by default.

In case you want to build the examples you must specify the target:

```
cmake --build . --target examples
```

Tests are run with CTest and `BUILD_TESTING` must be set at config time, to run them:

```
cmake -DBUILD_TESTING=ON ..
cmake --build .
ctest --output-on-failure
```


## Roadmap

* provide a step-by-step tutorial
* provide the high-level API documentation for available charts type
* provide a simple tutorial to implement your own chart using low-level components

## License
qnite is released under the terms of the **MIT license**. Full details in ``LICENSE`` file.
