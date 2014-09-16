#ifndef VIBESWINDOW_H
#define VIBESWINDOW_H

#include <QMainWindow>

#include <QHash>
#include <QFile>
#include <QPen>
#include <QBrush>
#include <QJsonDocument.h>
#include <QJsonObject.h>
#include <QJsonArray.h>
#include <QJsonValue.h>
#include <QJsonParseError.h>
#include "figure2d.h"

#include "vibesscene2d.h"
#include "vibesgraphicsitem.h"

#include <QFileDialog>

#include <QTimer>
#include <QtCore>

#include "vibestreemodel.h"

class Figure2D;

namespace Ui {
class VibesWindow;
}

class VibesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VibesWindow(bool showFileOpenDlg=false, QWidget *parent = 0);
    ~VibesWindow();

    Figure2D * newFigure(QString name=QString());

public slots:
    void readFile();
    bool processMessage(const QByteArray &msg);
    void exportCurrentFigureGraphics();

private slots:
    void removeFigureFromList(QObject *fig);
    void showSelectedFigure(const QModelIndex &mi);

private:
    Ui::VibesWindow *ui;

    QHash<QString, Figure2D*> figures;

    QFile file;
    QByteArray message;
};

#endif // VIBESWINDOW_H
