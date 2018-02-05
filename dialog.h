#ifndef DIALOG_H
#define DIALOG_H

#include <QSystemTrayIcon>
#include <QDialog>
#include <QAction>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QKeySequence>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog();

private:
    QAction* setKeySequence;
    QAction* quit;

    QKeySequence translateKeySequence;

    QSystemTrayIcon* trayIcon;
    QMenu* trayIconMenu;


    void createActions();
    void createTrayIcon();
};

class KeySequenceDialog : public QDialog {
    Q_OBJECT

public:
    KeySequenceDialog();
};

#endif // DIALOG_H
