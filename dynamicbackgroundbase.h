#ifndef DYNAMICBACKGROUNDBASE_H
#define DYNAMICBACKGROUNDBASE_H

#include <QObject>
#include <QWidget>
#include <QColor>
#include <QTimer>

class DynamicBackgroundBase : public QWidget
{
    Q_OBJECT
public:
    explicit DynamicBackgroundBase(QWidget *parent = nullptr);

signals:

public slots:

protected:
    QTimer* timer;

};

#endif // DYNAMICBACKGROUNDBASE_H
