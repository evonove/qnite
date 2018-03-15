 import qbs


 Project {
     CppApplication {
         Depends { name: "qnite" }
         Depends { name: "Qt.quick" }

         files: [
             "examples.qrc",
             "main.cpp",
         ]
     }
 }
