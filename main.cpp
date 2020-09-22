#include<QApplication>
#include<login.h>
#include<signup.h>
#include<QMainWindow>

int main(int argc, char** argv){

    QApplication app(argc, argv);

    login logmain ;
    logmain.show();

    return app.exec();
}
