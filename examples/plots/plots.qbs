 import qbs


 Project {
     CppApplication {
         Depends { name: "qnite" }
         Depends { name: "Qt.quick" }

         files: [
             "plots.qrc",
             "main.cpp",
         ]
     }
 }
