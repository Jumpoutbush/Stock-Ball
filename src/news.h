#ifndef NEWS_H
#define NEWS_H

#include <QDialog>
#include "dataresovle.h"
#include <QSqlTableModel>
#include <QWebEngineView>

namespace Ui {
class news;
}

class news : public QDialog
{
    Q_OBJECT

public:
    explicit news(const QString &Codec="0000001",QWidget *parent = nullptr);
    ~news();
    void setCodec(QString str);
private slots:
    void on_tableView_stocknews_doubleClicked(const QModelIndex &index);

private:
    Ui::news *ui;
    QString codec;
    QSqlTableModel *model;

};

#endif // NEWS_H
