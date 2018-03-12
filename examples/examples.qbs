 import qbs


 Project {
     CppApplication {
         Depends { name: "qnite" }
         Depends { name: "Qt.quick" }

         files: [
             "example_library/example_library.qrc",
             "example_library/main.cpp",
         ]
     }
 }
