#include<QApplication>
#include<login.h>
#include<QDesktopWidget>
#include<QMainWindow>

int main(int argc, char** argv){

    QApplication app(argc, argv);

    // to make the window size 70% the size of the screen
    QDesktopWidget qd;
    int x = qd.width()*0.4;
    int y = qd.height()*0.7;


    login logmain ;
    logmain.setFixedSize(x,y);
    logmain.show();

    return app.exec();
}
