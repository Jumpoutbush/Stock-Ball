#include "news.h"
#include "ui_news.h"
#include <QDebug>
#include <QSqlQuery>
#include "dataresovle.h"
#include <QSqlTableModel>
#include <QTableWidget>
#include <QSqlRecord>
#include <QDesktopServices>
#include <QWebEngineView>
#include <QHBoxLayout>

news::news(const QString &Codec,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::news)
{
    ui->setupUi(this);


    codec = Codec;

    model = new QSqlTableModel(this);
    model->setTable("newsData");
    ui->tableView_stocknews->setModel(model);
    //initializeModel(model,&g_db,sql);
    model->setFilter(QObject::tr("codec='%1'").arg(codec));
    model->select();
    model->removeColumns(0,3);
    model->removeColumn(1);

    QStringList tables;
    tables << "标题";
    model->setHeaderData(0, Qt::Horizontal,tables[0]);
    model->setSort(0, Qt::AscendingOrder);

    ui->tableView_stocknews->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_stocknews->setColumnWidth(0,500);
}

news::~news()
{
    delete ui;
}

void news::on_tableView_stocknews_doubleClicked(const QModelIndex &index)
{
    QLayout* layout = ui->widget_browser->findChild<QLayout*>();
    delete layout;
    QSqlRecord record = model->record(index.row());
    QString newstitle = record.value("title").toString();
    QSqlQuery query;
    QString sql = QString("select html from newsData where codec = '%1' and title = '%2' ").arg(codec).arg(newstitle);
    query.exec(sql);
    while(query.next())
    {
        QString news_html = query.value(0).toString();
        QVBoxLayout *mainLayout = new QVBoxLayout();

        QWebEngineView *view = new QWebEngineView(this);
        view->load(news_html);

        mainLayout->addWidget(view);
        ui->widget_browser->setLayout(mainLayout);


    }
}
