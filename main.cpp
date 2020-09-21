#include<QApplication>
#include<login.h>
#include<signup.h>
#include<QDesktopWidget>
#include<QMainWindow>

int main(int argc, char** argv){

    QApplication app(argc, argv);

    // to make the window size 70% the size of the screen
    QDesktopWidget qd;
    //int x_login = qd.width()*0.4;
    //int y-login = qd.height()*0.7;
    int x_signIn = qd.width()*0.6;
    int y_signIn = qd.height()*0.85;

    signUp signup;
    signup.setFixedSize(x_signIn, y_signIn);
    signup.show();

   // login logmain ;
   // logmain.setFixedSize(x,y);
   // logmain.show();

    return app.exec();
}
