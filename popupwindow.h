﻿#ifndef POPUPWINDOW_H
#define POPUPWINDOW_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QTimer>
#include <QFrame>
#include <QLabel>
#include <QTextEdit>

class PopUpWindow : public QFrame
{
    Q_OBJECT

    // property is used for QPropertyAnimation
    Q_PROPERTY(float opacity READ getOpacity WRITE setOpacity)

    void  setOpacity(float opacity);
    float getOpacity() const;

public:
    explicit PopUpWindow(int duration, QWidget *parent = nullptr);
    virtual ~PopUpWindow();

    void setSourceText(const QString& text, const QString& language);
    void setResultText(const QString& text, const QString& language);
    inline void setDuration(int duration) { m_duration = duration;}

public slots:
    void show();

protected:
    bool event(QEvent* e) override;

private slots:
    void hideAnimation();

private:   
    QTextEdit* sourceTextWidget;
    QTextEdit* resultTextWidget;

    QLabel* languagesLabel;
    QString sourceLang, resultLang;

    QImage* image;

    float opacity;
    QPropertyAnimation animation;
    QTimer* timer;

    int m_duration;
};

#endif // POPUPWINDOW_H
