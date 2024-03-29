#ifndef WINDOWCLIENT_H
#define WINDOWCLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <setjmp.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WindowClient; }
QT_END_NAMESPACE

class WindowClient : public QMainWindow
{
    Q_OBJECT

public:
    WindowClient(QWidget *parent = nullptr);
    ~WindowClient();

    void setNom(const char* Text);
    const char* getNom();
    void setMotDePasse(const char* Text);
    const char* getMotDePasse();
    void setPublicite(const char* Text);
    void setTimeOut(int nb);
    void setAEnvoyer(const char* Text);
    const char* getAEnvoyer();
    void setNomRenseignements(const char* Text);
    const char* getNomRenseignements();
    void setGsm(const char* Text);
    void setEmail(const char* Text);

    void setPersonneConnectee(int i,const char* Text);
    const char* getPersonneConnectee(int i);
    void setCheckbox(int i,bool b);
    void ajouteMessage(const char* personne,const char* message);

    void loginOK();
    void logoutOK();

public slots:
    void on_pushButtonLogin_clicked();
    void on_pushButtonLogout_clicked();
    void on_pushButtonQuitter_clicked();
    void on_pushButtonEnvoyer_clicked();
    void on_pushButtonConsulter_clicked();
    void on_pushButtonModifier_clicked();
    void on_checkBox1_clicked(bool checked);
    void on_checkBox2_clicked(bool checked);
    void on_checkBox3_clicked(bool checked);
    void on_checkBox4_clicked(bool checked);
    void on_checkBox5_clicked(bool checked);

private:
    Ui::WindowClient *ui;

    char connectes[6][20];
    char motDePasse[20];
    char aEnvoyer[100];
    char nomR[20];
};
#endif // WINDOWCLIENT_H
